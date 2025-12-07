/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "JUMP"

using namespace std;

/*Constants*/
const int N = 4e3+10;
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
set<pii> dp[N];

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    dp[1].insert({INF,0});
    for (int i=1; i<=n; i++){
        for (int l=1; l<=k; l++){
            int j = i+l;
            if (j>n) continue;
            int delta = abs(a[i]-a[j]);
            auto it = dp[i].lower_bound(make_pair(delta,0));
            if (it==dp[i].end()) continue;
            pii val = *it;
            val.fi = delta; ++val.se;
            it = dp[j].upper_bound(make_pair(val.fi,0));
            if (it!=dp[j].end()&&val.se>=it->se) continue;
            while (it!=dp[j].begin()&&prev(it)->se>=val.se) dp[j].erase(prev(it));
            dp[j].insert(val);
        }
    }
    if (dp[n].size()){
        cout << dp[n].begin()->se << endl;
    }
    else cout << -1 << endl;
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        for (auto in:dp[i]){
//            cout << in.fi << " " << in.se << endl;
//        }
//        cout << endl;
//    }
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
