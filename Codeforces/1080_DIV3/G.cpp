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
const int M = 4e5+10;
const int INF = 1e9+7;
const int LG_LCA = 18;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q;
vector<int> adj[N];
vector<pii> query[N];
vector<pii> query2[N];
int ans[M];
vector<int> order;
int tin[N], tout[N];
int sz[N];

int timedfs = 0;

void dfs(int u, int p) {
    tin[u] = timedfs++;
    sz[u] = 1;
    order.push_back(u);

    for (auto v:adj[u]) {
        dfs(v,u);
        sz[u] += sz[v];
        timedfs++;
        order.push_back(u);
    }
    tout[u] = timedfs-1;
}

int up[LG_LCA][N];
int depth[N];

void dfsLCA(int u, int p=0){
    depth[u] = depth[p]+1;
    up[0][u] = p;
    for (int lg=1; lg<LG_LCA; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        dfsLCA(v,u);
    }
}

int binLift(int u, int x){
    for (int lg=0; lg<LG_LCA; lg++){
        if ((1<<lg)&x) u = up[lg][u];
    }
    return u;
}

vector<int> pref;

int bin_search(int k) {
    int res = pref.size();
    int l = 0, r = pref.size()-1;
    while (l<=r) {
        int mid = (l+r)/2;
        int val = pref.back();
        if (mid) val = val - pref[mid-1];

        if (k >= val) {
            res = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return res;
}

void lift(int u, int p) {
    pref.push_back(tout[u] - tin[u] + 1 + ((pref.size())?pref.back():0));

    for (auto [k,id]:query[u]) {
        int pos = bin_search(k);
        int delta = pref.size()-pos;

        // cerr << u << " " << id << " " << pos << " " << delta << endl;
        // for (auto x:pref) {
        //     cerr << x << " ";
        // }
        // cerr << endl;

        if (delta < depth[u]) {
            int v = binLift(u,delta);
            int val = k - (pref.back() - ((pos)?pref[pos-1]:0));
            query2[v].push_back({val,id});
        }
    }

    for (auto v:adj[u]) {
        lift(v,u);
    }
    pref.pop_back();
}

void getAns(int u, int p) {
    for (auto [k,id]:query2[u]) {
        ans[id] = order[tin[u] + k];
    }
    
    for (auto v:adj[u]) {
        getAns(v,u);
    }
}

void solve(){
    cin >> n >> q;

    for (int i=1; i<=n; i++){
        adj[i].clear();
        query[i].clear();
        query2[i].clear();
    }
    order.clear();
    pref.clear();
    timedfs = 0;
    for (int i=1; i<=n; i++){
        int l,r; cin >> l >> r;
        if (l!=0) {
            adj[i].push_back(l);
            adj[i].push_back(r);
        }
    }
    dfs(1,0);
    dfsLCA(1,0);

    // for (int i=1; i<=n; i++){
    //     cout << tout[i] - tin[i] +1 << " ";
    // }
    // cout << endl;

    // for (int i=1; i<=n; i++){
    //     cerr << tin[i] << " " <<  tout[i]<< endl;
    // }

    for (int i=1; i<=q; i++){
        int v,k; cin >> v >> k;
        ans[i] = -1;
        query[v].push_back({k,i});
    }

    // for (int i=1; i<=q; i++) {
    //     for (auto [k,id]:query[i]){
    //         cerr << k << " " << id << " | ";
    //     }
    //     cerr << endl;
    // }

    lift(1,0);

    // for (int i=1; i<=q; i++) {
    //     for (auto [k,id]:query2[i]){
    //         cerr << k << " " << id << " | ";
    //     }
    //     cerr << endl;
    // }

    getAns(1,0);

    for (int id=1; id<=q; id++){
        cout << ans[id] << " ";
    }
    cout << endl;
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

