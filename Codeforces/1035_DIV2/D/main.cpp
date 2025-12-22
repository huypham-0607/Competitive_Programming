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
const int N = 5000+10;
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
int n,MD;
int dp[N][N];

/*Solution*/
void solve(){
    cin >> n >> MD;
    dp[n+1][0] = 1;
//    for (int i=1; i<=n; i++){
//        int cnt = n-i+1;
//        for (int j=0; j<=cnt; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    for (int i=n; i>0; i--){
        int cnt = n-i+1;
        for (int j=0; j<=cnt; j++){
            if (j!=0){
                dp[i][j] = (dp[i][j] + dp[i+1][j-1])%MD;
            }
            if (j!=cnt){
                dp[i][j] = (dp[i][j] + dp[i+1][j]*(j+1)%MD*i%MD)%MD;
            }
//            cout << i << " " << j << " " <<
        }
    }
    int t = 0;
    for (int j=0; j<=n; j++){
        t = (t+dp[1][j])%MD;
    }
    cout << t << endl;

//    for (int i=1; i<=n; i++){
//        int cnt = n-i+1;
//        for (int j=0; j<=cnt; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    dp[n+1][0] = 0;
    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++){
            dp[i][j] = 0;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}

