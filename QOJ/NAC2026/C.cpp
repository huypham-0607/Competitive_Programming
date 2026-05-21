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

int n;
int n,k;
int parent[N], cycle[N];
vector<pii> adj[N], adj2[N];
int vis[N];

void mark_cycle(int v, int p) {
    while (v!=p) {
        cycle[v] = 1;
        v = parent[v];
    }
    cycle[v] = 1;
}

void dfs(int u, int p) {
    vis[u] = 1;
    for (auto v:adj[u]) {
        if (v==p) continue;
        if (vis[u]) {
            mark_cycle(u,v);
        }
        else dfs(v,u);
    }
}

void dfs2(int u, int p) {

}

void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1,0);
    for (int i=1; i<=n; i++){
        if (cycle[i]) {
            for (auto [x,w]:adj[i]) {
                if (!cycle[x]) {
                    adj2[n+1].push_back({x,w});
                    adj2[x].push_back({n+1,w});
                }
            }
        }
        else {
            for (auto [x,w]:adj[i]) {
                adj2[i].push_back({x,w});
                adj2[x].push_back({i,w});
            }
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

