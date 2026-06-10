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

int n,k;
int a[N][N];
int locked[N];

void solve(){
    cin >> n >> k;
    ffor(i,1,n) {
        ffor(j,1,n) a[i][j] = 0;
    }
    ffor(i,2,n+1) locked[i] = 0;
    ffor(idx,1,k) {
        int s; cin >> s;
        int i,j; cin >> i >> j;
        a[i][j] = 1;
        locked[i+j] = 1;
        for (int uwu=1; uwu<s; uwu++) {
            char c; cin >> c;
            if (c=='D') ++i;
            else ++j;
            a[i][j] = 1;
        }
    }
    int ans = 1;
    for (int sum=2; sum<=n+1; sum++){
        if (locked[sum]) continue;
        int prev = 0;
        int cur = 0;
        // cout << "sum: " << sum << endl;
        for (int j=1; j<sum; j++) {
            int i = sum-j;
            if (a[i][j]) {
                if (prev != cur) ans = (ans*cur)%MD;
                prev = cur = 0;
                // cout << prev << " " << cur << " " << ans << endl;
                continue;
            }
            ++cur;
            if (i!=1 && !a[i-1][j]) {
                ++prev;
                a[i-1][j] = 1;
            }
            if (j!=1 && !a[i][j-1]) {
                ++prev;
                a[i][j-1] = 1;
            }
            // cout << prev << " " << cur << " " << ans << endl;
        }
        if (prev!=cur) ans = (ans*cur)%MD;
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

