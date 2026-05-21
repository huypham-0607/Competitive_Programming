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

const int N = 3e5+10;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];
int pref[N];
int dpp[2][2];
int dp[2][2];

void solve(){
    cin >> n;

    int res = 0;

    for (int i=1; i<=n; i++){
        char c; cin >> c;
        if (c == '(') a[i] = 1;
        else a[i] = -1;
        pref[i] = a[i] + pref[i-1];
    }

    // for (int i=1; i<=n; i++){
    //     cout << pref[i] << " ";
    // }
    // cout << endl;

    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            dp[i][j] = 0;
            dpp[i][j] = 0;
        }
    }

    for (int i=1; i<=n; i++){
        if (a[i] == 1) {
            dp[0][0] = (2*dpp[0][0] + dpp[0][1] + 1)%MD;
            dp[0][1] = dpp[0][1];
            if (pref[i] >= 2) dp[1][0] = (2*dpp[1][0] + dpp[1][1] + 1)%MD;
            else dp[1][0] = 0;
            dp[1][1] = dpp[1][1]; 
        }
        else {
            dp[0][0] = dpp[0][0];
            dp[0][1] = (2*dpp[0][1] + dpp[0][0] + 1)%MD;
            if (pref[i] >= 2) dp[1][0] = dpp[1][0];
            else dp[1][0] = 0;
            dp[1][1] = (2*dpp[1][1] + dpp[1][0] + 1)%MD;
        }

        // for (int i=0; i<2; i++){
        //     for (int j=0; j<2; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // res = (res + max(0LL, (dp[0][0] - dpp[0][0] + MD)%MD))%MD;
        // res = (res + max(0LL, (dp[1][1] - dpp[1][1] + MD)%MD))%MD;

        swap(dp,dpp);
    }
    swap(dp,dpp);

    res = res + dp[0][0];
    res = (res + dp[1][1])%MD;

    cout << res << endl;
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

