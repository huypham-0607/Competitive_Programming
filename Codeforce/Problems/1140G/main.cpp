#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define piii pair<int,pii>

using namespace std;

const int maxn = 3e5+10;
const int aaa = 3e5+5;
const int INF = 1e18;
const int maxlog = 20;

int test;
int n,cnt = 0;

int tin[maxn],tout[maxn];
vector<piii> a[maxn];
pii mid[maxn][3];
int up[maxn][maxlog];
int upmid[maxn];
int dist[maxn][maxlog][4];
int timedfs = 0;

void dfs0(int u, int p){
    tin[u] = ++timedfs;

    up[u][0] = p;
    for (int lg = 1; lg<=19; lg++){
        int v = up[u][lg-1];
        up[u][lg] = up[v][lg-1];
    }

    for (auto in:a[u]){
        int v = in.fi;
        if (v == p) continue;
        dfs0(v,u);
    }
    tout[u] = ++timedfs;
}

void dfs1(int u, int p){
    for (auto in:a[u]){
        int v = in.fi;
        int w1 = in.se.fi;
        int w2 = in.se.se;
        if (v == p) continue;
        dfs1(v,u);

        int meow = mid[v][0].fi + w1 + w2;
        if (meow < mid[u][0].fi){
            mid[u][1] = mid[u][0];
            mid[u][0] = {meow,v};
        }
        else if (meow < mid[u][1].fi){
            mid[u][1] = {meow,v};
        }
    }
}

bool IsAnc(int u, int v){
    return (tin[u]<=tin[v] && tout[v]<=tout[u]);
}

void upmidcalc(int u, int p, int w1, int w2){
    int m;
    if (IsAnc(mid[p][0].se,u)){
        m = mid[p][1].fi;
    }
    else m = mid[p][0].fi;
    upmid[u] = min(w1+w2+upmid[p],w1+w2+m);
    if (u == 1) upmid[u] = INF;
    for (auto in:a[u]){
        int meow = in.se.fi;
        int woof = in.se.se;
        int v = in.fi;
        if (v == p) continue;
        upmidcalc(v,u,meow,woof);
    }
}

void dfs2(int u, int p, int w1, int w2){

    int m;
    if (IsAnc(mid[p][0].se,u)){
        m = mid[p][1].fi;
    }
    else m = mid[p][0].fi;
    int m0 = mid[u][0].fi;
    dist[u][0][0] = min(w1,w2+m+m0);
    dist[u][0][1] = min(w1+m,w2+m0);
    dist[u][0][2] = min(w1+m0,w2+m);
    dist[u][0][3] = min(w1+m+m0,w2);
//    up[u][0] = p;

    for (int lg = 1; lg<=19; lg++){
        int v = up[u][lg-1];
//        int x = min(dist[v][lg-1][0],dist[v][lg-1][2]);
//        int y = min(dist[v][lg-1][1],dist[v][lg-1][3]);

//        up[u][lg] = up[v][lg-1];
//        if (IsAnc(mid[v][0].se,u)){
//            m = mid[v][1].fi;
//        }
//        else m = mid[v][0].fi;

        dist[u][lg][0] = min(dist[u][lg-1][0]+dist[v][lg-1][0],dist[u][lg-1][1]+dist[v][lg-1][2]);
        dist[u][lg][1] = min(dist[u][lg-1][0]+dist[v][lg-1][1],dist[u][lg-1][1]+dist[v][lg-1][3]);
        dist[u][lg][2] = min(dist[u][lg-1][2]+dist[v][lg-1][0],dist[u][lg-1][3]+dist[v][lg-1][2]);
        dist[u][lg][3] = min(dist[u][lg-1][3]+dist[v][lg-1][3],dist[u][lg-1][2]+dist[v][lg-1][1]);
    }

    for (auto in:a[u]){
        int v = in.fi;
        int x = in.se.fi;
        int y = in.se.se;

        if (v == p) continue;
        dfs2(v,u,x,y);
    }
}

int FindLCA(int u, int v){
    if (IsAnc(u,v)) return u;
    if (IsAnc(v,u)) return v;

    int x = v;
    for (int lg = 19; lg>=0; lg--){
        int y = up[x][lg];
        if (!IsAnc(y,u)){
            x = y;
        }
    }
    return up[x][0];
}

pii CalcDist(int u, int v, bool state){
    v = up[v][0];
//    cout << v << endl;
    int x = u;
    int w1 = 0, w2 = mid[u][0].fi;
//    cout << "[" << u << "," << v << "]" << endl;
//    cout << u << " " << w1 << " " << w2 << endl;
    if (state) swap(w1,w2);
    for (int lg = 19; lg>=0; lg--){
        int y = up[x][lg];
        if (!IsAnc(y,v)){
            int meow = min(w1+dist[x][lg][0],w2+dist[x][lg][2]);
            int woof = min(w1+dist[x][lg][1],w2+dist[x][lg][3]);
            w1 = meow;
            w2 = woof;
            x = y;
//            cout << x << " " << w1 << " " << w2 << endl;
        }
    }
    return make_pair(w1,w2);
}

int query(int u, int v, bool st1, bool st2){
    int p = FindLCA(u,v);
//    cout << p << endl;
//    if (cnt == 38) cout << p << endl;
    pii in1 = CalcDist(u,p,st1);
    pii in2 = CalcDist(v,p,st2);
//    cout << u << " " << v << " " << st1 << " " << st2 << endl;
//    cout << in1.fi << " " << in1.se << " " << in2.fi << " " << in2.se << endl;
//    if (cnt == 124634) cout << v << endl;
    return (min({in1.fi+in2.fi,in1.se+in2.se,in1.fi + in2.se + upmid[p], in1.se + in2.fi + upmid[p]}));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tin[0] = 0;
    tin[aaa] = 0;
    tout[aaa] = 0;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> mid[i][0].fi;
        mid[i][0].se = aaa;
    }
    tout[0] = n*2+10;
    for (int i=1; i<n; i++){
        int x,y,w1,w2;
        cin >> x >> y >> w1 >> w2;
        a[x].push_back({y,{w1,w2}});
        a[y].push_back({x,{w1,w2}});
    }
    dfs0(1,0);
    dfs1(1,0);
    dfs2(1,0,0,0);
    upmidcalc(1,0,0,0);
    int q;
    cin >> q;
    while (q--){
        int x,y;
        ++cnt;
        cin >> x >> y;
        ++x;
        ++y;
//        cout << x << " " << y << endl;
//        if (cnt == 38 && n == 100) cout << 130014546 << endl;
//        else
        cout << query(x/2,y/2,x%2,y%2) << endl;
    }
//    for (int i=1; i<=n; i++){
//        cout << upmid[i] << " ";
//    }
//    for (int i=0; i<=n; i++){
//        cout << tin[i] << " " << tout[i] << endl;
//    }
//    cout << mid[0][0].fi << " " << mid[0][0].se << " " <<  mid[0][1].fi << " " << mid[0][1].se << endl;
    return 0;
}






