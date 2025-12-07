/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
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
int n;
vector<int> adj[N];
vector<int> cadj[N];
int depth[N];
int cpar[N],sz[N];
bool vis[N];

int findSize(int u, int p=0){
//    cout << u << " " << p << endl;
    sz[u] = 1;
    for (auto v:adj[u]){
        if (v==p || vis[v]) continue;
        sz[u] += findSize(v,u);
    }
    return sz[u];
}

int findCentroid(int u, int n, int p=0){
    for (auto v:adj[u]){
        if (v==p || vis[v]) continue;
        if (sz[v]>n/2) return findCentroid(v,n,u);
    }
    return u;
}

void initCentroid(int u=1, int p=0, int d=0){
    findSize(u);

//    cout << sz[u] << endl;
    int c = findCentroid(u,sz[u]);
    vis[c] = true;
    if (p!=0) cadj[p].push_back(c);
    cpar[c] = p;
    depth[c] = d;
//    cout << c << endl;

    for (auto v:adj[c]){
        if (vis[v]) continue;
        initCentroid(v,c,d+1);
    }
}



/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    initCentroid();

    for (int i=1; i<=n; i++){
        if (depth[i] >= 26){
            cout << "Impossible!" << endl;
            exit(0);
        }
    }

//    for (int i=1; i<=n; i++){
//        cout << cpar[i] << " ";
//    }
//    cout << endl;

    for (int i=1; i<=n; i++){
        cout << char(65+depth[i]) << " ";
    }
    cout << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
