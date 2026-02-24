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

const int N = 5e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q;

vector<pair<int,pii>> query; 
vector<int> adj[N];

int _n;
vector<pii> qn[N];
vector<int> BIT;

void init(int __n) {
    _n = __n;
    BIT.resize(_n+10,0);
}

void update(int idx, int val) {
    while (idx <= _n) {
        BIT[idx] += val;
        idx += (idx&(-idx));
    }
}

void updateRange(int l, int r, int val) {
    update(l,val);
    update(r+1,-val);
}

int getVal(int idx) {
    int res = 0;
    while (idx > 0) {
        res += BIT[idx];
        idx -= (idx&(-idx));
    }
    return res;
}

int getRange(int l, int r) {
    return getVal(r) - getVal(l-1);
}

int ans[N];
int pos[N];
int tin[N], tout[N];
int timedfs = 0;

void dfs (int u, int p) {
    tin[u] = ++timedfs;

    for (auto [tme,val]:qn[u]) {
        update(tme,val);
    }
    ans[u] = getRange(pos[u],q);

    for (auto v:adj[u]) {
        if (v==p) continue;
        dfs(v,u);
    }

    for (auto [tme,val]:qn[u]) {
        update(tme,-val);
    }

    tout[u] = timedfs;
}

void solve(){
    cin >> q;
    query.clear();
    for (int i=1; i<=q; i++) {
        adj[i].clear();
        qn[i].clear();
    }
    n = 1;
    for (int i=1; i<=q; i++){
        int id; cin >> id;
        if (id == 1) {
            int x; cin >> x;
            ++n;
            query.push_back({id,{x,0}});
            adj[n].push_back(x);
            adj[x].push_back(n);
            pos[n] = i;
        }
        if (id == 2) {
            int x,val; cin >> x >> val;
            query.push_back({id,{x,val}});
            qn[x].push_back({i,val});
        }
    }

    timedfs = 0;
    init(q);
    dfs(1,0);

    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
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

