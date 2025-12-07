/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pdii pair<double,pii>
#define fi first
#define se second

#define NAME "talent"

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
vector<pdii> v;
int dp[1010];

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        int t,w;
        cin >> w >> t;
        v.push_back({1.0*t/w,{-w,t}});
    }
    dp[0] = 0;
    for (int i=1; i<=m; i++){
        dp[i] = -INF;
    }
    long double ans = 0;
    sort(v.begin(),v.end(),greater<pdii>());
    for (auto in:v){
        int t = in.se.se;
        int w = -in.se.fi;
        for (int i=m-1; i>=0; i--){
            if (dp[i] == -INF) continue;
            if (i+w>=m) ans = max(ans,(long double)1.0*(dp[i]+t)/(i+w));
            else dp[i+w] = max(dp[i+w],dp[i]+t);
        }
    }
//    for (int i=0; i<=m; i++){
//        cout << dp[i] << " ";
//    }
//    cout << endl;
    cout << floor(ans*1000) << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".in","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
