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
#define int unsigned long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k;
char a[N],b[N];
int dp[32];

void solve(){
    cin >> n >> k;
    
    int sa = 0,sb=0,sxor=0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        if (a[i] == '1') ++sa;
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
        if (b[i] == '1') ++sb;
        if (a[i]!=b[i]) ++sxor; 
    }
    int mul = 1;
    int ans = 0;
    dp[1] = sxor*(n-sxor);
    dp[2] = (sa*(n-sa)+sb*(n-sb));
    for (int i=3; i<=k; i++){
        dp[i] = dp[i-1] + 2*dp[i-2];
    }
    // for (int i=1; i<=k; i++) cout << dp[i] << " "; cout << endl;
    int pref = 0;
    for (int i=1; i<=k; i++){
        pref += dp[i];
    }
    cout << pref+(sa*(n-sa)+sb*(n-sb)) << endl;
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

