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

const int N = 410;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

struct Edge{
    int u,v,w;

    Edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }

    const bool operator<(Edge other) const{
        return w < other.w;
    }
    const bool operator>(Edge other) const{
        return w > other.w;
    }
};

int n,m,q;
vector<Edge> edges;

vector<pii> adj[N];
vector<pii> ans[N][N];
int dist[N];
bool vis[N];

void setup_BFS(int val){
    for (int s=1; s<=n; s++){
        deque<int> dq;
        ffor(i,1,n) {
            dist[i] = INF;
            vis[i] = 0;
        }
        dist[s] = 0;
        dq.push_back(s);
        while(!dq.empty()){
            int u = dq.front(); dq.pop_front();
            if (vis[u]) continue;
            vis[u] = true;
            // if (val == 9){
                 // cout << "bfs: " << u << " " << dist[u] << endl;
            // }
            for (auto [v,w]:adj[u]){
                if (dist[v] > dist[u]+w){
                    dist[v] = min(dist[v],dist[u]+w);
                    if (w){
                        dq.push_back(v);
                    }
                    else {
                        dq.push_front(v);
                    }
                }
            }
        }

        // if (val == 9 && s == 1) {
        //     ffor(e,1,n){
        //         cout << dist[e] << " ";
        //     }
        //     cout << endl;
        //     ffor(i,1,n){
        //         for (auto x:adj[i]) {
        //             cout << x.fi << ":" << x.se << " ";
        //         }
        //         cout << endl;
        //     }
        // }


        for (int e=s+1; e<=n; e++){
            if (ans[s][e].size() && ans[s][e].back().fi == dist[e]) ans[s][e].pop_back();
            ans[s][e].push_back({dist[e],val});
        }
    }
}

void solve(){
    cin >> n >> m >> q;
    ffor(i,1,n){
        ffor(j,1,n){
            ans[i][j].clear();
        }
    }
    edges.clear();
    ffor(i,1,m) {
        int u,v,w; cin >> u >> v >> w;
        edges.push_back(Edge(u,v,w));
    }
    sort(all(edges),greater<Edge>());
    frep(i,0,m){
        ffor(idx,1,n) adj[idx].clear();
        // cerr << i << endl;
        frep(idx,0,m) {
            adj[edges[idx].u].push_back({edges[idx].v,((idx<i)?1:0)});
            adj[edges[idx].v].push_back({edges[idx].u,((idx<i)?1:0)});
        }
        // cerr << "setup: " << i << " " << edges[i].w << endl;
        setup_BFS(edges[i].w);
    }

    // for (auto x:ans[1][6]){
    //     cerr << "{" << x.fi << "," << x.se << "} ";
    // }
    // cerr << endl;

    for (int i=1; i<=q; i++){
        int u,v,k; cin >> u >> v >> k;
        if (u>v) swap(u,v);
        // cout << u << " " << v << " " << k << endl;

        auto val = --upper_bound(all(ans[u][v]),make_pair(k,0));
        // cout << (val-ans[u][v].begin()) << endl;
        cout << val->se << " ";
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

