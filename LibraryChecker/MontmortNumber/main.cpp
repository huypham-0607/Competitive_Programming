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
const int N = 1e6+10;
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

int dp[N+1];

/*Solution*/
void solve(){
    cin >> n >> m;
    dp[0] = 1;
    dp[1] = 0;
    for (int i=2; i<=N; i++){
        dp[i] = (dp[i-1]+dp[i-2])%m*(i-1)%m;
    }
    for (int i=1; i<=n; i++){
        cout << dp[i] << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
