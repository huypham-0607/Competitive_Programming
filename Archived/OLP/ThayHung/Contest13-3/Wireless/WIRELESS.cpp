#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 5e5+20;
const int INF = 2e17;
const int maxlog = 19;
const int maxlog1 = 20;

int test;
int n,k,q;
int mark[maxn];
//vector<int> pre[maxn];
vector<pii> a[maxn];
int f[maxn],g[maxn];
int cnt[maxn];

//DP

void fcalc(int u, int p, int val){
    f[u] = 0;
    cnt[u] = 0;
    for (auto in:a[u]){
        int v = in.fi;
        int w = in.se;
        if (v==p) continue;
        fcalc(v,u,w);
        cnt[u]+=cnt[v];
        f[u]+=f[v]+w*cnt[v];
    }
    if (mark[u] == test) ++cnt[u];
}

void gcalc(int u, int p){
    for (auto in:a[u]){
        int v = in.fi;
        int w = in.se;
        if (v == p) continue;
        g[v] = f[u]-f[v]-(cnt[v]*w)+(k-cnt[v])*w+g[u];
        gcalc(v,u);
    }
}

int solve(){
    fcalc(1,0,0);
    gcalc(1,0);
    int res = INF;
    for (int i=1; i<=n; i++){
        res = min(res,f[i]+g[i]);
    }
//    for (int i=1; i<=n; i++){
//        cout << f[i] << " " << g[i] << endl;
//    }
    return res;
}

//LCA

int up[maxlog1][maxn],dist[maxlog1][maxn];
int h[maxn];

void DFS(int u, int p, int height, int d){
    h[u] = height;

    up[0][u] = p;
    dist[0][u] = d;
    for (int i=1; i<=maxlog; i++){
        int v = up[i-1][u];
        up[i][u] = up[i-1][v];
        dist[i][u] = dist[i-1][u] + dist[i-1][v];
    }

    for (auto in:a[u]){
        int v = in.fi;
        int w = in.se;
        if (v == p) continue;
        DFS(v,u,height+1,w);
    }
}

pii LCA(int u, int v){
    int d = 0;
    if (h[u] > h[v]) swap(v,u);
    int meow = h[v] - h[u];
    int c = 0;
    while (meow!=0){
        if ((meow & 1)){
            d+=dist[c][v];
            v = up[c][v];
        }
        ++c;
        meow = meow/2;
    }
    if (u == v) return make_pair(v,d);
    for(int i=maxlog; i>=0; i--){

        if (up[i][u] != up[i][v]){
            d+=dist[i][u];
            u = up[i][u];
            d+=dist[i][v];
            v = up[i][v];
        }
//        cout << i << " " << x << " " << y << endl;
    }
    d+=dist[0][u] + dist[0][v];
    return make_pair(up[0][u],d);
}

int Lift(int u, int v){
    if (h[u] > h[v]) swap(u,v);
    int meow = h[v] - h[u];
    int res = 0;
    int c = 0;
    while (meow!=0){
        if ((meow & 1)){
            res+=dist[c][v];
            v = up[c][v];
        }
        ++c;
        meow = meow/2;
    }
    return res;
}

int GetDist(int u, int v){
    pii meow = LCA(u,v);
    return Lift(meow,u) + Lift(meow,v);
}

signed main(){
//    freopen("WIRELESS.inp","r",stdin);
//    freopen("WIRELESS.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<n; i++){
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back({y,z});
        a[y].push_back({x,z});
    }
    if (q !=1) DFS(1,0,0,0);
    for (int i=1; i<=q; i++){
        cin >> k;
        if (k == 1){
            int x;
            cin >> x;
            cout << 0 << endl;
        }
        else if (k == 2){
            int u,v;
            cin >> u >> v;
            int meow = LCA(u,v);
            cout << meow << endl;
            cout << Lift(meow,u) + Lift(meow,v) << endl;
        }
        else if (k == 3){
            int x,y,z;
            cin >> x >> y >> z;
            int lca1 = LCA(x,y);
            int lca2 = LCA(y,z);
            int lca3 = LCA(x,z);

            int res = min({GetDist(lca1,x) + GetDist(lca1,y) + GetDist(lca1,z),
                      GetDist(lca2,x) + GetDist(lca2,y) + GetDist(lca2,z),
                      GetDist(lca3,x) + GetDist(lca3,y) + GetDist(lca3,z)});

            cout << lca1 << " " << lca2 << endl;
            cout << res << endl;
        }
        else{
            int x,y;
            test = i;
            x = k;
            while (x--){
                cin >> y;
                mark[y] = i;
            }
            cout << solve() << endl;
        }
        cout << endl;
    }
    return 0;
}
