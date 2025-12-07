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

int n,m,q;
int tme = 0,timedfs = 0;

int up[maxlog][maxn];
int st[maxlog][maxn];
int tiin[maxn],tout[maxn];
int parent[maxn];
vector<pii> a[maxn];

//DSU

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

void dfs(int u, int p, int dist){
    tiin[u] = ++timedfs;
    up[0][u] = p;
    st[0][u] = dist;
    for (int i=1; i<=maxlog; i++){
        up[i][u] = up[i-1][up[i-1][u]];
        st[i][u] = max(st[i-1][u],st[i-1][up[i-1][u]]);
    }
    for (auto in:a[u]){
        if (in.fi == p) continue;
        dfs(in.fi,u,in.se);
    }
    tout[u] = ++timedfs;
    for (int i=1; i<=n; i++){
        cout << tiin[i] << " " << tout[i] << " ";
        cout << endl;
    }
}

bool isanc(int u, int v){
    return tiin[u]<=tiin[v] && tout[u]>=tout[v];
}

int LCA(int u, int v){
    if (isanc(u,v)) return u;
    if (isanc(v,u)) return v;
    for (int lg = maxlog; lg>=0; lg--){
        int x = up[lg][v];
        if (!isanc(x,u)){
            v = x;
        }
    }
    if (!isanc(up[0][v],u)) return 0;
    else return up[0][v];
}

int gettime(int u, int v){
    if (u == v) return 0;
    if (v == 0) return -1;
    int ans = 0;
    for (int lg = maxlog; lg>=0; lg--){
        int x = up[lg][u];
        if (isanc(v,u)){
            ans = max(ans,st[lg][u]);
            u = x;
        }
    }
    return ans;
}

int query(int u, int v){
    int lca = LCA(u,v);
    return max(gettime(u,lca),gettime(v,lca));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    cin >> n >> m >> q;
//    Init(n);
    tiin[0] = 0;
    tout[0] = INF;
//    for (int i=1; i<=m; i++){
//        tme++;
//        int u,v;
//        cin >> u >> v;
//        Union(u,v);
//    }
//    for (int i=1; i<=n; i++){
//        if (parent[i] == i){
//            a[i].push_back({0,0});
//            a[0].push_back({i,0});
//        }
//    }
    cin >> n >> q;
    for (int i=2; i<=n; i++){
        int x;
        cin >> x;
        a[i].push_back({x,0});
        a[x].push_back({i,0});
    }
    cout << endl;
    dfs(1,0,0);
    while (q--){
        int l,r;
        cin >> l >> r;
        cout << LCA(l,r) << endl;
    }
    for (int i=1; i<=n; i++){
        for (auto in:a[i]){
            cout << in.fi << " " << in.se << " ";
        }
        cout << endl;
    }
    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << st[0][i] << " " << st[1][i] << " ";
//        cout << endl;
//    }
//    cout << isanc(5,2);
    cout << endl;
    for (int i=1; i<=n; i++){
        cout << i << " " << tiin[i] << " " << tout[i] << " ";
        cout << endl;
    }
    return 0;
}
