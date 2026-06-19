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

const int N = 5e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int used[N];
int a[N];
int fw[N];
int bw[N];
int vis[N];

struct DSU{
    int n;
    vector<int> parent,sz;

    void init(int _n){
        n = _n;
        parent.clear();
        sz.clear();
        parent.resize(n+1,0);
        sz.resize(n+1,1);
        iota(all(parent),0);

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
            sz[x] += sz[y];
            parent[y] = x;
        }
    }
}DSU;

bool DFS(int i, int val) {
    // cout << "DFS: " << i << " " << val << endl;
    vis[i] = true;
    if (used[val]) return false;
    used[val] = true;
    a[i] = val;

    int u = fw[i];
    int w = fw[a[i]];
    // cout << "nxt: " << i << " " << u << " " << w << endl;
    if (a[u] != -1 && a[u] != w) return false;
    if (vis[u]) {
    }
    else {
        if (!DFS(u,w)) return false;
    }

    u = bw[i];
    w = bw[a[i]];
    // cout << "nxt: " << i << " " << u << " " << w << endl;
    if (a[u] != -1 && a[u] != w) return false;
    if (vis[u]) {
    }
    else {
        if (!DFS(u,w)) return false;
    }
    return true;
}

vector<int> lst[N];
int ptr[N];

void solve(){
    cin >> n;
    DSU.init(n);
    ffor(i,1,n) {
        vis[i] = used[i] = 0;
        lst[i].clear();
        ptr[i] = 0;
    }
    ffor (i,1,n) {
        cin >> fw[i]; bw[fw[i]]=i;
        DSU.merge(i,fw[i]);
    }
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        if (a[i] != -1 && !vis[i]) {
            bool res = DFS(i,a[i]);
            if (!res) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    ffor(i,1,n) {
        int sz = DSU.sz[DSU.find(i)];
        lst[sz].push_back(i);
    }

    for (int i=1; i<=n; i++){
        if (a[i] == -1) {
            int sz = DSU.sz[DSU.find(i)];
            while (ptr[sz]!=lst[sz].size() && used[lst[sz][ptr[sz]]]) ++ptr[sz];
            bool res = DFS(i,lst[sz][ptr[sz]]);
            if (!res) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    ffor(i,1,n) cout << a[i] << " "; cout << endl;
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

