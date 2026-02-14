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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
vector<int> adj[N];
int cmpid[N];
int cmpchild[N];
int cmpcnt = 0;
int childcnt[N];
int same_cmp_check[N];
int ans[N];

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

int get_ans(int k, int t) {
    // cout << k << endl;
    if (k == 1) {
        return 1;
    }
    else {
        return 1LL*Comb::binPow(n,k-2)*t%MD;
    }
}

void dfs_mark(int u, int p) {
    cmpid[u] = cmpcnt;
    cmpchild[cmpcnt]++;
    for (auto v:adj[u]) {
        if (v==p) continue;
        dfs_mark(v,u);
    }
}

void dfs_cnt(int u, int p) {
    childcnt[u] = 1;
    for (auto v:adj[u]) {
        if (v==p) continue;
        dfs_cnt(v,u);
        childcnt[u] += childcnt[v];
    }
}

int dfs_find(int u, int p) {
    if (u == n-1) return n-1;
    for (auto v:adj[u]) {
        if (v==p) continue;
        int tmp = dfs_find(v,u);
        if (tmp) {
            if (u == n);
            return v;
        }
    }
    return 0;
}

void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        adj[i].clear();
        ans[i] = 0;
        cmpid[i] = 0;
        childcnt[i] = 0;
        cmpchild[i] = 0;
        same_cmp_check[i] = 0;
    }
    cmpcnt = 0;
    int t = 1;
    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=n; i++){
        if (!cmpid[i]) {
            ++cmpcnt;
            dfs_mark(i,0);
            t = (t*cmpchild[cmpcnt])%MD;
        }
    }

    dfs_cnt(n,0);

    if (cmpid[n-1] == cmpid[n]) {
        int node = dfs_find(n,0);
        int ans = get_ans(cmpcnt,t);
        for (int i=1; i<n; i++){
            if (i == node) {
                cout << ans << " ";
            }
            else cout << 0 << " ";
        }
        cout << endl;
    }
    else {
        for (auto v:adj[n]) {
            same_cmp_check[v] = 1;
        }
        for (int i=1; i<n; i++){
            if (cmpid[i] == cmpid[n]) {
                if (!same_cmp_check[i]) {
                    ans[i] = 0;
                    continue;
                }
                int idi = cmpid[i];
                int idn = cmpid[n];
                int tnew = t*Comb::invMod(cmpchild[idn],MD)%MD;
                tnew = tnew*(childcnt[i])%MD;

                ans[i] = get_ans(cmpcnt,tnew);
            }
            else if (cmpid[i] == cmpid[n-1]) {
                int idi = cmpid[i];
                int idn = cmpid[n];
                int tnew = t*Comb::invMod(cmpchild[idi],MD)%MD;
                tnew = tnew*Comb::invMod(cmpchild[idn],MD)%MD;
                tnew = tnew*(cmpchild[idi]+cmpchild[idn])%MD;

                ans[i] = get_ans(cmpcnt-1,tnew);
            }
            else {
                int idi = cmpid[i];
                int idn = cmpid[n];
                // cout << cmpchild[idi] << " " << cmpchild[idn] << endl;
                int tnew = t*Comb::invMod(cmpchild[idi],MD)%MD;
                tnew = tnew*Comb::invMod(cmpchild[idn],MD)%MD;
                tnew = tnew*(cmpchild[idi])%MD;
                // cout << tnew << endl;

                ans[i] = get_ans(cmpcnt-1,tnew);
            }
        }
        for (int i=1; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

