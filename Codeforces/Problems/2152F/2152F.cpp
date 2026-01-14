/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "2152F"

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

const int N = 250000+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const int LG_LCA = 18;
const long long LLINF = 1e18+3;

//Starts here

int n,delta,q;
int a[N];
int nxt[N];
vector<int> adj_suc[N];

struct LCA{
    static const int LG_LCA = 18;

    int n;
    vector<vector<int>> up;
    vector<int> depth;

    LCA (int _n, int s, vector<int> adj[]) {
        n = _n;
        up.resize(LG_LCA,vector<int>(n+10,0));
        depth.resize(n+10,0);
        dfsLCA(s,s,adj);
    }

    void dfsLCA(int u, int p, vector<int> adj[]){
        depth[u] = depth[p]+1;
        up[0][u] = p;
        for (int lg=1; lg<LG_LCA; lg++){
            int v = up[lg-1][u];
            up[lg][u] = up[lg-1][v];
        }
        for (auto v:adj[u]){
            if (v==p) continue;
            dfsLCA(v,u,adj);
        }
    }

    int binLift(int u, int x){
        for (int lg=0; lg<LG_LCA; lg++){
            if ((1<<lg)&x) u = up[lg][u];
        }
        return u;
    }

    pii getLCA(int u, int v){
        int dist = 0;
        if (depth[u]>depth[v]) swap(u,v);
        dist += depth[v]-depth[u];
        v = binLift(v,depth[v]-depth[u]);
        if (u==v) return {u,dist};
        for (int lg=LG_LCA-1; lg>=0; lg--){
            if (up[lg][u]!=up[lg][v]){
                dist += 2*(1<<lg);
                u = up[lg][u];
                v = up[lg][v];
            }
        }
        return {up[0][u],dist+2};
    }
};

int jump_nxt[N];
int jump_val[N];
int jump[LG_LCA][N];
int jump_dist[LG_LCA][N];

void solve(){
    cin >> n >> delta;
    for (int i=1; i<=n+1; i++){
        adj_suc[i].clear();
    }
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        int pos = upper_bound(a+1,a+1+n,a[i]+delta) - (a+1)+1;
        nxt[i] = max(i+1,pos);
        nxt[i] = pos;
        adj_suc[i].push_back(nxt[i]);
        adj_suc[nxt[i]].push_back(i);
    }

    LCA suc(n+1,n+1,adj_suc);

    for (int i=1; i<=n; i++){
        auto [lca,d] = suc.getLCA(i,i+1);
        jump_nxt[i] = lca;
        jump_val[i] = d;
    }
    jump_nxt[n+1] = n+1;

    // for (int i=1; i<=n+1; i++){
        // cout << jump_nxt[i] << " ";
    // }
    // cout << endl;

    for (int i=n+1; i>0; i--){
        jump[0][i] = jump_nxt[i];
        jump_dist[0][i] = jump_val[i];
        for (int lg=1; lg<LG_LCA; lg++){
            int j = jump[lg-1][i];
            jump[lg][i] = jump[lg-1][j];
            jump_dist[lg][i] = jump_dist[lg-1][i] + jump_dist[lg-1][j];
        }
    }

    cin >> q;
    while (q--){
        int l,r; cin >> l >> r;
        int sum = 0;
        int u = l;
        for (int lg=LG_LCA-1; lg>=0; lg--){
            int v = jump[lg][u];
            if (v <= r) {
                sum += jump_dist[lg][u];
                u = v;
            }
        }

        // cout << u << " " << sum << endl;

        if (u<r) {
            int cur = u;
            for (int lg=LG_LCA-1; lg>=0; lg--){
                int par = suc.up[lg][cur];
                if (par <= r) {
                    sum += (1<<lg);
                    cur = par;
                }
            }
            sum++;

            cur = u+1;
            for (int lg=LG_LCA-1; lg>=0; lg--){
                int par = suc.up[lg][cur];
                if (par <= r) {
                    sum += (1<<lg);
                    cur = par;
                }
            }
            sum++;
        } else {
            sum++;
        }
        cout << sum << endl;
    }
}

/*Driver Code*/
signed main(){
    // cin.tie(0) -> sync_with_stdio(0);
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

