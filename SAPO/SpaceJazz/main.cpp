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
string s;
int dp[N][N];

/*Solution*/
void solve(){
    cin >> s;
    n = s.size();
    for (int i=0; i<n; i++){
        dp[i][i] = 1;
    }
    for (int i=0; i<n-1; i++){
        if (s[i] == s[i+1]){
            dp[i][i+1] = 0;
        }
        else dp[i][i+1] = 2;
    }
    for (int delta=2; delta<n; delta++){
        int l,r;
        for (l=0, r=l+delta; l+delta<n; l++, r++){
            dp[l][r] = INF;
            for (int mid=l; mid<r; mid++){
                dp[l][r] = min(dp[l][r],dp[l][mid]+dp[mid+1][r]);
            }
            if (s[l] == s[r]){
//                if (l+1 == r-1){
//                    dp[l][r] = min(dp[l][r],dp[l+1][r-1]);
//                }
                for (int mid=l+1; mid<=r-1; mid++){
                    dp[l][r] = min(dp[l][r],dp[l+1][mid]+dp[mid+1][r-1]);
                }
            }
//            cout << l << " " << r << " " << dp[l][r] << endl;
        }
    }
    cout << dp[0][n-1];
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
