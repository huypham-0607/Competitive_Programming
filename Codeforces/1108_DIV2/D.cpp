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

const int N = 1e5+10;
const int INF = 1e9+7;
const int LG = 18;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];
int dp[LG][N];

int calc_val(int x, int lg){
    int mask = (1<<lg)-1;
    int res = 0;

    int cmp = (1<<lg)-(x&mask);
    if (cmp == (1<<lg)) cmp = 0;
    res += cmp;

    // cout << x << " " << lg << " " << res << " ";

    int red = x+cmp;
    res += ((red == 0)?0:63-__builtin_clzll(red)+__builtin_popcountll(red));
    // cout << res << endl;
    return res;
}

void solve(){
    cin >> n;
    ffor(i,1,n) cin >> a[i];
    ffor(i,1,n){
        int val = INF;    
        rfor(lg,LG-1,0){
            val = min(val,calc_val(a[i],lg));
            dp[lg][i] = dp[lg][i-1] + val;
        }
    }
    // ffor(i,1,n){
    //     frep(lg,0,6){
    //         cout << calc_val(a[i],lg) << " ";
    //     }
    //     cout << endl;
    // }
    int ans = INF;
    frep(i,0,LG){
        int tmp = dp[i][n]-i*(n-1);
        ans = min(ans,tmp);
        // cout << i << " " << tmp << endl;
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

