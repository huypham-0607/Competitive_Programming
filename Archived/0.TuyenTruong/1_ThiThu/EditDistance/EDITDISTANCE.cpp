/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
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
int n,m;
string s,e;
int dp[5010][5010];

/*Solution*/
void solve(){
    cin >> s >> e;
    n = e.size(); m = s.size();
    s = "#"+s;
    e = "#"+e;
    for (int i=0; i<=m; i++){
        dp[0][i] = i;
    }
    for (int i=0; i<=n; i++){
        dp[i][0] = i;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            dp[i][j] = min(dp[i][j-1]+1,dp[i-1][j]+1);
            if (e[i] == s[j]){
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            }
            else dp[i][j] = min(dp[i][j],dp[i-1][j-1]+1);
        }
    }
//    for (int i=0; i<=n; i++){
//        for (int j=0; j<=m; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << dp[n][m] << endl;

}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

