/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 5010;
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
int val[N];
int dp[N][110];
vector<int> a[N],GCD[110],pfactor[10010];
vector<int> Prime;

//Sieve
void Sieve(){
    bitset<110> bs;
    bs.set();
    bs[0] = bs[1] = false;
    for (int i=2; i<=10; i++){
        if (!bs[i]) continue;
        for (int j=i*i; j<=100; j+=i){
            bs[j] = false;
        }
    }
    for (int i=1; i<=100; i++){
        if (bs[i]) Prime.push_back(i);
    }
}

//DP
void DFS(int u, int p){
    vector<int> child;
    vector<int> mn;
    for (auto v:a[u]){
        if (v==p) continue;
        child.push_back(v);
        DFS(v,u);
    }
    for (int i=2; i<=10000; i++){
        int rawr = 0;
        for (auto v:a[u]){
            if (v==p) continue;
            int mn = LLINF;
            for (auto j:pfactor[i]){
                mn = min(mn,dp[v][j]);
            }
            rawr+=mn;
        }
        if (i!=val[u]) rawr+=i;
        for (auto j:pfactor[i]){
            dp[u][j] = min(dp[u][j],rawr);
        }
    }
}

/*Solution*/
void solve(){
    Sieve();
    for (int i=2; i<=10000; i++){
        for (auto j:Prime){
            if (i%j==0) pfactor[i].push_back(j);
        }
    }
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> val[i];
    }
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=100; j++){
            dp[i][j] = LLINF;
        }
    }
    DFS(1,0);
    int ans = INF;
    for (int i=2; i<=100; i++){
        ans = min(ans,dp[1][i]);
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
