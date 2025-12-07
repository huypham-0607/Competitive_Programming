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
int n,k;
int a[N];
int dp[N];

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        dp[i] = 0;
    }
    dp[n+1] = dp[n+2] = 0;
    int res = 0;
    int r = n;
    int cur = 0;
    for (int l=n; l>0; l--){
        cur+=a[l];
        while (cur>k){
            cur-=a[r];
            --r;
        }
        res+=r-l+1;
        res+=dp[r+2];
        dp[l] = dp[r+2]+r-l+1;
    }
    cout << res << endl;
//    for (int i=1; i<=n; i++){
//        cout << dp[i] << " ";
//    }
//    cout << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
