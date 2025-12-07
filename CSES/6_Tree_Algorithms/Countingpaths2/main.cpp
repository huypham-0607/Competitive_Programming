#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;

vector<vector<int>> up(20,vector<int>(maxn,0));
int t=0;
int n,m,lg;
vector<int> tin(maxn,0),tout(maxn,0),a[maxn],l(maxn,0),pre(maxn,0);

void preprocess(int u, int p, int lvl){
    tin[u] = ++t;
    up[0][u] = p;
    l[u] = lvl;
    for (int i=1; i<=lg; i++){
        up[i][u] = up[i-1][up[i-1][u]];
    }
    for (auto v:a[u]){
        if (v==p) continue;
        preprocess(v,u,lvl+1);
    }
    tout[u] = ++t;
}

bool is_anc(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int LCA(int u, int v){
    if (is_anc(u,v)) return u;
    if (is_anc(v,u)) return v;
    for (int i=lg; i>=0; i--){
        if (!is_anc(up[i][v],u)){
            v = up[i][v];
        }
    }
    return up[0][v];
}

void dfs(int u, int p){
    for (auto v:a[u]){
        if (v==p) continue;
        dfs(v,u);
        pre[u]+=pre[v];
    }
}

int main(){
//    freopen("meow.inp","r",stdin);
//    freopen("meow.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    lg = ceil(log2(n));
    tout[0] = maxn*3;
    preprocess(1,0,0);

    while (m--){
        int x,y;
        cin >> x >> y;
        int lca = LCA(x,y);
        pre[x]++;
        pre[y]++;
        pre[lca]--;
        pre[up[0][lca]]--;
    }
//    for (int i=0; i<=lg; i++){
//        for (int j=0; j<=n; j++){
//            cout << cnt[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
    dfs(1,0);
    for (int i=1; i<=n; i++){
        cout << pre[i] << " ";
    }
//    cout << "\n";
    return 0;
}

