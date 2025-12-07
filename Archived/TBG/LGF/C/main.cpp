/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m;
int suf[N];
vector<int> v;
vector<vector<int>> a(N,vector<int>()), b(N,vector<int>());
vector<int> f(N);
vector<int> g(N);

pii BFS(int x, vector<vector<int>> & adj){
    queue<piii> q;
    q.push({{x,0},1});
    pii res = make_pair(0,0);
    while (!q.empty()){
        int u = q.front().fi.fi;
        int p = q.front().fi.se;
        int depth = q.front().se;

        q.pop();

        res = {u,depth};
        for (auto v:adj[u]){
            if (v==p) continue;
            q.push({{v,u},depth+1});
        }
    }
    return res;
}

int GetDia(vector<vector<int>> & adj){
    pii res = BFS(1,adj);
    res = BFS(res.fi,adj);
    return res.se-1;
}

void DFSF(int u, int p, vector<vector<int>> & adj){
    f[u] = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        DFSF(v,u,adj);
        f[u] = max(f[u],f[v]+1);
    }
}

void DFSG(int u, int p, vector<vector<int>> & adj){
    if (u==1) g[u] = 0;
    int mx1 = 0;
    int mx2 = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        if (f[v]+1 > mx1){
            mx2 = mx1;
            mx1 = f[v]+1;
        }
        else if (f[v]+1 > mx2) mx2 = f[v]+1;
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        if (f[v]+1 == mx1){
            g[v] = max(mx2+1,g[u]+1);
        }
        else g[v] = max(mx1+1,g[u]+1);
        DFSG(v,u,adj);
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1; i<m; i++){
        int u,v;
        cin >> u >> v;
        b[v].push_back(u);
        b[u].push_back(v);
    }
    DFSF(1,0,a);
    DFSG(1,0,a);
    int diaa = GetDia(a), diab = GetDia(b);
    int dia = max(diaa,diab);
//    cout << dia << endl;

    for (int i=1; i<=n; i++){
        v.push_back(max(f[i],g[i]));
//        cout << f[i] << " " << g[i] << endl;
    }
//    cout << endl;
    sort(v.begin(),v.end());
    for (int i=n-1; i>=0; i--){
        suf[i] = suf[i+1]+v[i];
    }
    DFSF(1,0,b);
    DFSG(1,0,b);
    int res = 0;
    for (int u=1; u<=m; u++){
//        cout << f[u] << " " << g[u] << endl;
        int rawr = max(f[u],g[u]);
        int pos = upper_bound(v.begin(),v.end(),dia-rawr-1)-v.begin();
        res+=pos*dia+(rawr+1)*(n-pos)+suf[pos];
//        cout << rawr << " " << pos << " " << res << endl;
    }
//    cout << endl;
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

