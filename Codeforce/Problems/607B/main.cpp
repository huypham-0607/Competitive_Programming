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
const int N = 510;
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
int dp[N][N];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        dp[i][i] = 1;
    }
    for (int delta=1; delta<n; delta++){
        for (int l=1, r=l+delta; r<=n; l++,r++){
            dp[l][r] = INF;
            for (int mid=l; mid<r; mid++){
                dp[l][r] = min(dp[l][r],dp[l][mid]+dp[mid+1][r]);
            }
            if (a[l] == a[r]){
                if (r==l+1){
                    dp[l][r] = min(dp[l][r],1);
                }
                else dp[l][r] = min(dp[l][r],dp[l+1][r-1]);
            }
        }
    }
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << dp[1][n] << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
