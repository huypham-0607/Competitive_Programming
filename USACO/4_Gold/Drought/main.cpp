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
const int N = 102;
const int M = 1002;
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
int a[N];
int dp[N][M][M];
int suf[N][M][M];
//i: Current index
//j: Current overall height
//k: Current last index height


/*Solution*/
void solve(){
    cin >> n;
    int m = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        m = max(m,a[i]);
    }
    dp[1][a[1]][a[1]] = 1;
    for (int i=a[1]; i>=0; i--){
        suf[1][a[1]][i] = 1;
    }
    for (int i=2; i<=n; i++){
        for (int j=a[i]; j>=0; j--){
            for (int k=a[i]; k>j; k--){
                int inc = a[i] - k;
                dp[i][j][k] = suf[i-1][j][min(j+inc,(int) 1001)];
                if (inc) dp[i][j][k] = (dp[i][j][k] + dp[i-1][min(j+inc,(int) 1001)][min(j+inc,(int) 1001)])%INF;
                suf[i][j][k] = (suf[i][j][k+1]+dp[i][j][k])%INF;
            }
            int inc = a[i]-j;
            for (int h=a[i-1]; h>=j; h--){
                dp[i][j][j] = (dp[i][j][j] + suf[i-1][h][min(j+inc,(int)1001)])%INF;
            }
            suf[i][j][j] = (suf[i][j][j+1]+dp[i][j][j])%INF;
        }
    }
//    for (int i=1; i<=n; i++){
//        cout << "{" << i << "}" << endl;
//        for (int j=a[i]; j>=0; j--){
//            for (int k=a[i]; k>=0; k--){
//                cout << dp[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//
//    cout << "suf: " << endl << endl;
//
//    for (int i=1; i<=n; i++){
//        cout << "{" << i << "}" << endl;
//        for (int j=a[i]; j>=0; j--){
//            for (int k=a[i]; k>=0; k--){
//                cout << suf[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
    int ans = 0;
    for (int j=a[n]; j>=0; j--){
        for (int k=a[n]; k>=0; k--){
            if (n%2) ans = (ans + dp[n][j][k]*(j+1))%INF;
            else ans = (ans+dp[n][j][k])%INF;
        }
    }
    cout << ans;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
