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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int a,b,c,x,y,z;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = '$' + s;
    vector<int> d(500, INF);
    vector<vector<int>> dp(2, vector<int> (n + 1));
    d[s[1]] = 1;
    for (int i = 2; i <= n; i++) {
        dp[0][i] = dp[0][i - 1] + 1;
        dp[1][i] = dp[1][i - 1] + 1;
        dp[1][i] = min(dp[1][i], d[s[i]]);
        d[s[i]] = min(d[s[i]], dp[0][i] + 1);
    }

    cout << min(dp[1][n], dp[0][n]) << "\n";
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
   //cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

