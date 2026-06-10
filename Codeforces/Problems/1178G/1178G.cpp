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
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int BLOCK = 180;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q;
vector<int> adj[N];
ll _a[N],_b[N];
ll a[N],b[N];
vector<pair<int,pii>> query;
int tin[N],tout[N];
int timedfs = 0;

void dfs(int u, int p) {
    a[tin[u]] += _a[u];
    b[tin[u]] += _b[u];
    for (auto v:adj[u]){
        if (v==p) continue;
        tin[v] = ++timedfs;
        b[tin[v]] += b[tin[u]];
        a[tin[v]] += a[tin[u]];
        dfs(v,u);
    }
    b[tin[u]] = abs(b[tin[u]]);
    a[tin[u]] = a[tin[u]]*b[tin[u]];
    tout[u] = timedfs;
}

int b_sz;

int get_idx(int i) {
    return i/b_sz;
}

//CHT

struct Line{
    ll m,n;

    Line(ll _m, ll _n) : m(_m), n(_n) {};

    int operator() (const ll& x) {return m*x+n;};

    friend ld intersect(Line a, Line b) {
        return ((ld)(b.n-a.n))/(a.m-b.m);
    }
};

vector<pii> rnk[N/BLOCK+10];
ll var[N/BLOCK+10];
int pos[N/BLOCK+10];
vector<Line> CHT[N/BLOCK+10];

void update_qpoint(int id, int delta) {
    var[id] += delta;
    while (pos[id]+1 != CHT[id].size() && intersect(CHT[id][pos[id]],CHT[id][pos[id]+1]) < var[id]) ++pos[id];
}

void reset_cht(int id) {
    CHT[id].clear();
    for (auto [i,par]:rnk[id]) {
        Line line(par*b[i],par*a[i]);
        
        while (!CHT[id].empty() && CHT[id].back().m == line.m && CHT[id].back().n < line.n) {
            CHT[id].pop_back();
        }
        if (!CHT[id].empty() && CHT[id].back().m == line.m) continue;
        
        while (CHT[id].size() > 1 && intersect(CHT[id].back(),line) < intersect(CHT[id].back(),CHT[id][CHT[id].size()-2])) {
            CHT[id].pop_back();
        }
        CHT[id].push_back(line);
    }

    pos[id] = 0;
    update_qpoint(id,0);
}

ll get_cht_max(int id) {
    return CHT[id][pos[id]].m*var[id] + CHT[id][pos[id]].n;
}

void solve(){
    cin >> n >> q;
    for (int u=2; u<=n; u++){
        int v; cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        cin >> _a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> _b[i];
    }
    for (int i=1; i<=q; i++){
        int id,u,val=0; cin >> id >> u;
        if (id == 1) cin >> val;
        query.push_back({id,{u,val}});
    }
    tin[1] = 0;
    dfs(1,0);
    // for (int u=1; u<=n; u++){
    //     cout << tin[u] << " " << tout[u] << endl;
    // }
    // for (int i=0; i<n; i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    // frep(i,0,n) cout << a[i]/b[i] << " "; cout << endl;
    b_sz = min((int)ceil(sqrt(n)),BLOCK);
    // cerr << b_sz << endl;
    for (int b_id=0; b_id*(b_sz)<n; b_id++){
        // cout << "b_id: " << b_id << endl;
        for (int i=b_id*b_sz; i<min((b_id+1)*b_sz,n); i++) {
            rnk[b_id].push_back({i,-1});
            rnk[b_id].push_back({i,1});
        }
        sort(all(rnk[b_id]), [&](pii x, pii y) {return (ll)b[x.fi]*x.se < (ll)b[y.fi]*y.se;});
        // for (auto [val,par]:rnk[b_id]) {
        //     cout << val << " " << b[val] << " " << par << endl;
        // }
        var[b_id] = 0;
        reset_cht(b_id);
    }
    
    for (auto [id,in]:query) {
        auto [u,val] = in;
        int l = tin[u], r = tout[u];
        if (id == 1) {
            if (get_idx(l)==get_idx(r)) {
                for (int i=l; i<=r; i++){
                    a[i] += (ll)val*b[i];
                }
                reset_cht(get_idx(l));
            }
            else {
                if (l != get_idx(l)*b_sz) {
                    for (int i=l; i<(get_idx(l)+1)*b_sz; i++) {
                        a[i] += (ll)val*b[i];
                    }
                    reset_cht(get_idx(l));
                    l = (get_idx(l)+1)*b_sz;
                }
                if (r != (get_idx(r)+1)*b_sz-1) {
                    for (int i=r; i>=get_idx(r)*b_sz; i--) {
                        a[i] += (ll)val*b[i];
                    }
                    reset_cht(get_idx(r));
                    r = get_idx(r)*b_sz - 1;
                }

                for (int b_id = get_idx(l); b_id <=get_idx(r); b_id++){
                    update_qpoint(b_id,val);
                }
            }
        }
        else {
            ll ans = -LLINF;
            if (get_idx(l)==get_idx(r)){
                for (int i=l; i<=r; i++){
                    ans = max(ans,var[get_idx(i)]*b[i] + a[i]);
                    ans = max(ans,-(var[get_idx(i)]*b[i] + a[i]));
                }
            }
            else {
                for (int i=l; i<(get_idx(l)+1)*b_sz; i++) {
                    ans = max(ans,var[get_idx(i)]*b[i] + a[i]);
                    ans = max(ans,-(var[get_idx(i)]*b[i] + a[i]));
                }
                for (int i=r; i>=get_idx(r)*b_sz; i--) {
                    ans = max(ans,var[get_idx(i)]*b[i] + a[i]);
                    ans = max(ans,-(var[get_idx(i)]*b[i] + a[i]));
                }
                for (int b_id = get_idx(l)+1; b_id < get_idx(r); b_id++){
                    ans = max(ans,get_cht_max(b_id));
                }
            }
            cout << ans << endl;
        }
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}