/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
//#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;
using ll = long long;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 1e9+7;
const int MD = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,k;
vector<int> adj[N];
int fac[N];
ll precalc[N];

namespace Comb {
    using ll = long long;

    const int MD = 1e9+7;
    const int N = 2e5;
    const int LG = 30;

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
        return 1LL*fac[n]*invMod(fac[k],MD)%MD*invMod(fac[n-k],MD)%MD;
    }

    struct Init {
        Init() {
            fac[0] = 1;
            for (int i = 1; i <= N; i++){
                fac[i] = (int)(1LL*fac[i-1]*i%MD);
            }
        }
    } _init;
}

void dfs(int u, int p=0){
    for (int i=0; i<k; i++){
        if (!p) precalc[i] = precalc[i]*(k-i)%MD;
        else precalc[i] = precalc[i]*(k-i-1)%MD;
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        dfs(v,u);
    }
}

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int u=2; u<=n; u++){
        int v; cin >> v;
        ++v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=0; i<k; i++){
        precalc[i] = 1;
    }
    dfs(1);
    ll ans = 0;
    for (int i=0; i<k; i++){
        int tmp = 1LL*precalc[i]*Comb::nCk(k,i)%MD;
        ans = (ans + tmp*((i%2)? -1 : 1) + MD)%MD;
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
