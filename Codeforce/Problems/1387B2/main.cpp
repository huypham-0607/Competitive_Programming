/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
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
vector<int> v;
int sz[N];
int order[N];
int ans[N];
int timeDFS = 0;

int findSize(int u=1, int p=0){
    sz[u] = 1;
    for (auto v:adj[u]){
        if (v==p) continue;
        sz[u] += findSize(v,u);
    }
    return sz[u];
}

int findCentroid(int u, int n, int p=0){
    for (auto v:adj[u]){
        if (v==p) continue;
        if (sz[v]>n/2) return findCentroid(v,n,u);
    }
    return u;
}

int total = 0;

void DFS(int u, int p, int id){
//    cout << u << endl;
    v.push_back(u);
    order[timeDFS++] = u;
    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u,id);
    }
    total+=sz[u];
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    findSize();
//    cout << sz[1] << endl;
    int centroid = findCentroid(1,sz[1]);
//    cout << centroid << endl;
    findSize(centroid);
//    for (int i=1; i<=n; i++){
//        cout << sz[i] << " ";
//    }
//    cout << endl;
    order[0] = centroid;
    v.push_back(centroid);
    timeDFS++;
    int id = 0;
    for (auto v:adj[centroid]){
        DFS(v,centroid,++id);
    }
    for (int i=0; i<n; i++){
        ans[order[(i+n/2)%n]] = order[i];
    }
    cout << total*2 << endl;
    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
