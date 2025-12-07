/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = ((unsigned long long)1 << 63);

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
ull dp[105][64];

/*Solution*/
void solve(){
    for (int i=1; i<=100; i++){
        for (int j=1; j<=63; j++){
            ull sum = 0;
            for (int k=j; k>0; k--){
                sum = sum + dp[i-1][k-1]+1;
                if (sum >= LLINF) sum = LLINF;
            }
            dp[i][j] = sum;
        }
    }
    ull n;
    int k;
    while (true){
        cin >> k >> n;
        if (k == 0) return;
        int idx;
        for (idx=0; idx<=63; idx++){
            if (dp[k][idx]>=n) break;
        }
        if (dp[k][idx]>=n) cout << idx << endl;
        else cout << "More than 63 trials needed." << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
