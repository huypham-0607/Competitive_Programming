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

const int N = 1e5+10;
const int GR = 512;
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

int gauss (vector < vector<int> > a, vector<int> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i) {
            if (a[i][col] != 0) {
                for (int j=col; j<=m; ++j){
                    swap (a[i][j], a[row][j]);
                }
                break;
            }
        }
        if (a[row][col] == 0) {
            continue;
        }
        where[col] = row;

        for (int i=0; i<n; ++i) {
            if (i != row) {
                int c = (a[i][col]*Comb::invMod(a[row][col],MD))%MD;
                for (int j=col; j<=m; ++j) {
                    a[i][j] = (a[i][j] - (a[row][j] * c)%MD + MD)%MD;
                }
            }
        }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i) {
        if (where[i] != -1) {
            ans[i] = (a[where[i]][m]*Comb::invMod(a[where[i]][i],MD))%MD;
        } 
    }
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j) {
            sum = (sum + (ans[j] * a[i][j])%MD)%MD;
        }
        if ((sum - a[i][m] + MD)%MD != 0) {
            return 0;
        }
    }

    for (int i=0; i<m; ++i) {
        if (where[i] == -1) {
            return INF;
        }
    }
    return 1;
}

int n,m;
int deg[N];
int grundy[N];
vector<int> reach[N];
vector<int> adj[N];
int cnt[GR];
vector<vector<int>> mat(GR,vector<int>(GR+1,0));
vector<int> ans(GR,0);

void solve(){
    cin >> n  >> m;
    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        adj[v].push_back(u);
        deg[u]++;
    }

    queue<int> q;
    for (int i=1; i<=n; i++){
        if (deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        sort(all(reach[u]));
        reach[u].resize(unique(all(reach[u])) - reach[u].begin());
        for (int idx=0; idx<reach[u].size(); idx++){
            if (reach[u][idx] == idx) ++grundy[u];
        }

        for (auto v:adj[u]) {
            deg[v]--;
            reach[v].push_back(grundy[u]);
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i=1; i<=n; i++){
        cnt[grundy[i]]++;
    }

    // for (int i=0; i<10; i++) {
    //     cout << cnt[i] << endl;
    // }

    int marisa = Comb::invMod(n+1,MD);

    for (int i=0; i<GR; i++){
        for (int j=0; j<GR; j++){
            mat[i][j] = (cnt[j^i]*marisa)%MD;
            if (i == j) mat[i][j] = (mat[i][j] - 1 + MD)%MD;
        }
        if (i != 0) mat[i][GR] = (-marisa+MD)%MD;
        else mat[i][GR] = 0;
    }

    // for (int i=0; i<3; i++){
    //     for (int j=0; j<3; j++){
    //         cout << mat[i][j]*(n+1)%MD << " ";
    //     }
    //     cout << mat[i][GR]*(n+1)%MD << endl;
    // }

    int tmp = gauss(mat, ans);
    // cout << tmp << endl << endl;
    // cout << 5 * Comb::invMod(23, MD) % MD << endl;

    // cout << ans[0] << endl << endl;
    // for (int i=0; i<GR; i++) {
    //     ans[i] = ans[i]*Comb::invMod(n+1,MD)%MD;
    // }
    // for (int i=0; i<10; i++){ 
    //     cout << ans[i] << endl;
    // }
    cout << (ans[0])%MD << endl;
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

