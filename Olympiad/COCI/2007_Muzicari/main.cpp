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
int n,t;
int dp[5010][510];
int v[510];
int loc[N];

/*Solution*/
void solve(){
    cin >> t >> n;
    for (int i=1; i<=n; i++){
        loc[i] = -1;
        cin >> v[i];
        dp[0][i] = -1;
    }
    int mx = 0;
    for (int i=1; i<=t; i++){
        for (int j=1; j<=n; j++){
            if (dp[i][j-1]!=0) dp[i][j] = dp[i][j-1];
            if (v[j]<=i && dp[i-v[j]][j-1]!=0) dp[i][j] = j;
//            cout << dp[i][j] << " ";
        }
//        cout << endl;
        if (dp[i][n]) mx = i;
    }
    int i = mx;
    int j = n;
    while (i!=0){
//        cout << i << " " << j << endl;
        loc[dp[i][j]] = i-v[dp[i][j]];
        int luuj = dp[i][j];
        j = dp[i][j]-1;
        i-=v[luuj];
//        cin >> luuj;
    }
    int prev = 0;
    for (int i=1; i<=n; i++){
        if (loc[i] == -1){
            cout << prev << " ";
            prev+=v[i];
        }
        else cout << loc[i] << " ";
    }
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
