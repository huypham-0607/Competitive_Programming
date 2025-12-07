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
const int N = 100+10;
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
int a[N];
int dp[N][N][N];
// i - Total number of days
// j - Number of Breakouts
// k - Number of days since last breakout

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            for (int k=0; k<=n; k++){
                dp[i][j][k] = INF;
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            if (j == 1){
                dp[i][j][i-1] = dp[i-1][j][i-2] + ((i-1 == a[i])? 0 : 1);
            }
            else{
                for (int k=0; k<=i-j; k++){
                    if (k == 0){
                        for (int k2=0; k2<=i-j; k2++){
                            dp[i][j][k] = min(dp[i][j][k],dp[i-1][j-1][k2]+((a[i] == 0)? 0 : 1));
                        }
                    }
                    else{
                        dp[i][j][k] = dp[i-1][j][k-1] + ((k == a[i])? 0 : 1);
                    }
                }
            }
        }
    }
    for (int j=1; j<=n; j++){
        int ans = INF;
        for (int k=0; k<=n-j; k++){
            ans = min(ans,dp[n][j][k]);
        }
        cout << ans << endl;
    }
//    for(int j=1; j<=n; j++){
//        for (int k=1; k<=n; k++){
//            if (dp[n][j][k] == INF) cout << -1 << " ";
//            else cout << dp[n][j][k] << " ";
//        }
//        cout << endl;
//    }
}

/*Driver Code*/
int main(){
    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
