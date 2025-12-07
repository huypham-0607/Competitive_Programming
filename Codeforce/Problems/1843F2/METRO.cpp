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
vector<piii> query;
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    cin >> test;
    while (test--){
        for (int i=1; i<=n; i++){
            a[i].clear();
        }
        tin[0] = 0;
        tout[0] = INF;
        query.clear();
        timedfs = 0;
        n = 1;
        val[1] = 1;
        int q;
        cin >> q;
        while (q--){
            char c;
            cin >> c;
            if (c == '+'){
                ++n;
                int x,v;
                cin >> x >> v;
                a[x].push_back(n);
                val[n] = v;
            }
            else{
                int u,v,x;
                cin >> u >> v >> x;
                query.push_back({{u,v},x});
            }
        }
        dfs(1,0);
        for (auto in:query){
            int u = in.fi.fi;
            int v = in.fi.se;
            int x = in.se;
            int p = FindLCA(u,v);
            piiii info1 = BinaryJump(u,p);
            piiii info2 = BinaryJump(v,p);

            int l = min({info1.fi.fi,info2.fi.fi,info1.se.fi + info2.se.fi + val[p]});
            ++cnt;
            if (l<=x && x<=r) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}
