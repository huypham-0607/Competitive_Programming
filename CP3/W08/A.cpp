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

const int N = 4e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int dist[2*N];
int vis[2*N];
int n,m,l;
vector<int> adj[2*N];
int mn[2];

void dijkstra(int s, int n){
    for (int i=1; i<=n; i++){
        dist[i] = LLINF;
        vis[i] = 0;
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[s] = 0;
    pq.push({0,s});
    while (!pq.empty()){
        int u = pq.top().se;
        int d = pq.top().fi;
        pq.pop();

        // if (vis[u]) continue;
        if (d > dist[u]) continue;
        // vis[u] = true;

        for (auto v:adj[u]){
            int delta = 1;
            if (dist[v] > d+delta){
                dist[v] = d+delta;
                pq.push({d+delta,v});
            }
        }
    }
}

void solve(){
    cin >> n >> m >> l;
    mn[0] = mn[1] = 0;
    int mno = INF;
    int t = 0;
    for (int i=1; i<=2*n; i++){
        adj[i].clear();
        dist[i] = INF;
        vis[i] = 0;
    }
    for (int i=1; i<=l; i++) {
        int x;cin >> x;
        t += x;
        if (x%2) mno = min(mno,x);
    }
    mn[t%2] = t;
    if (mno!=INF) {
        mn[(t+1)%2] = t-mno;
    }
    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v+n);
        adj[v+n].push_back(u);

        adj[u+n].push_back(v);
        adj[v].push_back(u+n);
    }

    dijkstra(1,2*n);

    for (int i=1; i<=n; i++){
        if (mn[0] >= dist[i] || mn[1] >= dist[i+n]) {
            cout << '1';
        }
        else cout << '0';
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

