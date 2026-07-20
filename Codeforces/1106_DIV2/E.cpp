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

const int N = 510;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];
vector<vector<int>> dp, dpp;

void solve(){
    cin >> n;
    string s; cin >> s;
    for (int i=1; i<=n; i++){
        if (s[i-1] == 'T') a[i] = -1;
        if (s[i-1] == 'F') a[i] = 1;
        if (s[i-1] == 'N') a[i] = 0;
    }
    dp.clear(), dpp.clear();
    dp.resize(n+1,vector<int>(n+1,-INF));
    dpp.resize(n+1,vector<int>(n+1,-INF));
    dp[0][0] = 0;
    for (int idx=1; idx<=n; idx++){
        swap(dp,dpp);
        ffor(i,0,n){
            ffor(j,0,n) dp[i][j] = -INF;
        }
        if (a[idx]>=0) {
            for (int i=0; i<=n; i++){
                for (int j=0; j<=n; j++){
                    int v = j+1;
                    int u = max(i,j+1);
                    if (u>n || v>n) continue;
                    dp[u][v] = max(dp[u][v], dpp[i][j]+1);
                }
            }
        }
        if (a[idx]<=0) {
            ffor (i,0,n) {
                ffor(j,0,n) {
                    int v = max(0LL,j-1);
                    int u = i;
                    dp[u][v] = max(dp[u][v],dpp[i][j]);
                }
            }
        }
        // ffor(i,0,n) {
        //     ffor(j,0,n) {
        //         cout << ((dp[i][j]<0)?-1:dp[i][j]) << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    int ans = 0;
    ffor(i,0,n) {
        ffor (j,0,n) {
            ans = max(ans,dp[i][j]-i);
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

