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
int n,sum;
bool dp[N][N];
bool reach[N];
int a[N];

/*Solution*/
void solve(){
    cin >> n >> sum;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=0; i<=sum; i++){
        dp[i][0] = 1;
    }
    reach[0] = true;
    for (int idx=1; idx<=n; idx++){
        int val = a[idx];
        for (int i=sum; i>=val; i--){
            if (reach[i-val]){
                for (int j=1; j<=sum; j++){
                    if (dp[i-val][j]) dp[i][j] = true;
                    if (j>=val && dp[i-val][j-val]) dp[i][j] = true;
                }
                reach[i] = true;
            }
        }
//        for (int i=1; i<=sum; i++){
//            for (int j=1; j<=sum; j++){
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }
    int cnt = 0;
    for (int i=0; i<=sum; i++){
        if (dp[sum][i]) ++cnt;
    }
    cout << cnt << endl;
    for (int i=0; i<=sum; i++){
        if (dp[sum][i]) cout << i << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

