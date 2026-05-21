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
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];
int nxt[N];
int dp[N];

void solve(){
    cin >> n;
    for (int i=1; i<=n+1; i++) {
        nxt[i] = 0;
        dp[i] = 0;
    }
    long long ans = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        // ans += a[i]*i*(n-i+1);
    }

    for (int i=n; i>0; i--) {
        dp[i] = dp[i+1] + (n-i+1);
        nxt[i] = i+1;
        while (nxt[i] != n+1 && a[nxt[i]] == a[i]+1) {
            dp[i] -= (n-nxt[i]+1);
            nxt[i] = nxt[nxt[i]];
        }
        ans += dp[i];
    }

    // for (int i=1; i<=n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
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

