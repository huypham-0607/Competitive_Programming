#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;
const int maxlog = 20;

int n,m,q,tme = 0,timedfs = 0;
int parent[maxn],lg[maxn];
vector<pii> a[maxn];
int start[maxn];
pii st[maxn*2][maxlog];
int dist[maxn*2][maxlog];
int h[maxn*2],elt[maxn*2],d[maxn*2];

void Init(int n){
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
}

int Find (int x){
    return (parent[x] == x)? x: parent[x] = Find(parent[x]);
}

bool Same(int x, int y){
    return (Find(x) == Find(y));
}

void Union(int x, int y){
    if (!Same(x,y)){
        int u = Find(x);
        int v = Find(y);
        if (u>v) swap(u,v);
        parent[v] = u;
        a[u].push_back({v,tme});
        a[v].push_back({u,tme});
    }
}

void dfs(int u, int p, int lvl, int dist){
    timedfs++;
    elt[timedfs] = u;
    h[timedfs] = lvl;
    d[timedfs] = dist;
    start[u] = timedfs;
    for (auto in:a[u]){
        if (in.fi == p) continue;
        dfs(in.fi,u,lvl+1,in.se);
        timedfs++;
        elt[timedfs] = u;
        h[timedfs] = lvl;
        d[timedfs] = in.se;
    }
}

int getdist(int x, int y){
    if (x == y) return 0;
    if (start[x] > start[y]) swap(x,y);
    int u = start[x]+1;
    int v = start[y];
//    cout << u << " " << v << endl;
    int l = lg[v-u+1];
    int meow = max(dist[u][l],dist[v-(1<<l)+1][l]);
    if (meow >= INF) return -1;
    else return meow;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lg[1] = 0;
    cin >> n >> m >> q;
    Init(n);
    for (int i=1; i<=m; i++){
        tme++;
        int u,v;
        cin >> u >> v;
        Union(u,v);
    }
    for (int i=1; i<=n; i++){
        if (parent[i] == i){
            a[0].push_back({i,INF});
            a[i].push_back({0,INF});
        }
    }
    dfs(0,0,0,INF+1);
    for (int i=2; i<=timedfs; i++){
        lg[i] = lg[i/2]+1;
    }
    for (int i=1; i<=timedfs; i++){
        st[i][0] = {h[i],elt[i]};
        dist[i][0] = d[i];
    }
    for (int i=1; i<=maxlog; i++){
        for (int j=1; j<=timedfs; j++){
            if (j + (1 << i) -1 > n*2) break;
            st[j][i] = min(st[j][i-1],st[j + (1 << (i-1))][i-1]);
            dist[j][i] = max(dist[j][i-1],dist[j + (1 << (i-1))][i-1]);
        }
    }
//    for (int i=0; i<=n; i++){
//        cout << i << " ";
//        for  (auto in:a[i]){
//            cout << "[" << in.fi << "," << in.se << "] ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    for (int i=1; i<=timedfs; i++){
//        cout << d[i] << " ";
//    }
//    cout << endl;
    while (q--){
        int u,v;
        cin >> u >> v;
        cout << getdist(u,v) << endl;
    }
//    pii meow = {1,0};
//    pii woof = {1,1};
//    pii oof = min(meow,woof);
//    cout << oof.fi << " " << oof.se;
    return 0;
}
