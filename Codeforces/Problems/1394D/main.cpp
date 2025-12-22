/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 2e12+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
int t[N],h[N];
vector<int> adj[N];
int dp[N][2];
int mn[N];

void DFS(int u, int p){
    int total = 0;
    int cst = 0;
    if (p!=0) ++total;
    vector<int> cnt(2);
    for (int v:adj[u]){
        if (v==p) continue;
        ++total;
        DFS(v,u);
        if (h[u] > h[v]){
            dp[v][1] = LLINF;
            mn[v] = 0;
        }
        else if (h[u] < h[v]){
            dp[v][0] = LLINF;
            mn[v] = 1;
        }
        cst+=dp[v][mn[v]];
        ++cnt[mn[v]];
    }
    vector<int> tmp;
    for (int dir=0; dir<=1; dir++){
        tmp.clear();
        if (p!=0) cnt[(dir+1)%2]++;

        int mncst = cst+(total-min(cnt[0],cnt[1]))*t[u];
        int rem = total/2-min(cnt[0],cnt[1]);
        int sussed;
//        cout << cnt[0] << " " << cnt[1] << endl;
        if (cnt[0] < cnt[1]) sussed=0;
        else sussed = 1;
//        cout << sussed << endl;
        for (auto v:adj[u]){
            if (v==p) continue;
            if (mn[v]==sussed) continue;
            int delta = dp[v][(mn[v]+1)%2]-dp[v][mn[v]];
            if (delta<t[u]) tmp.push_back(delta-t[u]);
        }
        sort(tmp.begin(),tmp.end());
        for (int i=0; i<min(rem,(int)tmp.size()); i++){
            mncst+=tmp[i];
        }

        dp[u][dir] = mncst;

        if (p!=0) cnt[(dir+1)%2]--;
    }
//    cout << u << " " <<  dp[u][0] << " " << dp[u][1] << " " << total << endl;
//    cout << cnt[0] << " " << cnt[1] << " " << cst << " " << mn[u] << endl << endl;
    if (dp[u][1] < dp[u][0]) mn[u] = 1;
    else mn[u] = 0;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> t[i];
    }
    for (int i=1; i<=n; i++){
        cin >> h[i];
    }
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1,0);
    cout << min(dp[1][0],dp[1][1]) << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
