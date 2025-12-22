/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "743E"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
//#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MXL = 125;
const int LG = 8;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[1002];
int dp[1002][MXL+2][(1<<LG)];
vector<int> pos[LG];

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        a[i]--;
    }

    for (int i=0; i<=0; i++){
        for (int j=1; j<=MXL; j++) {
            for (int mask = 0; mask < (1<<LG); mask++) {
                if (j == 1) dp[i][j][mask] = 0;
                else if (mask == 0) dp[i][j][mask] = 0;
                else dp[i][j][mask] = -INF;
            }
        }
    }

    int ans = 0;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=MXL; j++){
            for (int mask = 0; mask < (1<<LG); mask++){
                dp[i][j][mask] = dp[i-1][j][mask];
            }
        }
        pos[a[i]].push_back(i);
        int val = a[i];
        for (int j=1; j<=min((int)pos[val].size(),MXL); j++){
            int ps = pos[val][pos[val].size()-j];
            // cout << ps << endl;
            for (int mask=0; mask<(1<<LG); mask++){
                if (mask&(1<<val)) {
                    int sub = mask^(1<<val);
                    if (dp[ps-1][j][sub]!=-INF) {
                        dp[i][j][mask] = max(dp[i][j][mask],dp[ps-1][j][sub]+j);
                    }
                    if (j!=MXL && dp[ps-1][j+1][sub]!=-INF) {
                        dp[i][j+1][mask] = max(dp[i][j+1][mask],dp[ps-1][j+1][sub]+j);
                    }
                }
            }
        }

        // for (int j=1; j<=MXL; j++){
        //     for (int mask=0; mask<(1<<LG);mask++){
        //         if (dp[i][j][mask] == -INF) cout << "-" << " ";
        //         else cout << dp[i][j][mask] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        for (int j=1; j<=MXL; j++){
            ans = max(ans,dp[i][j][(1<<LG)-1]);
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

