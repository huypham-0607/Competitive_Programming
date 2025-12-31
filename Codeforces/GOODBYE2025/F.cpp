/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "F"

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
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

namespace Comb {
    using ll = long long;

    const int MD = 998244353;
    const int N = 2e5;
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


int n,cnt;
int pre[N],suf[N];
int sz[N];
int val[N];
vector<int> adj[N];

void DFScolor(int u, int p) {
    sz[u] = 1;
    for (auto v:adj[u]) {
        if (v==p) continue;
        DFScolor(v,u);
        sz[u] += sz[v];
    }
}

void DFScomp(int u, int p) {
    val[u] = 1;
    for (auto v:adj[u]) {
        if (v==p) continue;
        DFScomp(v,u);
    }
    if (u == 1 || sz[u]%2 == 0) {
        if (u!=1) {
            ++cnt;
            pre[cnt] = val[u];
            suf[cnt] = val[u];
        }
    } else {
        val[p] += val[u];
    }
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    cnt = 0;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFScolor(1,0);
    DFScomp(1,0);

    if (cnt == 0) {
        cout << 1 << endl;
        return;
    }

    pre[0] = 1;
    suf[cnt+1] = 1;
    for (int i=1; i<=cnt; i++){
        // cout << pre[i] << " ";
        pre[i] = (pre[i-1]*pre[i])%MD;
    }
    for (int i=cnt; i>0; i--) {
        suf[i] = (suf[i+1]*suf[i])%MD;
    }
    // cout << endl;
    // for (int i=1; i<=cnt; i++){
    //     cout << pre[i] << " " << suf[i] << endl;
    // }
    // cout << val[1] << " " << Comb::fac[cnt-1] << endl;

    int ans = 0;
    for (int i=1; i<=cnt; i++){
        ans = (ans + 
            (val[1]*pre[cnt]%MD
            *pre[i-1]%MD
            *suf[i+1]%MD
            *Comb::fac[cnt-1])
            )%MD;
    }
    cout << ans << endl;
    // cout << endl;

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
