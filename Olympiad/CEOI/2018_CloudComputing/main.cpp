/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
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
int n;
ll dp[N];
vector<piii> v;

/*Solution*/
void solve(){
    cin >> n;
    int m = 0;
    for (int i=1; i<=n; i++){
        int c,f,val;
        cin >> c >> f >> val;
        v.push_back({f,{c,val}});
        m+=c;
    }
    cin >> n;
    for (int i=1; i<=n; i++){
        int c,f,val;
        cin >> c >> f >> val;
        v.push_back({f,{-c,val}});
    }
    sort(v.begin(),v.end(),greater<piii>());
    for (int i=1; i<=m; i++){
        dp[i] = -LLINF;
    }
    m = 0;
    for (auto in:v){
        int c = in.se.fi;
        int val = in.se.se;

        if (c>0){
            m+=c;
            for (int i=m; i>=c; i--){
                if (dp[i-c]==-LLINF) continue;
                dp[i] = max(dp[i],dp[i-c]-val);
            }
        }
        else{
            c = -c;
            for (int i=c; i<=m; i++){
                if (dp[i]==-LLINF) continue;
                dp[i-c] = max(dp[i-c],dp[i]+val);
            }
        }
//        for (int i=0; i<=m; i++){
//            if (dp[i] == -LLINF) cout << "X" << " ";
//            else cout << dp[i] << " ";
//        }
//        cout << endl;
    }
    ll ans = 0;
    for (int i=0; i<=m; i++){
        ans = max(ans,dp[i]);
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
