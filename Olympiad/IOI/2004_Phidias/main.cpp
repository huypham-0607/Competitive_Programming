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
int n,w,h;
int weight[210],height[210];
int dp[610][610];

/*Solution*/
void solve(){
    cin >> w >> h;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> weight[i] >> height[i];
    }
    for (int i=1; i<=w; i++){
        for (int j=1; j<=h; j++){
            dp[i][j] = i*j;
            for (int idx=1; idx<=n; idx++){
                if (weight[idx]<=i && height[idx]<=j) dp[i][j] = min({dp[i][j],dp[i-weight[idx]][j] + dp[weight[idx]][j-height[idx]],dp[i][j-height[idx]] + dp[i-weight[idx]][height[idx]]});
            }
        }
    }
    cout << dp[w][h];
//    cout << endl;
//    for (int i=1; i<=w; i++){
//        for (int j=1; j<=h; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
//    for (int i=1; i<=n; i++){
//        cout << weight[i] << " " << height[i] << endl;
//    }
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
