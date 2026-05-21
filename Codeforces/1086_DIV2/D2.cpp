/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "D2"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
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

const int N = 8010;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;

struct DSU{
    int n;
    vector<int> parent;

    void init(int _n){
        n = _n;
        parent.resize(n+1,0);
        for (int i=1; i<=n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        return (x == parent[x])? x : parent[x] = find(parent[x]);
    }

    bool isSame(int u, int v){
        return (find(u) == find(v));
    }

    // merge y to x
    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if (x!=y){
            parent[y] = x;
        }
    }
} DSU;

int deg[N];
int mat[N][N];
int mat2[N][N];
vector<int> to[N];
vector<int> from[N];
vector<int> adj[N];
vector<pii> ans;

int vis[N];

void BFS(int s) {
    for (int i=1; i<=n; i++){
        vis[i] = 0;
    }
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()){
        int u = q.front();
        q.pop();

        mat2[s][u] = 1;

        for (auto v:adj[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;     
            }
        }
    }
}

void solve(){
    cin >> n;

    ans.clear();
    for (int i=1; i<=n; i++){
        deg[i] = 0;
        from[i].clear();
        to[i].clear();
        adj[i].clear();
        for (int j=1; j<=n; j++){
            mat[i][j] = 0;
            mat2[i][j] = 0;
        }
    }
    DSU.init(n);

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            char c; cin >> c;
            mat[i][j] = c-'0';
            if (i == j) continue;
            if (c == '1') {
                deg[i]++;
                to[i].push_back(j);
                from[j].push_back(i);
            }
        }
    }

    queue<int> q;
    for (int i=1; i<=n; i++){
        if (deg[i] == 0) q.push(i); 
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int idx = to[u].size()-1; idx>=0; idx--) {
            int v = to[u][idx];
            if (!DSU.isSame(u,v)) {
                ans.push_back({u,v});
                adj[u].push_back(v);
                DSU.merge(u,v);
            }
        }

        for (auto v:from[u]){ 
            --deg[v];
            to[v].push_back(u);
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    // cout << ans.size() << endl;

    // for (auto [x,y]:ans) {
    //     cout << x << " " << y << endl;
    // }

    if (ans.size() != n-1) {
        cout << "NO" << endl;
        return;
    }

    for (int i=1; i<=n; i++){
        BFS(i);
    }

    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=n; j++){
    //         cout << mat2[i][j];
    //     }
    //     cout << endl;
    // }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (mat[i][j] != mat2[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (auto [x,y]:ans) {
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

