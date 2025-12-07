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
int n,p,k;
ll dp[N][(1<<7)+10];
int a[N];
int s[N][10];
vector<pii> v;

/*Solution*/
void solve(){
    cin >> n >> p >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end(),greater<pii>());
    for (int i=1; i<=n; i++){
        for (int j=1; j<=p; j++){
            cin >> s[i][j];
        }
    }
    for (int mask=1; mask<(1<<p); mask++){
        dp[0][mask] = -LLINF;
    }
    for (int i=1; i<=n; i++){
        int pos = v[i-1].se;
        for (int mask=0; mask<(1<<p); mask++){
            int cnt = __builtin_popcount(mask);
            if (cnt > i) continue;
            if (cnt < i) dp[i][mask] = dp[i-1][mask] + ((i-cnt<=k)? a[pos]: 0);
            for (int idx=0; idx<p; idx++){
                if (mask&(1<<idx)) dp[i][mask] = max(dp[i][mask],dp[i-1][mask^(1<<idx)]+s[pos][idx+1]);
            }
        }
    }
    cout << dp[n][(1<<p)-1] << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
