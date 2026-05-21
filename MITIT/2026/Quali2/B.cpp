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
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

namespace Comb {
    using ll = long long;

    const int MD = 1e9+7;
    const int N = 1e5;
    const int LG = 30;

    int invFac[N+1];
    int fac[N+1];

    int binPow(int a, int b){
        ll res = 1;
        for (int lg = LG-1; lg>=0; lg--){
            res = res*res%MD;
            if ((1LL<<lg)&b) res = res*a%MD;
        }
        return res;
    }

    int invMod(int x, int MD){
        return binPow(x,MD-2);
    }

    int nCk(int n, int k){
        return 1LL*fac[n]*invFac[k]%MD*invFac[n-k]%MD;
    }

    struct Init {
        Init() {
            fac[0] = 1;
            invFac[0] = 1;
            for (int i = 1; i <= N; i++){
                fac[i] = (1LL*fac[i-1]*i%MD);
                invFac[i] = invMod(fac[i],MD);
            }
        }
    } _init;
}

int n;

int dp[N];
int sz[N];
vector<int> adj[N];

void dfs(int u, int p) {
    dp[u] = 1;
    sz[u] = 1;

    int oddcnt = 0;
    int evencnt = 0;

    for (auto v:adj[u]) {
        if (v==p) continue;
        dfs(v,u);
        sz[u] += sz[v];
        if (sz[v]%2) ++oddcnt;
        else ++evencnt;
        dp[u] = (dp[u]*dp[v])%MD;
    }

    // cout << "u: " << u << endl;
    // cout << sz[u] << " " << dp[u] << " " << oddcnt << " " << evencnt << endl;

    if (oddcnt != 0) {
        dp[u] = dp[u]*Comb::nCk(oddcnt,oddcnt/2)%MD*Comb::binPow(2,evencnt)%MD;
    }
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);

    // for (int i=1; i<=n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    cout << dp[1] << endl;
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

