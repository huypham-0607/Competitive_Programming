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
int l[N],range[N],val[N];
vector<int> adj[N];
int ans = 0;

void DFS(int u, int p){
    vector<int> lst;
    int delta = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u);
        lst.push_back(val[v]);
    }
    sort(lst.begin(),lst.end());
    if (lst.empty()) return;
    int pivot = min(max(l[u],lst.back()),l[u]+range[u]);
    val[u] = pivot;
    for (auto x:lst){
        delta+=max((int)0,x-pivot);
    }
    ans+=delta;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> l[i];
        int x; cin >> x;
        range[i] = x-l[i];
        val[i] = l[i];
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
//    for (int i=1; i<=n; i++){
//        cout << "i=" << i << ": ";
//        for (auto v:adj[i]){
//            cout << v << " ";
//        }
//        cout << endl;
//    }
//    for (int i=1; i<=n; i++){
//        cout << val[i] << " ";
//    }
//    cout << endl;
    ans = 0;
    DFS(1,0);
    cout << val[1] + ans << endl;
    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
