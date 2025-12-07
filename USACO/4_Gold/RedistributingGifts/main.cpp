/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
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

const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 18;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q;
bool adj[LG][LG];
int dp[LG][1<<LG];

int getmsb(int mask) {
    if (mask == 0) return -1;
    return (63-__builtin_clzll(mask));
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++) {
        bool valid = true;
        for (int idx=1; idx<=n; idx++){
            int x; cin >> x;
            if (valid) adj[i-1][x-1] = true;
            if (x==i) valid = false;
        }
    }

//    for (int i=0; i<n; i++) {
//        for (int j=0; j<n; j++) {
//            cout << adj[i][j] << " ";
//        }
//        cout << endl;
//    }

    for (int mask=1; mask<(1<<n); mask++) {
        int cnt = __builtin_popcountll(mask);
        int msb = getmsb(mask);
        for (int x = 0; x < n; x++) {
            dp[x][mask] = 0;
            if (mask&(1<<x) && x!=msb) continue;
            if (cnt == 1) {
                if (adj[msb][x]) dp[x][mask] = 1;
                continue;
            }
            for (int idx = 0; idx < n; idx++) {
                if (!(mask&(1<<idx))) continue;
                int smask = mask^(1<<idx);
                if (idx == msb) {
                    if (adj[idx][x]) dp[x][mask] += dp[getmsb(smask)][smask];
                }
                else {
                    if (adj[idx][x]) dp[x][mask] += dp[idx][smask];
                }
            }
        }
    }

    cin >> q;

    for (int i=1; i<=q; i++) {
        int mask1=0, mask2=0;
        for (int idx = 0; idx<n; idx++){
            char c; cin >> c;
            if (c == 'H') mask1^=(1<<idx);
            if (c == 'G') mask2^=(1<<idx);
        }
        if (mask2>mask1) swap(mask1,mask2);
        int res1 = dp[getmsb(mask1)][mask1];
        int res2;
//        cout << mask1 << " " << mask2 << " " << getmsb(mask2) << endl;
        if (getmsb(mask2) == -1){
            res2 = 1;
        }
        else res2 = dp[getmsb(mask2)][mask2];
        cout << res1*res2 << endl;
    }
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
