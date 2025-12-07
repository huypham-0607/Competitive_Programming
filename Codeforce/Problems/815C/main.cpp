/*Author: KawakiMeido*/

//Main Idea: Subtract subtrees from the original tree
//Calculate max sum values of subtrees that we can cut with total node count = x
//At every node x, set InitCost = Sum coupon from all nodes from subtree x
//Greedily take the node with largest value
//Merge dp array of children with current node

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
const int N = 5010;
const int INF = 1e9+7;
const long long LLINF = 1e17+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,b;
int org[N],coupon[N];
vector<vector<int>> dp(N,vector<int>(N,(ll)0));

vector<int> adj[N];
int initcst[N];
int sz[N];

void DFS(int u, int p){
    sz[u] = 1;
    initcst[u] = coupon[u];
    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u);
        sz[u]+=sz[v];
        initcst[u]+=initcst[v];
    }
}

set<pii>* DP(int u, int p){
    int nxt = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        if (!nxt || sz[nxt]<sz[v]) nxt = v;
    }
    set<pii>* st,*st2;
    if (nxt) st = DP(nxt,u);
    else st = new set<pii>;
    for (auto v:adj[u]){
        if (v==p || v==nxt) continue;
        st2 = DP(v,u);
        for (auto in:(*st2)){
            (*st).insert(in);
        }
        delete st2;
    }
    (*st).insert(make_pair(-org[u],u));
    vector<int> tmp = dp[nxt];
    dp[u] = dp[nxt];
    int cursz = sz[nxt];
    for (auto v:adj[u]){
        if (v==p || v==nxt) continue;
        for (int idx=1; idx<=sz[v]; idx++){
            for (int i=idx; i<=cursz+sz[v]; i++){
                if (tmp[i] < dp[u][i-idx] + dp[v][idx]) tmp[i] = dp[u][i-idx]+dp[v][idx];
            }
        }
        dp[u] = tmp;
        cursz+=sz[v];
    }
    int cnt = 0, val = -initcst[u];
    for (auto in:(*st)){
        val+=(-in.fi);
        ++cnt;
        dp[u][cnt] = max(dp[u][cnt],val);
    }
    return st;
}

/*Solution*/
void solve(){
    cin >> n >> b;
    int sum = 0;
    for (int u=1; u<=n; u++){
        int x,y,v;
        cin >> x >> y;
        org[u] = x;
        coupon[u] = y;
        sum+=org[u]-coupon[u];
        if (u!=1){
            cin >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    DFS(1,0);
    DP(1,0);
//    for (int i=1; i<=n; i++){
//        cout << sum - dp[1][n-i] << " ";
//    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
    int ans = 0;
    for (int i=1; i<=n; i++){
        if (b>=sum-dp[1][n-i]) ans = i;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
