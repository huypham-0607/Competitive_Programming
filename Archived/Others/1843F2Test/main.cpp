#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define piiii pair<pii,pii>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;
const int maxlog = 19;

int test;
int n;
int timedfs = 0;
vector<int> a[maxn];
int val[maxn];
vector<pii> query;
vector<pii> build;
priority_queue<piiii,vector<piiii>,greater<piiii>> bruh;
int tin[maxn],tout[maxn];
int up[maxn][maxlog];
int pre[maxn][maxlog][2],suf[maxn][maxlog][2],sum[maxn][maxlog];
int ans[maxn][maxlog][2];

void dfs(int u, int p){
    tin[u] = ++timedfs;
    up[u][0] = p;
    sum[u][0] = val[u];
    pre[u][0][0] = min(val[u],0);
    pre[u][0][1] = max(val[u],0);
    suf[u][0][0] = min(val[u],0);
    suf[u][0][1] = max(val[u],0);
    ans[u][0][0] = min(val[u],0);
    ans[u][0][1] = max(val[u],0);
    for (int lg=1; lg<maxlog; lg++){
        int v = up[u][lg-1];
        up[u][lg] = up[v][lg-1];
        sum[u][lg] = sum[u][lg-1]+sum[v][lg-1];
        pre[u][lg][0] = min(pre[u][lg-1][0],sum[u][lg-1]+pre[v][lg-1][0]);
        pre[u][lg][1] = max(pre[u][lg-1][1],sum[u][lg-1]+pre[v][lg-1][1]);
        suf[u][lg][0] = min(suf[u][lg-1][0]+sum[v][lg-1],suf[v][lg-1][0]);
        suf[u][lg][1] = max(suf[u][lg-1][1]+sum[v][lg-1],suf[v][lg-1][1]);
        ans[u][lg][0] = min({ans[u][lg-1][0],ans[v][lg-1][0],suf[u][lg-1][0] + pre[v][lg-1][0]});
        ans[u][lg][1] = max({ans[u][lg-1][1],ans[v][lg-1][1],suf[u][lg-1][1] + pre[v][lg-1][1]});
    }

    for (auto v:a[u]){
        dfs(v,u);
    }
    tout[u] = ++timedfs;
}

