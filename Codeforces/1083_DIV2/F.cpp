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

int n,m;
vector<vector<int>> vert,hor,avert,ahor;

struct DSU{
    int n;
    vector<int> marked,val;
    vector<int> parent;

    void init(int _n){
        n = _n;
        parent.resize(n,0);
        marked.resize(n,0);
        val.resize(n,0);
        for (int i=0; i<n; i++){
            parent[i] = i;
            marked[i] = 0;
            val[i] = 0;
        }
    }

    int find(int x){
        return (x == parent[x])? x : parent[x] = find(parent[x]);
    }

    bool isSame(int u, int v){
        return (find(u) == find(v));
    }

    void merge(int u, int v){
        int x = find(u);
        int y = find(v);
        if (x!=y){
            marked[x] += marked[y];
            val[x] += val[y];
            parent[y] = x;
        }
    }
} DSU;



void solve(){
    cin >> n >> m;
    hor.clear(); vert.clear();
    ahor.clear(); avert.clear();
    hor.resize(n+1,vector<int>(m+1,0));
    vert.resize(n+1,vector<int>(m+1,0));
    ahor.resize(n+1,vector<int>(m+1,0));
    avert.resize(n+1,vector<int>(m+1,0));
    for (int i=0; i<n-1; i++){
        for (int j=0; j<m; j++){
            cin >> vert[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m-1; j++){
            cin >> hor[i][j];
        }
    }
    for (int i=0; i<n-1; i++){
        for (int j=0; j<m; j++){
            char c; cin >> c;
            avert[i][j] = c-'0';
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m-1; j++){
            char c; cin >> c;
            ahor[i][j] = c-'0';
        }
    }

    --n;
    --m;

    DSU.init(n*m);
    vector<pii> edge;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int id = i*m+j;
            int x = hor[i][j] - hor[i+1][j] + vert[i][j] - vert[i][j+1];
            DSU.val[id] = x;
            
            if (!ahor[i][j]) {
                if (i == 0) DSU.marked[id] = 1;
                else edge.push_back({id,id-m});
            }
            if (!ahor[i+1][j]) {
                if (i == n-1) DSU.marked[id] = 1;
                else edge.push_back({id,id+m});
            }
            if (!avert[i][j]) {
                if (j == 0) DSU.marked[id] = 1;
                else edge.push_back({id,id-1});
            }
            if (!avert[i][j+1]) {
                if (j == m-1) DSU.marked[id] = 1;
                else edge.push_back({id,id+1});
            }
        }
    }

    for (auto [u,v]:edge) {
        DSU.merge(u,v);
    }

    vector<int> vis(n*m,0);
    int ans = 0;
    for (int id = 0; id<n*m; id++){
        int x = DSU.find(id);
        if (vis[x]) continue;
        vis[x] = 1;

        if (!DSU.marked[x]) {
            ans += max(0LL,DSU.val[x]);
        }
    }
    
    cout << ans << endl;
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

