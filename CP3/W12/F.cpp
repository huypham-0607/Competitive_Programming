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
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m,k;
vector<int> adj[N];
int num[N];
int col[N];
vector<pii> edges;
int timedfs = 0;

void dfs(int u, int p) {
    num[u] = ++timedfs;

    for (auto v:adj[u]) {
        if (v==p) continue;
        if (!num[v]) {
            edges.push_back({u,v});
            dfs(v,u);
        }
        else if (num[v] < num[u]) {
            ++k;
            col[k] = v;
            edges.push_back({u,k});
        }
    }
}

void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    k = n;
    for (int i=1; i<=n; i++){
        col[i] = i;
    }
    dfs(1,0);
    cout << k << endl;
    for (int i=1; i<=k; i++){
        cout << col[i] << " ";
    }
    cout << endl;
    for (auto [x,y]:edges){ 
        cout << x << " " << y << endl;
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

