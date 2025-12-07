/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int B = 800;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,q;
//int B;
pii edges[N];
int weight[N];
bool marked[N];
bool sus[N];
int ans[N];
vector<int> lst_marked;
vector<int> lst_node;
vector<pii> lst_edges;
vector<pii> version[N];
vector<piii> query;

//DSU
struct DSU{
    int parent[N];
    int sz[N];
    DSU(){
        for (int i=1; i<=n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int Find(int x){
        return (x == parent[x]) ? x : parent[x] = Find(parent[x]);
    }

    void Union (int x, int y){
        int u = Find(x);
        int v = Find(y);
        if (sus[v]) swap(u,v);
        if (u!=v){
            sz[u]+=sz[v];
            parent[v] = u;
        }
    }
} DSU1,DSU2;

void GetAns(int t, int s, int w){
//    cerr << t << " " << s << " " << w << endl;
    for (auto idx:lst_marked){
        int i = --upper_bound(all(version[idx]),make_pair(t,INF)) - version[idx].begin();
        int val = version[idx][i].se;
//        cerr << "val: " << val << endl;
        if (val >= w){
            DSU2.Union(edges[idx].fi,edges[idx].se);
        }
    }
    int rawr = DSU1.Find(s);
//    for (int i=1; i<=n; i++){
//        cerr << DSU1.parent[i] << " ";
//    }
//    cerr << endl;
//    cerr << rawr << " " << DSU1.sz[DSU1.Find(s)] << endl;
    if (!sus[rawr]){
        ans[t] = DSU1.sz[DSU1.Find(s)];
    }
    else ans[t] = DSU2.sz[DSU2.Find(rawr)];
}

void Magic(){
    sort(all(query),greater<piii>());
    for (int i=1; i<=m; i++){
        if (!marked[i]) lst_edges.push_back({weight[i],i});
    }
    sort(all(lst_edges),greater<pii>());
    int idx = 0;
    for (auto in:query){
        int w = in.fi;
        int u = in.se.fi;
        int t = in.se.se;

        while (idx!=(int)lst_edges.size() && lst_edges[idx].fi>=w){
            int edge_id = lst_edges[idx].se;
//            cerr << "edge: " << edges[edge_id].fi << " " << edges[edge_id].se << endl;
            DSU1.Union(edges[edge_id].fi,edges[edge_id].se);
            ++idx;
        }

        for (auto id:lst_node){
            DSU2.parent[id] = DSU1.parent[DSU1.Find(id)];
            DSU2.sz[id] = DSU1.sz[DSU1.Find(id)];
        }
        GetAns(t,u,w);
    }
    for (int i=1; i<=n; i++){
        DSU1.parent[i] = i;
        DSU1.sz[i] = 1;
        DSU2.parent[i] = i;
        DSU2.sz[i] = 1;
    }
    lst_edges.clear();
    query.clear();
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges[i] = {u,v};
        weight[i] = w;
    }
    cin >> q;
//    B = floor(sqrt(q));
    for (int i=1; i<=n; i++){
        DSU1.parent[i] = i;
        DSU1.sz[i] = 1;
        DSU2.parent[i] = i;
        DSU2.sz[i] = 1;
    }
//    cerr << B << endl;
    int pos = 0;
    int ibatch = 0;
    while (pos<q){
        int cnt = 0;
        int lim = q-pos;
        ++ibatch;
//        cerr << "batch: " << ibatch << endl;
        while (cnt<min(B,lim)){
            ++pos;
            ++cnt;
//            cerr << cnt << endl;
            int id,idx,val;
            cin >> id >> idx >> val;
            if (id == 1){
                if (!marked[idx]){
                    lst_marked.push_back(idx);
                    version[idx].push_back({0,weight[idx]});
                    marked[idx] = true;
                }
                version[idx].push_back({pos,val});
                if (!sus[edges[idx].fi]){
                    sus[edges[idx].fi] = true;
                    lst_node.push_back(edges[idx].fi);
                }
                if (!sus[edges[idx].se]){
                    sus[edges[idx].se] = true;
                    lst_node.push_back(edges[idx].se);
                }
            }
            else{
                query.push_back({val,{idx,pos}});
            }
        }
        Magic();
        for (auto idx:lst_marked){
            weight[idx] = version[idx].back().se;
            version[idx].clear();
            marked[idx] = false;
        }
        lst_marked.clear();
        for (auto idx:lst_node){
            sus[idx] = false;
        }
        lst_node.clear();
//        for (int i=1; i<=m; i++){
//            cout << weight[i] << " ";
//        }
//        cout << endl;
    }
    for (int i=1; i<=q; i++){
        if (ans[i]) cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
//    freopen("Bridges.inp","r",stdin);
//    freopen("Bridges.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
