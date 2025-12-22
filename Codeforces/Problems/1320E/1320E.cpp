/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
//#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piiii pair<pii,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 18;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void Solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) Solve();
}

/*Global Variables*/
int n,q,k,m;

int timedfs = 0;
int depth[N], tin[N], tout[N];
vector<int> adj[N];
int up[LG][N];

void DFS(int u, int p){
    tin[u] = ++timedfs;


    for (auto v:adj[u]){
        if (v==p) continue;

        depth[v] = depth[u]+1;
        up[0][v] = u;

        for (int lg=1; lg<LG; lg++){
            up[lg][v] = up[lg-1][up[lg-1][v]];
        }

        DFS(v,u);
    }
    tout[u] = ++timedfs;
}

bool IsAnc(int u, int v){
    return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

int GetLCA(int u, int v){
    if (IsAnc(u,v)) return u;
    if (IsAnc(v,u)) return v;
    for (int lg=LG-1; lg>=0; lg--){
        if (depth[v] >= ((int)1<<lg) && !IsAnc(up[lg][v],u)){
            v = up[lg][v];
        }
    }
    return up[0][v];
}

bool CompDFSTime(int u, int v){
    return (tin[u] < tin[v]);
}

int s[N];
vector<int> source;
vector<int> sink;
vector<int> VT_node;
vector<pii> VT[N];
int VT_size;
vector<pair<pii,int>> dist;

void Dijkstra(){
    priority_queue<piiii,vector<piiii>,greater<piiii>> pq;
    for (int i=0; i<VT_size; i++){
        if (dist[i].fi.fi == -1){
            pq.push({{dist[i].fi.fi,dist[i].fi.se},{dist[i].se,i}});
        }
    }

    while (!pq.empty()){
        int u = pq.top().se.se;
        int d = pq.top().se.fi;
        int id = pq.top().fi.se;
        int t = pq.top().fi.fi;

        pair<pii,int> rawr = {{t,id},d};

        pq.pop();

        if (rawr>dist[u]) continue;

//        cout << t << " " << id << " " << d << " " << VT_node[u] << endl;

        for (auto in:VT[u]){
            int v = in.fi;
            int d_new = d + in.se;
            pair<pii,int> sus = {{d_new/s[id],id},d_new};
            if (sus<dist[v]){
                dist[v] = sus;
                pq.push({{d_new/s[id],id},{d_new,v}});
            }
        }
    }
}

void SolveQuery(){
    cin >> k >> m;
    for (int i=0; i<k; i++){
        int x; cin >> x >> s[i];
        source.push_back(x);
        VT_node.push_back(x);
    }
    for (int i=0; i<m; i++){
        int x; cin >> x;
        sink.push_back(x);
        VT_node.push_back(x);
    }

    sort(all(VT_node),CompDFSTime);
    VT_node.resize(unique(all(VT_node))-VT_node.begin());
    VT_size = VT_node.size();
    for (int i=0; i<VT_size-1; i++){
        VT_node.push_back(GetLCA(VT_node[i],VT_node[i+1]));
    }
    sort(all(VT_node),CompDFSTime);
    VT_node.resize(unique(all(VT_node))-VT_node.begin());
    VT_size = VT_node.size();

    stack<int> st;
    st.push(0);

    for (int i=1; i<VT_size; i++){
        int j = st.top();
        while (!IsAnc(VT_node[j],VT_node[i])){
            st.pop();
            j = st.top();
        }
        VT[j].push_back({i,depth[VT_node[i]] - depth[VT_node[j]]});
        VT[i].push_back({j,depth[VT_node[i]] - depth[VT_node[j]]});
        st.push(i);
    }

//    for (int i=0; i<VT_size; i++){
//        cout << VT_node[i] << " ";
//    }
//    cout << endl;
//    for (int i=0; i<VT_size; i++){
//        for (auto in:VT[i]){
//            cout << "{" << in.fi << "," << in.se << "} ";
//        }
//        cout << endl;
//    }

    dist.resize(VT_size,{{INF,INF},INF});
    for (int i=0; i<(int)source.size(); i++){
        int id = lower_bound(VT_node.begin(),VT_node.end(),source[i],CompDFSTime) - VT_node.begin();
        dist[id] = {{-1,i},-1};
    }

//    for (int i=0; i<VT_size; i++){
//        cout << dist[i].fi.fi << " " << dist[i].fi.se << " " << dist[i].se << endl;
//    }

    Dijkstra();

    for (int i=0; i<(int)sink.size(); i++){
        int id = lower_bound(all(VT_node),sink[i],CompDFSTime) - VT_node.begin();
        cout << dist[id].fi.se+1 << " ";
    }
    cout << endl;
    dist.clear();
    for (int i=0; i<VT_size; i++){
        VT[i].clear();
    }
    VT_node.clear();
    source.clear();
    sink.clear();
//    cout << endl;
}

/*Solution*/
void Solve(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1,0);

//    cout << GetLCA(5,7) << endl;

//    for (int i=1; i<=n; i++){
//        cout << i << " " << depth[i] << endl;
//        cout << tin[i] << " " << tout[i] << endl;
//        for (int lg=0; lg<LG; lg++){
//            cout << up[lg][i] << " ";
//        }
//        cout << endl;
//    }

//    cout << (-1)/10 << endl;
    cin >> q;
    for (int i=1; i<=q; i++){
        SolveQuery();
    }
}

/*Driver Code*/
signed main(){
//    freopen("1320E.inp","r",stdin);
//    freopen("1320E.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
