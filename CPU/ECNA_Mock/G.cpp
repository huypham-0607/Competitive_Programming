/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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

const int N = 30;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
int blocked[30][3];
int dp[30][8];

void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        long double tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        int x = ceil(tmp1);
        int y = ceil(tmp2);
        blocked[x][y-1] = 1;
//        cout << x << " " << y << endl;
    }
    dp[0][0] = 1;
    for (int i=1; i<=n; i++){
        for (int mask=0; mask<8; mask++){
            for (int pmask=0; pmask<8; pmask++){
                if ((1<<0)&pmask && blocked[i][0]) continue;
                if ((1<<1)&pmask && blocked[i][1]) continue;
                if ((1<<2)&pmask && blocked[i][2]) continue;
                if ((1<<0)&mask && blocked[i][0]) continue;
                if ((1<<1)&mask && blocked[i][1]) continue;
                if ((1<<2)&mask && blocked[i][2]) continue;
                bool ver = true;
                for (int idx=0; idx<3; idx++){
                    if ((1<<idx)&pmask && ((1<<idx)&mask)) ver = false;
                }

                if (ver) dp[i][mask] += dp[i-1][pmask];

                ver = true;
                if (blocked[i][0] || blocked[i][1]) ver = false;
                if ((1<<0)&mask || (1<<1)&mask) ver = false;
                if ((1<<0)&pmask || (1<<1)&pmask) ver = false;
                if ((1<<2)&pmask && (1<<2)&mask) ver = false;
                if (ver) dp[i][mask] += dp[i-1][pmask];

                ver = true;
                if (blocked[i][1] || blocked[i][2]) ver = false;
                if ((1<<1)&mask || (1<<2)&mask) ver = false;
                if ((1<<1)&pmask || (1<<2)&pmask) ver = false;
                if ((1<<0)&pmask && (1<<0)&mask) ver = false;
                if (ver) dp[i][mask] += dp[i-1][pmask];
            }
        }
    }
    cout << dp[n][0];
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

