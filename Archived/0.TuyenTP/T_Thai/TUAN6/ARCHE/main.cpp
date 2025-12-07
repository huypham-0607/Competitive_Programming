/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e15+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m;
vector<piii> edges;
//vector<piii> tmp;
//vector<piii> org;
vector<pii> cancel;
bool sus[N];

struct DSU{
    int n;
    vector<int> parent;

    void Init(int _n){
        n = _n;
        parent.resize(n+10);
    }

    void Reset(){
        for (int i=1; i<=n; i++){
            parent[i] = i;
        }
    }

    int Find(int x){
        return (parent[x] == x)? x : parent[x] = Find(parent[x]);
    }

    void Union(int u, int v){
        int x = Find(u);
        int y = Find(v);
        parent[y] = x;
    }
} DSU;

bool check(int x){
    DSU.Reset();
//    for (auto &in:org){
//        int u,v; tie(u,v) = in.se;
//        DSU.Union(u,v);
//    }
    for (int i=(int)edges.size()-1; i>=0; i--){
        int w = edges[i].fi;
        int u = edges[i].se.fi;
        int v = edges[i].se.se;
        if (w<=x) break;
        DSU.Union(u,v);
    }

    for (auto &in:cancel){
        int u,v; tie(u,v) = in;
        if (DSU.Find(u)==DSU.Find(v)) return false;
    }
    return true;
}

/*Solution*/
void solve(){
    cin >> n >> m;
    DSU.Init(n);
    DSU.Reset();
    for (int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
        if (w == -1){
            cancel.push_back({u,v});
        }
        else{
            edges.push_back({w,{u,v}});
            DSU.Union(u,v);
        }
    }
//    for (auto &in:cancel){
//        int u,v; tie(u,v) = in;
//        if (DSU.Find(u) == DSU.Find(v)){
//            sus[u] = 1;
//            sus[v] = 1;
//        }
//    }
//    for (auto &in:tmp){
//        int u,v; tie(u,v) = in.se;
//        edges.push_back(in);
////        if (sus[u] || sus[v]) edges.push_back(in);
////        else org.push_back(in);
//    }

    sort(edges.begin(),edges.end());

    int ans = -1;
    int l = 0;
    int r = INF;
    while (l<=r){
        int mid = (l+r)/2;
        if (check(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
