/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "2124F1"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 102;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
/*
    dp[i][j][state][k] : Number of ways to reach the array of status:
    - Has length of i
    - The i-th character is j
    - State == 0: We are appending suffix
    - State == 1: We are appending prefix
    - if state == 0, k denotes the first character of that suffix;
    - if state == 1, k denotes the last character of that prefix;
*/
int dp[N][N][2][N];

int allowed[N][N];

void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            allowed[i][j] = 1;
        }
    }
    for (int i=1; i<=m; i++){
        int pos,x; cin >> pos >> x;
        allowed[pos][x] = 0;
    }

    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=n; j++){
    //         cout << allowed[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            for (int state=0; state<2; state++){
                for (int k=1; k<=n; k++){
                    dp[i][j][state][k] = 0;
                }
            }
        }
    }

    for (int i=1; i<=n; i++){
        for (int val=1; val<=n; val++){
            if (!allowed[i][val]) continue;
            for (int state = 0; state < 2; state++){
                for (int k=1; k<=n; k++){
                    if (state == 0) {
                        dp[i][val][state][k] = (dp[i][val][state][k] + dp[i-1][val-1][state][k])%MD;
                    }
                    else {
                        if (k < val) continue;
                        dp[i][val][state][k] = (dp[i][val][state][k] + dp[i-1][val-1][state][k])%MD;
                    }
                }
            }
        }

        int startcnt = 0;
        if (i==1) ++startcnt;
        for (int val=1; val<=n; val++) {
            startcnt = (startcnt + dp[i-1][val][0][1])%MD;
            startcnt = (startcnt + dp[i-1][val][1][val])%MD;
        }

        if (allowed[i][1]) {
            for (int k=1; k<n; k++){
                for (int val = k+1; val <= n; val++){
                    dp[i][1][1][k] = (dp[i][1][1][k] + dp[i-1][val][0][k+1])%MD;
                }
            }
        }

        for (int val=1; val<=n; val++){
            if (!allowed[i][val]) continue;
            dp[i][val][0][val] = (dp[i][val][0][val] + startcnt)%MD;
            dp[i][val][0][val] = (dp[i][val][0][val] - dp[i-1][val-1][0][1]+MD)%MD;
        }
    }

    for (int i=1; i<=n; i++){
        for (int val = 1; val<=n; val++){
            // cout << "i,val: " << i << " " << val << endl;
            for (int state=0; state<2; state++) {
                // cout << "State = " << state << ": ";
                for (int k=1; k<=n; k++) {
                    // cout << dp[i][val][state][k] << " ";
                }
                // cout << endl;
            }
        }
    }

    int ans = 0;
    for (int val=1; val<=n; val++) {
        ans = (ans + dp[n][val][0][1])%MD;
        ans = (ans + dp[n][val][1][val])%MD;
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

