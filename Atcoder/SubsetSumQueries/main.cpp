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
const int N = 5e3+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;
const int MD = 998244353;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int q,k;
int dp[N];


/*Solution*/
void solve(){
    cin >> q >> k;
    char c;
    int x;
    dp[0] = 1;
    while (q--){
        cin >> c >> x;
        if (c == '+'){
            for (int i=k; i>=x; i--){
                dp[i]=(dp[i]+dp[i-x])%MD;
            }
        }
        else{
            for (int i=x; i<=k; i++){
                dp[i]=(dp[i]-dp[i-x]+MD)%MD;
            }
        }
        cout << dp[k] << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
