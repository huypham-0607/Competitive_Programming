/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "nocross"

using namespace std;

/*Constants*/
const int N = 1010;
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
int a[N],b[N];
int dp[N][N];

/*Solution*/
void solve(){
    cin >> n;
//    int ans = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            if (abs(a[i]-b[j]) <= 4) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
//            ans = max(ans,dp[i][j]);
        }
    }
    cout << dp[n][n];
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
}

/*Driver Code*/
int main(){
    freopen(NAME".in","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
