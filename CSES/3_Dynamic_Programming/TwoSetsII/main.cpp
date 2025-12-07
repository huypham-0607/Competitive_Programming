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
int dp[510][100000];

/*Solution*/
void solve(){
    cin >> n;
    int total = n*(n+1)/2;
    if (total%2){
        cout << 0 << endl;
        return;
    }
    int m = total/2;
    dp[0][0] = 1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            dp[i][j] = dp[i-1][j];
            if (j>=i) dp[i][j]=(dp[i][j]+dp[i-1][j-i])%INF;
        }
    }
    cout << dp[n][m] << endl;
//    for (int i=0; i<=n; i++){
//        for (int j=0; j<=m; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
