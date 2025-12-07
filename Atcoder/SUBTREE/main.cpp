#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,mod;
int f[maxn],g[maxn];
vector<int> a[maxn];

void dfs(int u, int p){
    for (auto v:a[u]){
        if (v==p) continue;
        dfs(v,u);
        f[u]=f[u]*(f[v]+1)%mod;
    }
}

void dfs2(int u, int p){
    vector<int> vt;
    vector<int> node;
    for (auto v:a[u]){
        if (v==p) continue;
        vt.push_back(f[v]+1);
        node.push_back(v);
    }
    for (signed i=signed(vt.size()-2); i>=0; i--){
        vt[i] = vt[i]*vt[i+1]%mod;
    }
    vt.push_back(1);
    int prev = 1;
    for (signed i=0; i<signed(vt.size()-1); i++){
        g[node[i]] = ((prev*vt[i+1])%mod*g[u]+1)%mod;
        prev = prev*(f[node[i]]+1)%mod;
    }
    for (auto v:a[u]){
        if (v == p) continue;
        dfs2(v,u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> mod;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        f[i] = 1;
        g[i] = 1;
    }
    dfs(1,0);
    dfs2(1,0);
//    for (int i=1; i<=n; i++){
//        cout << f[i] << " " << g[i] << endl;
//    }
    for (int i=1; i<=n; i++){
        cout << f[i]*g[i]%mod << endl;
    }
    return 0;
}
