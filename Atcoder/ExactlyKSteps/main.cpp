/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int LG = 18;
const int N = 2e5+10;
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
int n,q;
vector<int> a[N];
int up[N][LG];
int h[N];
pair<int,int> f[N],g[N];


void DFS(int u, int p){
    up[u][0] = p;
    h[u] = h[p]+1;

    for (int lg=1; lg<LG; lg++){
        int v = up[u][lg-1];
        up[u][lg] = up[v][lg-1];
    }

    f[u] = {u,0};

    for (auto v:a[u]){
        if (v==p) continue;
        DFS(v,u);
        if (f[u].se < f[v].se+1){
            f[u] = f[v];
            f[u].se++;
        }
    }
}

void DFS2(int u, int p){
    pair<int,int> rawr = g[u];
    rawr.se++;
    pair<int,int> woof = rawr;
    for (auto v:a[u]){
        if (v==p) continue;
        if (f[v].se+2>rawr.se){
            woof = rawr;
            rawr = f[v];
            rawr.se+=2;
        }
        else if (f[v].se+2>woof.se){
            woof = f[v];
            woof.se+=2;
        }
    }
    for (auto v:a[u]){
        if (v==p) continue;
        if (rawr.fi!=f[v].fi) g[v] = rawr;
        else g[v] = woof;
        DFS2(v,u);
    }
}

int Lift(int u, int k){
    int v = u;
    for (auto lg=0; lg<LG; lg++){
        if (k&(1<<lg)) v = up[v][lg];
    }
    return v;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    h[0]=-1;
    DFS(1,0);
    g[1] = {1,0};
    DFS2(1,0);

    cin >> q;
    for (int i=1; i<=q; i++){
        int u,k;
        cin >> u >> k;
        if (f[u].se>=k) cout << Lift(f[u].fi,f[u].se-k) << endl;
        else if (h[u]>=k) cout << Lift(u,k) << endl;
        else if (g[u].se>=k) cout << Lift(g[u].fi,g[u].se-k)<< endl;
        else cout << -1 << endl;
    }

//    for (int u=1; u<=n; u++){
//        cout << h[u] << endl;
//    }
//    cout << endl;
//    for (int u=1; u<=n; u++){
//        cout << f[u].fi << " " << f[u].se << endl;
//    }
//    cout << endl;
//    for (int u=1; u<=n; u++){
//        cout << g[u].fi << " " << g[u].se << endl;
//    }
//    cout << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