bool IsAnc(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int FindLCA(int u, int v){
    if (IsAnc(u,v)) return u;
    if (IsAnc(v,u)) return v;

    int x = v;
    for (int lg = maxlog-1; lg>=0; lg--){
        int y = up[x][lg];
        if (!IsAnc(y,u)){
            x = y;
        }
    }
    return up[x][0];
}

piiii BinaryJump(int u, int p){
    p = up[p][0];
    int x = 0,y = 0, t = 0,resx = 0, resy = 0;
    for (int lg = maxlog-1; lg>=0; lg--){
        int v = up[u][lg];
        if (!IsAnc(v,p)){
            t+=sum[u][lg];
            resx = min({resx,ans[u][lg][0],x + pre[u][lg][0]});
            resy = max({resy,ans[u][lg][1],y + pre[u][lg][1]});
            x = min(suf[u][lg][0], sum[u][lg] + x);
            y = max(suf[u][lg][1], sum[u][lg] + y);
            u = v;
        }
    }
    return {{resx,resy},{x,y}};
}

//Solution related ------------------------------------------------------------

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
mt19937 mt2(chrono::steady_clock::now().time_since_epoch().count());

int rd(int l, int r){
    return l+mt()%(r-l+1);
}

int sgen(){
    return mt2();
}

const int qconst = 2e5;
const int sizeconst = 200000;

void gentest(){
//    cout << maxn << endl;

    int n,q;
    n = rd(sizeconst/2-sizeconst/8,sizeconst/2 + (sizeconst/8));
    q = sizeconst - n;
//    cout << n << " " << q << endl;
//    cout << n << " " << q << endl;
    int cnt = 1;

    for (int i=2; i<=n+1; i++){
        int c = rd(0,1);
        if (!c) c = -1;
//        cout << "+ " << rd(1,cnt) << " " << c << endl;
//        build.push_back({cnt,c});
        build.push_back({rd(1,cnt),c});
//        cout << "+ " << 1 << " " << c << endl;
        ++cnt;
//        while (q && (rd(0,1)) && q>=(n-cnt)){
//            int u = rd(1,cnt);
//            int v = rd(1,cnt);
//            int val;
//            if (cnt < 100) val = rd(-cnt/3,cnt/3);
//            else if (cnt < 1000) val = rd(-cnt/12,cnt/12);
//            else if (cnt < 10000) val = rd(-cnt/26,cnt/26);
//            else if (cnt < 200000) val = rd(-cnt/44,cnt/44);
//            cout << "? " << u << " " << v << " " << val << endl;
//            --q;
//        }
    }
    for (int i=1; i<=q; i++){
        int u = rd(1,cnt);
        int v = rd(1,cnt);
//        int v = u;
//        cout << u << " " << v << " og" << endl;
        query.push_back({u,v});
//        cout << "? " << u << " " << v << endl;
    }
}

signed main(){
    freopen("METRO.INP","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//Solution ------------------------------------------------------------

    test = qconst/sizeconst;
    cout << test << endl;
    while (test--){
        int cnt = 1;
        for (int i=1; i<=n; i++){
            a[i].clear();
        }
        tin[0] = 0;
        tout[0] = INF;
        build.clear();
        query.clear();
        gentest();
        timedfs = 0;
        n = 1;
        val[1] = 1;
//        int q;
//        cin >> q;
//        while (q--){
//            char c;
//            cin >> c;
//            if (c == '+'){
//                ++n;
//                int x,v;
//                cin >> x >> v;
//                a[x].push_back(n);
//                val[n] = v;
//            }
//            else{
//                int u,v,x;
//                cin >> u >> v >> x;
//                query.push_back({{u,v},x});
//            }
//        }
        for (auto in:build){
            ++n;
            int x = in.fi;
            int v = in.se;
            a[x].push_back(n);
            val[n] = v;
//            cout << x << " " << v << endl;
        }
        dfs(1,0);
        for (auto in:query){
            int u = in.fi;
            int v = in.se;
//            cout << u << " " << v << " meow" << endl;
//            int x = in.se;
            int p = FindLCA(u,v);
            piiii info1 = BinaryJump(u,p);
            piiii info2 = BinaryJump(v,p);

            int l = min({info1.fi.fi,info2.fi.fi,info1.se.fi + info2.se.fi + val[p]});
            int r = max({info1.fi.se,info2.fi.se,info1.se.se + info2.se.se + val[p]});
//            cout << l << " " << r << " " << x << " " << p << " " << p << endl;
//            cout << info1.fi.fi << " " << info1.fi.se << " " << info1.se.fi << " " << info1.se.se << endl;
//            cout << info2.fi.fi << " " << info2.fi.se << " " << info2.se.fi << " " << info2.se.se << endl;
//            if (cnt == 95){
//                cout << "NO" << endl;
//            }
//            else{

            int c = rd(0,1000);
//            int c = rd(0,1);
            if (c){
                int val = rd(l,r);
                bruh.push({{max(u,v),u},{v,val}});
            }
            else{
                int c2 = rd(0,1);
                if (c2){
                    bruh.push({{max(u,v),u},{v,rd(r+1,n+1)}});
                }
                else{
                    bruh.push({{max(u,v),u},{v,rd(-n-1,l-1)}});
                }
            }
//            if (l<=x && x<=r) cout << "YES" << endl;
//            else cout << "NO" << endl;
//            }
        }
        cout << sizeconst << endl;
        while (!bruh.empty() && bruh.top().fi.fi <= cnt){
            cout << "? " << bruh.top().fi.se << " " << bruh.top().se.fi << " " << bruh.top().se.se << endl;
            bruh.pop();
        }
        for (auto in:build){
            ++cnt;
            int u = in.fi;
            int x = in.se;
            cout << "+ " << u << " " << x << endl;
            while (!bruh.empty() && bruh.top().fi.fi <= cnt){
                cout << "? " << bruh.top().fi.se << " " << bruh.top().se.fi << " " << bruh.top().se.se << endl;
                bruh.pop();
            }
        }
    }

//Solution ------------------------------------------------------------



    return 0;
}
