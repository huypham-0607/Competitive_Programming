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
const int N = 1e5+10;
const int MD = 1e9+7;
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

int dp[N][4];

/*Solution*/
void solve(){
    cin >> n >> m;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i=2; i<=max(n,m); i++){
        dp[i][0] = (dp[i-1][1]+dp[i-1][3])%MD;
        dp[i][1] = (dp[i-1][0]+dp[i-1][2])%MD;
        dp[i][2] = dp[i-1][0];
        dp[i][3] = dp[i-1][1];
    }
    int res=0;
    for (int idx=0; idx<=3; idx++){
        res = (res+dp[n][idx])%MD;
        res = (res+dp[m][idx])%MD;
    }
    if (res-2<0) res = res-2+MD;
    else res-=2;
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
