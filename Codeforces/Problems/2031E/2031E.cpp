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

const int N = 1e6+10;
const int INF = 1e9+7;
const int LG = 20;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
vector<int> adj[N];
int f[N];


void calcf(int u, int p) {
    f[u] = 0;
    
    vector<int> val;
    for (auto v:adj[u]) {
        if (v==p) continue;
        calcf(v,u);
        val.push_back(f[v]);
    }
    // cout << "Node: " << u << endl;
    sort(all(val));
    if (!val.size()){
        f[u] = 0;
        return;
    }
    else if (val.size() == 1) {
        f[u] = val[0] + 1;
        return;
    }
    int a = 0, b = 0;
    for (auto x:val) {
        // cout << x << " ";
        if (a) a = ((a-1)>>min(30LL,x-b)) + 1;
        b=x; ++a;
    }
    // cout << endl;
    f[u] = b+1+(63-__builtin_clzll(a-1));
    // cout << "f[u]: " << a << " " << b << " " << f[u] << endl;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        adj[i].clear();
        f[i] = 0;
    }
    for (int u=2; u<=n; u++){
        int v; cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    calcf(1,0);
    
    cout << f[1] << endl;
    // for (int i=1; i<=n; i++){
    //     cout << f[i] << " ";
    // }
    // cout << endl;
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

