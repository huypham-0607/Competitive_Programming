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
int n,m;
int w[210],v[210];
int dp[210][5020];

/*Solution*/
void solve(){
    cin >> n >> m;
    int lim = 0;
    for (int i=1; i<=n; i++){
        long long x;
        cin >> x;
        while (x%5==0){
            ++w[i];
            ++lim;
            x/=5;
        }
        while (x%2==0){
            ++v[i];
            x/=2;
        }
    }
    lim = min(lim,(int)5010);
    for (int i=0; i<=n; i++){
        for (int k=0; k<=lim; k++){
            dp[i][k] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i=1; i<=n; i++){
        int weight = w[i];
        int val = v[i];
        for (int j=m; j>0; j--){
            for (int k=weight; k<=lim; k++){
                if (dp[j-1][k-weight] == -INF) continue;
                dp[j][k] = max(dp[j][k],dp[j-1][k-weight]+val);
            }
        }
    }
    int ans = 0;
//    if (m == 185) cout << lim << endl;
    for (int k=1; k<=lim; k++){
        ans = max(ans,min(k,dp[m][k]));
    }
    cout << ans;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
