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
int n,m;
int a[25],b[25];
pair<int,int> dp[(1<<20)+10];
bool valid[(1<<20)+10];

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    a[n+1] = INF;
    for (int j=0; j<m; j++){
        cin >> b[j];
    }
    valid[0] = true;
    dp[0] = {1,0};
    for (int mask=1; mask<(1<<m); mask++){
        for (int idx=0; idx<m; idx++){
            if (mask&(1<<idx)){
                if (valid[mask^(1<<idx)]){
                    pii tmp = dp[mask^(1<<idx)];
                    tmp.se+=b[idx];
                    if (tmp.se<a[tmp.fi]){
                        valid[mask] = true;
                        dp[mask] = tmp;
                    }
                    else if (tmp.se==a[tmp.fi]){
                        valid[mask] = true;
                        dp[mask] = {tmp.fi+1,0};
                    }
                }
            }
        }
    }
    int v = false;
    for (int mask=1; mask<(1<<m); mask++){
        if (dp[mask].fi>n) v = true;
    }
    if (v) cout << "YES" << endl;
    else cout << "NO" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
