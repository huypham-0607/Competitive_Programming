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
const int N = 22;
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
int a[N][N];
int dp[(1<<21)];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    dp[0] = 1;
    for (int mask=1; mask<(1<<n); mask++){
        int j = __builtin_popcount(mask)-1;
        for (int i=0; i<n; i++){
            if (a[i][j]){
                dp[mask]= (dp[mask]+dp[mask^(1<<i)])%INF;
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
