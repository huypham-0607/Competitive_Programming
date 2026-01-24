/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "pieaters"

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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;

int dp[302][302];
int cost[302][302];
int best[302][302][302];

void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int w,l,r; cin >> w >> l >> r;
        cost[l][r] = w;
    }

    for (int delta = 0; delta<n; delta++) {
        for (int i=1, j=i+delta; j<=n; i++,j++){
            for (int idx=i; idx<=j; idx++){
                if (idx!=j) best[idx][i][j] = max(best[idx][i][j],best[idx][i][j-1]);
                if (idx!=i) best[idx][i][j] = max(best[idx][i][j],best[idx][i+1][j]);
                best[idx][i][j] = max(best[idx][i][j],cost[i][j]);
            }
        }
    }

    for (int delta = 0; delta<n; delta++){
        for (int i=1, j=i+delta; j<=n; i++,j++){

            for (int mid=i; mid<j; mid++){
                dp[i][j] = max(dp[i][j],dp[i][mid] + dp[mid+1][j]);
            }

            for (int idx=i; idx<=j; idx++){
                dp[i][j] = max(dp[i][j], dp[i][idx-1]+dp[idx+1][j]+best[idx][i][j]);
            }
        }
    }

    cout << dp[1][n]<< endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".in","r")){
        freopen(TEXT".in","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

