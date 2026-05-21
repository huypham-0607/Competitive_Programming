/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
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

const int N = 5010;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int dp[N][N];
int a[N];

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    a[0] = 0;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dp[i][j] = LLINF;
        }
    }
    for (int i=1; i<=n; i++){
        dp[0][i] = LLINF;
    }
    dp[0][0] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=min(n,a[i]); j++){
            dp[i][j] = LLINF;
            if (j > a[i-1]) {
                dp[i][j] = min(dp[i][j], dp[i-1][a[i-1]] + (j-a[i-1]) + ((j == a[i]) ? 0 : 1));
            }
            else {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + ((j == a[i]) ? 0 : 1));
            }
        }
            for (int j=min(n,a[i])-1; j>=0; j--){
                dp[i][j] = min(dp[i][j],dp[i][j+1]);
            }
    }
    cout << dp[n][0] << endl;
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

