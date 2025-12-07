/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "bovinegenetics"

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7;
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
int a[N];
int dp[4][4][4];
int suggestion[4][4][4];
int pre[4][4][4];

/*Solution*/
void solve(){
    string s; cin >> s;
    n = s.size();
    for (int i=1; i<=n; i++){
        if (s[i-1] == 'A') a[i] = 0;
        if (s[i-1] == 'C') a[i] = 1;
        if (s[i-1] == 'G') a[i] = 2;
        if (s[i-1] == 'T') a[i] = 3;
        if (s[i-1] == '?') a[i] = -1;
    }
    a[0] = -1;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            suggestion[0][i][j] = 1;
        }
    }
    for (int idx=1; idx<=n; idx++){
        swap(pre,dp);
        int l = 0, r = 3;
        if (a[idx] != -1){
            l = a[idx];
            r = a[idx];
        }

        for (int id=0; id<4; id++){
            for (int i=0; i<4; i++){
                for (int j=0; j<4; j++){
                    dp[id][i][j] = 0;
                }
            }
        }

        for (int id=0; id<4; id++){
            for (int j = l; j<=r; j++){
                for (int i=0; i<4; i++){
                    dp[j][i][j] = (dp[j][i][j] + suggestion[id][i][j])%MD;
                }
            }
        }

        for (int id=0; id<4; id++){
            for (int i=0; i<4; i++){
                for (int j=0; j<4; j++){
                    suggestion[id][i][j] = 0;
                }
            }
        }

        for (int id=l; id<=r; id++){
            for (int i=0; i<4; i++){
                for (int j=0; j<4; j++){
                    dp[id][i][j] = (dp[id][i][j] + pre[0][i][j] + pre[1][i][j] + pre[2][i][j] + pre[3][i][j] - pre[id][i][j])%MD;
                }
            }
        }

        for (int id=l; id<=r; id++){
            for (int j=0; j<4; j++){
                for (int j2=0; j2<4; j2++){
                    suggestion[id][j][j2] = (suggestion[id][j][j2] + dp[id][id][j])%MD;
                }
            }
        }
    }
    int ans = 0;
    for (int id=0; id<4; id++){
        for (int i=0; i<4; i++){
            ans = (ans+suggestion[id][i][0])%MD;
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
