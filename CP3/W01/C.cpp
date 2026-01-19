#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;

const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 30;
const int MD = 1e9+7;
const long long LLINF = 1e18+3;

int n,m;

int parent[N];

void init(int n) {
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
}

int find(int u) {
    return (u==parent[u]) ? u : parent[u] = find(parent[u]);
}

void merge(int u, int v){
    int x = find(u);
    int y = find(v);

    if (x!=y) {
        parent[x] = y;
    }
}

vector<pair<int,pii>> edges;
vector<pii> edge;

bool check(int mask) {
    init(n);
    edge.clear();
    for (auto in:edges) {
        if (in.fi&mask) continue;
        edge.push_back(in.se);
    }

    int cnt = 0;
    for (auto [u,v]:edge) {
        if (find(u)!=find(v)) {
            merge(u,v);
            ++cnt;
        }
    }
    if (cnt == n-1) return true;
    return false;
}

void solve(){
    edges.clear();
    edge.clear();
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    
    int mask = 0;
    for (int lg=LG-1; lg>=0; lg--){
        if (check(mask^(1<<lg))) {
            mask^=(1<<lg);
        }
    }
    int ans = mask^((1<<LG)-1);
    cout << ans << endl;
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

