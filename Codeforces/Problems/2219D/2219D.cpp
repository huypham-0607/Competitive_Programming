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
const int LG = 18;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int perm[N];
int inv_perm[N];
vector<int> adj[N];
set<int> st;
int cnt[N];
int best[N]; // Hypothetical mex when all ancestor of u occupies [0,perm[u])
int jump[LG][N];
int dist[LG][N];

// For each op, transform into adding an additional number mex[u], but hard cap values of subtree to perm[u];

int timedfs = 0;
int tin[N],tout[N];

void elt(int u, int p){
    cnt[u] = 1;
    tin[u] = ++timedfs;
    for (auto v:adj[u]){
        if (v==p) continue;
        elt(v,u);
        cnt[u] += cnt[v];
    }
    tout[u] = timedfs;
}

void compute(int u, int p) {
    st.erase(perm[u]);

    for (auto v:adj[u]) {
        if (v==p) continue;
        compute(v,u);
    }

    best[u] = (*st.lower_bound(perm[u]));
    int nxt = inv_perm[best[u]];
    if (tin[nxt] < tin[u] || tout[u] < tin[nxt]) nxt = 0;

    jump[0][u] = nxt;
    dist[0][u] = cnt[nxt] * (best[nxt] - best[u]);

    for (int lg=1; lg<LG; lg++){
        int v = jump[lg-1][u];
        jump[lg][u] = jump[lg-1][v];
        dist[lg][u] = dist[lg-1][u] + dist[lg-1][v];
    }

    st.insert(perm[u]);
}

int mex_sum[N];
int ans;

void compute_mex_sum(int u, int p){
    st.erase(perm[u]);
    mex_sum[u] = (*st.begin());

    for (auto v:adj[u]){
        if (v==p) continue;
        compute_mex_sum(v,u);
        mex_sum[u] += mex_sum[v];
    }

    st.insert(perm[u]);
}

void get(int u, int p){
    st.erase(perm[u]);
    int mex = (*st.begin());
    int mex_new = (*(++st.begin()));
    int cap = perm[u];

    if (mex_new <= cap) {
        // cout << "mex_new lower than cap: " << u << endl;
        int cur_ans = mex_sum[1] - mex_sum[u] + (mex_new)*cnt[u];

        int nxt = inv_perm[mex_new];
        if (tin[nxt] < tin[u] || tout[u] < tin[nxt]) nxt = 0;

        if (best[nxt] > cap) {
            cur_ans += cnt[nxt] * (cap - (mex_new));
            ans = max(ans,cur_ans);
            // cout << "final mex (low cap): " << cur_ans << endl;
        }
        else {
            cur_ans += cnt[nxt] * (best[nxt] - (mex_new)); 
            for (int lg=LG-1; lg>=0; lg--){
                int v = jump[lg][nxt];
                if (best[v] <= cap) {
                    cur_ans += dist[lg][nxt];
                    nxt = v;
                }
            }
            cur_ans += cnt[jump[0][nxt]] * (cap - best[nxt]);
            ans = max(ans,cur_ans);
            // cout << "final mex (high cap): " << cur_ans << endl;
        }
    }
    else {
        // cout << "mex_new greater than cap: " << u << endl;
        int cur_ans = mex_sum[1] - mex_sum[u] + (cap)*cnt[u];
        // cout << "final mex (flat): " << cur_ans << endl;
        ans = max(ans,cur_ans);
    }

    for (auto v:adj[u]){
        if (v==p) continue;
        get(v,u);
    }

    st.insert(perm[u]);
}

void solve(){
    cin >> n;

    st.clear();
    best[0] = INF;
    timedfs = 0;
    ffor(i,1,n) adj[i].clear();
    ffor(i,0,n+1) inv_perm[i] = 0;
    ffor(i,1,n) {
        cin >> perm[i];
        inv_perm[perm[i]] = i;
    }
    ffor(i,1,n-1){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ffor(i,0,n+1) st.insert(i);
    elt(1,0);
    compute_mex_sum(1,0);
    compute(1,0);
    ans = mex_sum[1];
    // ffor(i,1,n) cout << mex_sum[i] << " "; cout << endl;
    get(1,0);
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

