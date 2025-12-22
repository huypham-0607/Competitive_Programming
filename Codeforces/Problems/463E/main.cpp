/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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
const int INF = 1e9+7;
const int MXVAL = 2e6;
const int MXP = 1414;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q;
int a[N];
vector<int> adj[N];
vector<int> primes;
vector<int> save[MXVAL+10];
int ans[N];
int depth[N];

void Sieve(){
    bitset<MXP+1> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i*i<=MXP; i++){
        if (!bs[i]) continue;
        for (int j=i*i; j<=MXP; j+=i){
            bs[j]=0;
        }
    }

    for (int i=1; i<=MXP; i++){
        if (bs[i]) primes.push_back(i);
    }
}

vector<int> fact[N];

void getFact(int x) {
    fact[x].clear();

    int val = a[x];
    for (auto p:primes) {
        if (val%p == 0){
            fact[x].push_back(p);
            while (val%p == 0) val/=p;
        }
    }
//    cout << "meow" << endl;
    if (val!=1) fact[x].push_back(val);
//    cout << "meow" << endl;
}

void getDepth(int u, int p){
    if (u==1) depth[u] = 1;
    else depth[u] = depth[p]+1;
    for (auto v:adj[u]){
        if (v==p) continue;
        getDepth(v,u);
    }
}

void DFS(int u, int p){
    ans[u] = 0;
    for (auto p:fact[u]) {
        if (save[p].size()!=0 && depth[save[p].back()] > depth[ans[u]]) ans[u] = save[p].back();
        save[p].push_back(u);
    }

    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u);
    }
    for (auto p:fact[u]) {
        save[p].pop_back();
    }
}

void solve(){
    Sieve();
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        getFact(i);
//        for (auto x:fact[i]) cout << x << " ";
//        cout << endl;
    }
//    cout << "Meow" << endl;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[0] = 0;
    getDepth(1,0);

//    cout << primes.size() << endl;
//    for (int i=0; i<10; i++){
//        cout << primes[i] << endl;
//    }

    DFS(1,0);
    while (q--) {
        int id,u,w; cin >> id >> u;
        if (id == 2) cin >> w;
        if (id == 1) {
            if (ans[u] == 0) cout << -1 << endl;
            else cout << ans[u] << endl;
        }
        else {
            a[u] = w;
            getFact(u);
            DFS(1,0);
        }
    }
}

/*Driver Code*/
signed main(){
//    cin.tie(0) -> sync_with_stdio(0);
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
