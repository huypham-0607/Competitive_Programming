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
const int N = 1e6+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;
const int MD = 1e9+7;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,k;
int dp[N];
int pref;


/*Solution*/
void solve(){
    cin >> n >> m >> k;
    int comb = 1;
    pref = 0;
    dp[0] = 0;
    for (int i=1; i<=n; i++){
        comb = (comb*m)%MD;
        if (i>=k){
            pref = (pref-dp[i-k]+MD)%MD;
        }
        else{
            dp[i] = (dp[i]+m)%MD;
        }
        dp[i] = (dp[i]+pref*(m-1)%MD)%MD;
        pref = (pref+dp[i])%MD;
    }
    cout << (comb-dp[n]+MD)%MD << endl;
}

/*Driver Code*/
signed main(){
    freopen("spainting.in","r",stdin);
    freopen("spainting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
