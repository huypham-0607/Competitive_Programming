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
typedef pair<pii, pii> piiii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2010;
const int INF = 1e9+7;
const int LG = 20;
const int MD1 = 1e9+7;
const int MD2 = 998244353;
const int MD3 = 999999937;
const long long LLINF = 1e18+3;

int n;
int pow1[N],pow2[N],pow3[N];


int binPow(int a, int b, int MD){
    ll res = 1;
    for (int lg = LG-1; lg>=0; lg--){
        res = res*res%MD;
        if ((1LL<<lg)&b) res = res*a%MD;
    }
    return res;
}

vector<piiii> nen;
piiii hsh;
vector<int> adj[N];
char val[N];

void add_hash(char c, int deg) {
    int idx = (('0' <= c && c <= '9') ? c-'0' : 10+c-'a');
    // cout << idx << endl;
    hsh.fi.fi = (hsh.fi.fi + idx*pow1[deg]%MD1)%MD1;
    hsh.fi.se = (hsh.fi.se + idx*pow2[deg]%MD2)%MD2;
    hsh.se.fi = (hsh.se.fi + idx*pow3[deg]%MD3)%MD3;
    hsh.se.se++;
}

void del_hash(char c, int deg) {
    int idx = (('0' <= c && c <= '9') ? c-'0' : 10+c-'a');
    hsh.fi.fi = (hsh.fi.fi - idx*pow1[deg]%MD1 + MD1)%MD1;
    hsh.fi.se = (hsh.fi.se - idx*pow2[deg]%MD2 + MD2)%MD2;
    hsh.se.fi = (hsh.se.fi - idx*pow3[deg]%MD3 + MD3)%MD3;
    hsh.se.se--;
}

void DFS(int u, int p, int deg) {
    // cout << u << endl;
    add_hash(val[u],deg);
    nen.push_back(hsh);

    for (auto v:adj[u]) {
        if (v==p) continue;
        DFS(v,u,deg+1);
    }

    del_hash(val[u],deg);
}

void solve(){
    cin >> n;
    for (int i=0; i<=n; i++){
        pow1[i] = binPow(16,i,MD1);
        pow2[i] = binPow(16,i,MD2);
        pow3[i] = binPow(16,i,MD3);
    }
    hsh = {{0,0},{0,0}};
    for (int i=1; i<=n; i++){
        cin >> val[i];
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        // cout << "start: " << i << endl;
        // cout << hsh.fi.fi << " " << hsh.fi.se << " " << hsh.se.fi << endl;
        DFS(i,0,0);
    }

    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());
    // for (int i=0; i<nen.size(); i++){
    //     cout << nen[i].fi.fi << " " << nen[i].fi.se << " " << nen[i].se.fi << endl;
    // }
    cout << nen.size() << endl;
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

