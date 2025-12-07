#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e18;

int n;
vector<int> a[maxn];
int f[maxn],g[maxn],leaf[maxn],l[maxn],upleaf[maxn];

void dfs(int u, int p){
    if (!a[u].size()){
        leaf[u] = 1;
        f[u] = 0;
        return;
    }
    for (auto v:a[u]){
        if (v==p) continue;
        dfs(v,u);
        f[u]+=f[v]+(l[v]+1)*leaf[v];
        leaf[u]+=leaf[v];
    }
}

void dfs2(int u, int p){
    for (auto v:a[u]){
        g[v]=f[u]-f[v]-(l[v]+1)*leaf[v]+g[u]+3*(leaf[1]-leaf[v]);
        dfs2(v,u);
    }
}

signed main(){
    freopen("dirtraverse.in","r",stdin);
    freopen("dirtraverse.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        l[i] = (long long) s.size();
        int m,x;
        cin >> m;
        while (m--){
            cin >> x;
            a[i].push_back(x);
        }
    }
    dfs(1,0);
    dfs2(1,0);
    int ans = INF;
    for (int i=1; i<=n; i++){
        if (a[i].size() > 0){
            ans = min(ans,f[i]+g[i]-leaf[1]);
        }
    }
    cout << ans;
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << f[i] << " ";
//    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << g[i] << " ";
//    }
//    cout << endl;
    return 0;
}
