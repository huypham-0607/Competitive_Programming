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
const int N = 3e5+10;
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
int n,k;
int dp[N][12];
int a[N];

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        for (int j=0; j<=k; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        for (int j=0; j<=k; j++){
            dp[i][j] = dp[i-1][j] + a[i];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=k; j++){
            dp[i][j] = min(dp[i][j],dp[i][j-1]);
            int mn = a[i];
            for (int k=0; k<=min(j,i-1); k++){
                mn = min(mn,a[i-k]);
                dp[i][j] = min(dp[i][j],dp[i-k-1][j-k]+mn*(k+1));
            }
        }
    }
    cout << dp[n][k] << endl;
    for (int i=1; i<=n; i++){
        for (int j=0; j<=k; j++){
//            cout << dp[i][j] << " ";
            dp[i][j] = 0;
        }
//        cout << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
