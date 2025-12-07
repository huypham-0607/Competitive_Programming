/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "NUMBERS"

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

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        char c;
        cin >> c;
        if (c=='+') a[i] = 1;
        else if (c=='?') a[i] = 0;
        else if (c=='-') a[i] = -1;
    }
    dp[0][0] = 1;
    for (int i=1; i<=n; i++){
        for (int j=0; j<=n; j++){
            if (a[i]<=0) dp[i][j] = max(dp[i][j],dp[i-1][j+1]);
            if (a[i]>=0 && j!=0) dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
        }
    }
    int mn = INF;
    int mx = 0;

}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
