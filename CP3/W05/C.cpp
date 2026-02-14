/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

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

const int N = 1001;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k;
int dp[N][2*N][2];

void solve(){
    cin >> n >> k;
    dp[1][1][0] = 1;
    dp[1][2][1] = 1;
    for (int i=2; i<=n; i++){
        for (int j=1; j<=2*n; j++){
            dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][0])%MD;
            if (j-1 > 0) dp[i][j][0] = (dp[i][j][0] + dp[i-1][j-1][0])%MD;
            dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][1]*2)%MD;

            dp[i][j][1] = (dp[i][j][1] + dp[i-1][j][1])%MD;
            if (j-2 > 0) dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-2][1])%MD;
            if (j-1 > 0) dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-1][0]*2)%MD;
            // cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
    }

    cout << (dp[n][k][0] + dp[n][k][1])%MD*2%MD << endl;
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

