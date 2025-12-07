#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n;
vector<int> a[maxn];
int f[maxn],g[maxn],h[maxn];

void dfs(int u, int p){
    for (auto v:a[u]){
        if (v==p) continue;
        dfs(v,u);
        if (f[v]+1 > h[u]) h[u] = f[v]+1;
        if (h[u] > f[u]) swap(h[u],f[u]);
    }
}

void dfs2(int u, int p){
    for (auto v:a[u]){
        if (v==p) continue;
        if (f[v]+1 == f[u]) g[v] = max(g[u]+1,h[u]+1);
        else g[v] = max(g[u]+1,f[u]+1);
    }
    for (auto v:a[u]){
        if (v==p) continue;
        dfs2(v,u);
    }
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
//    cout << "meow" << endl;
    dfs2(1,0);
    for (int i=1; i<=n; i++){
        cout << max(f[i],g[i]) << " ";
    }
    return 0;
}
