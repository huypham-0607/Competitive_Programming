/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "harvest"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e17+3;

/*TestCases*/
int test=1;
bool solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m;
vector<pii> v;
long long dp[N*2][2];

/*Solution*/
bool solve(){
    cin >> n >> m;
    if (n==0 && m==0) return false;
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        v.push_back({x,1});
    }
    for (int i=1; i<=m; i++){
        int x; cin >> x;
        v.push_back({x,0});
    }
    v.push_back({0,1});
    dp[0][0] = dp[0][1] = LLINF;
    sort(v.begin(),v.end());
    for (int i=1; i<(int)v.size(); i++){
        if (v[i].se){
            dp[0][0] = dp[0][1] = 0;
            dp[i][0] = dp[i][1] = INF;
            int j = i-1;
            while (!v[j].se){
                int mn = min(dp[j-1][0],dp[j-1][1]);
                dp[i][0] = min(dp[i][0],(v[i].fi-v[j].fi)*2+mn);
                dp[i][1] = min(dp[i][1],(v[i].fi-v[j].fi)*1+mn);
                --j;
            }
        }
        else{
            dp[i][0] = dp[i-1][0]+(v[i].fi-v[i-1].fi)*1;
            dp[i][1] = dp[i-1][1]+(v[i].fi-v[i-1].fi)*2;
        }
    }
    for (int i=1; i<(int)v.size(); i++){
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << min(dp[(int)v.size()-1][0],dp[(int)v .size()-1][1]) << " ";
    v.clear();
    return true;
}

/*Driver Code*/
signed main(){
//    freopen(NAME".INP","r",stdin);
//    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve()){};

    return 0;
}
