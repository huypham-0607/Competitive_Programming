/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 20;
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
string s;
int cnt[N+5][N+5];
int dp[(1<<N)+10];

/*Solution*/
void solve(){
    cin >> m >> n;
    cin >> s;
    for (int i=1; i<m; i++){
        int id1 = s[i-1]-'a';
        int id2 = s[i]-'a';
        if (id1 == id2) continue;
        cnt[id1][id2]++;
        cnt[id2][id1]++;
    }
    for (int mask=1; mask<(1<<n); mask++){
        int pos = __builtin_popcount(mask);
        dp[mask] = INF;
        for (int i=0; i<n; i++){
            if (!(mask&(1<<i))) continue;
            int pre = (mask^(1<<i));
            int val = dp[pre];
            for (int j=0; j<n; j++){
                if ((mask&(1<<j))){
                    val+=cnt[i][j]*pos;
                }
                else{
                    val-=cnt[i][j]*pos;
                }
            }
            dp[mask] = min(dp[mask],val);
        }
    }
    cout << dp[(1<<n)-1] << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
