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
const long long LLINF = 1e17+3;

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
int dp[3][N];

int GetMD(int x){
    int tmp = abs(x)/3+1;
    return (x+3*tmp)%3;
}

/*Solution*/
void solve(){
    cin >> n;
    dp[0][0] = 0;
    dp[1][0] = -LLINF;
    dp[2][0] = -LLINF;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        dp[0][i] = dp[0][i-1];
        dp[1][i] = dp[1][i-1];
        dp[2][i] = dp[2][i-1];

        int t = 0;
        for (int j=i; j>=1; j--){
            t+=a[j];
            int md = GetMD(a[i]+a[j]);
            for (int idx=0; idx<3; idx++){
                if (j == 1){
                    dp[(idx+md)%3][i] = max(dp[(idx+md)%3][i],dp[idx][0]+t);
                }
                else dp[(idx+md)%3][i] = max(dp[(idx+md)%3][i],dp[idx][j-2]+t);
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++){
        ans = max(ans,dp[0][i]);
    }
    cout << ans << endl;
//    for (int i=1; i<=n; i++){
//        for (int j=0; j<3; j++){
//            cout << dp[j][i] << " ";
//        }
//        cout << endl;
//    }
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
