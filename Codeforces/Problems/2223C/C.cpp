/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>
#include <unordered_map>

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

const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

// struct Hash {
//     size_t seed;
    
//     explicit Hash(size_t _seed): seed(_seed) {};

//     size_t operator()(const int key) const {

//     }
// }

int n,q;
vector<pii> adj[N];
vector<int> nen;
vector<pair<int,pii>> dest;
int par[N]; int wei[N];
int pref[N];
int par2[N];

void DFS(int u, int p, int cur_t, int org_t, int divisor, int wai){
    par2[u] = p;
    pref[u] += pref[p] + wai;
    if (adj[u].size() == 0) {
        // cerr << "pushed: " << divisor << " " << org_t << " " << u << endl;
        // dest.push_back({divisor,{org_t,u}});
        // nen.push_back(divisor);
        return;
    }
    int mul = adj[u].size();
    int gcd = __gcd<ll>(divisor,mul);
    int iter = ((divisor == LLINF)? 1 : mul/__gcd<ll>(divisor,mul));
    int ndivisor = (divisor/gcd > LLINF/mul) ? LLINF : divisor/gcd*mul;
    cerr << "u: " <<  u << " " << cur_t << " " << org_t << " " << divisor << " " << iter << endl;



    for (int i=0; i<adj[u].size(); i++){
        auto [v,w] = adj[u][cur_t%adj[u].size()];
        // cerr << i << " " << org_t << " " << cur_t << " " << v << " " << w << endl;

        if (iter == 1) {
            
            DFS(v,par2[u],cur_t+w,org_t,ndivisor,w);
            par2[u] = -1;
        }
        else {
            DFS(v,u,cur_t+w,org_t,ndivisor,w);
        }

        if (org_t>LLINF-divisor) break;
        org_t += divisor;
        cur_t += divisor;
    }
}

int timestamp[N];
int ans[N];

void Query(int u, int p, int pos, int cur_t) {
    cout << u << " " << cur_t << " " << pref[u] << endl;
    if (adj[u].size() == 0) {
        ans[pos] = u;
        return;
    }
    auto [v,w] = adj[u][(cur_t+pref[u])%adj[u].size()];
    Query(v,u,pos,cur_t);
}

void solve(){
    cin >> n >> q;
    ffor(i,1,n) adj[i].clear();
    nen.clear(); dest.clear();
    ffor(i,1,q) ans[i] = 0;
    ffor(i,2,n){
        cin >> par[i];
    }
    ffor(i,2,n) {
        cin >> wei[i];
        adj[par[i]].push_back({i,wei[i]});
    }

    ffor(i,1,n) par2[i] = -1;
    // cerr << "Passed input!" << endl;
    DFS(1,0,0,0,1,0);
    // cerr << "Passed DFS!" << endl;

    ffor(i,1,n) adj[i].clear();
    int root = 0;
    ffor(i,1,n) {
        if (par2[i] == -1) continue;
        if (par2[i] == 0) root = i;
        else {
            adj[par2[i]].push_back({i,wei[i]});
        }
    }

    ffor(i,1,n){
        for(auto in:adj[i]){
            cout << in.fi << " ";
        }
        cout << endl;
    }
    ffor(i,1,n){
        cout << par2[i] << " ";
    }
    cout << endl;

    ffor(i,1,q) {
        cin >> timestamp[i];
        Query(root,0,i,timestamp[i]);
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

