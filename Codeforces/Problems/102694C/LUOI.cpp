//#pragma comment(linker, "/STACK:268435456");
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 3e5+10;
const int INF = 2e9;

int test;
int n,q;
int h[maxn];
vector<int> a[maxn];
int up[maxn][21];

void dfs(int u, int p){
//    cout << u << " " << p << endl;
    h[u] = h[p]+1;
    up[u][0] = p;

    for (int i=1; i<=__lg(h[u]); i++){
        int v = up[u][i-1];
        up[u][i] = up[v][i-1];
    }

    for (auto v:a[u]){
        if (v == p) continue;
        dfs(v,u);
    }
}

int Lift(int u, int k){
    for (int lg=0; lg<=__lg(k); lg++){
        if ((k & (1<<lg))) u = up[u][lg];
    }
    return u;
}

int FindLCA(int u, int v){
    if (h[u]!=h[v]){
        if (h[u] > h[v]) swap(u,v);

        int k = h[v] - h[u];

        v = Lift(v,k);

    }
    if (u == v) return u;
    for (int lg = __lg(h[u]); lg>=0; lg--){
        if (up[u][lg] != up[v][lg]){
            u = up[u][lg], v = up[v][lg];
        }
    }
    return up[u][0];
}

int main(){
//    freopen("LUOI.INP","r",stdin);
//    freopen("LUOI.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0);
//    cout << "meow" << endl;
    cin >> q;
    while (q--){
        int x,y,z;
        cin >> x >> y >> z;
        int lca = FindLCA(x,y);
        int dist1 = h[x] - h[lca];
        int dist2 = h[y] - h[lca];
        if (z >= dist1+dist2) cout << y << endl;
        else if (z > dist1) cout << Lift(y,dist2 - (z - dist1)) << endl;
        else cout << Lift(x,z) << endl;
    }

    return 0;
}
