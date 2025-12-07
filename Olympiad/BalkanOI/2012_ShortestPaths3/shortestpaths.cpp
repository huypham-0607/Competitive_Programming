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

#define NAME "shortestpaths"

using namespace std;

/*Constants*/
const int N = 2e3+10;
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
int n,m,s,e,k;
vector<int> distfor,distrev,distcen;
vector<pii> adj[N];
vector<int> a[N];
int sp[N];
int parent[N];
bool IsSP[N];
int ID[N];
vector<int> nxt[N];
int anc[N];
int ans[N];

void dijkstra(int s, vector<int>& dist, bool sus){
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    dist.resize(n+10,INF);
    dist[s] = 0;
    pq.push({0,{s,0}});
    while (!pq.empty()){
        int d = pq.top().fi;
        int u = pq.top().se.fi;
        int p = pq.top().se.se;
        pq.pop();

//        cout << u << " " << d << " " << p << endl;

        if (d>dist[u]) continue;
        if (sus && !parent[u]){
            parent[u] = p;
            if (p!=0){
//                cout << p << " " << u << endl;
                a[u].push_back(p);
                a[p].push_back(u);
            }
        }
        for (auto in:adj[u]){
            int v = in.fi;
            int delta = in.se;

            if (d+delta < dist[v]){
                dist[v] = d+delta;
                pq.push({d+delta,{v,u}});
            }
        }
    }
}

void DFS(int u, int p, int curanc){
    if (IsSP[u]) curanc = u;
    anc[u] = curanc;
    for (auto v:a[u]){
        if (v==p) continue;
        DFS(v,u,curanc);
    }
}

/*Solution*/
void solve(){
    cin >> n >> m >> s >> e;
    for (int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin >> k;
    for (int i=1; i<=k; i++){
        cin >> sp[i];
        ID[sp[i]] = i;
        IsSP[sp[i]] = true;
        ans[i] = INF;
        if (i==1) continue;
        nxt[sp[i]].push_back(sp[i-1]);
        nxt[sp[i-1]].push_back(sp[i]);
    }
    dijkstra(s,distfor,0);
    dijkstra(e,distrev,0);
//    for (int i=1; i<=n; i++){
//        if (IsSP[i]){
//            for (int j=0; j<(int)adj[i].size(); j++){
//                for (auto x:nxt[i]){
//                    if (adj[i][j].fi == x) adj[i][j].se = 0;
//                }
//            }
//        }
//    }

    dijkstra(s,distcen,1);
    DFS(s,0,0);
    for (int i=1; i<=n; i++){
        if (IsSP[i]){
            for (int j=0; j<(int)adj[i].size(); j++){
                for (auto x:nxt[i]){
                    if (adj[i][j].fi == x) adj[i][j].se = 0;
                }
            }
        }
    }
//    for (int i=1; i<=n; i++){
//        cout << distfor[i] << " " << distrev[i] << " " << distcen[i] << endl;
//        cout << "Node: " << i << endl;
//        for (auto in:adj[i]){
//            cout << "{" << in.fi << "," << in.se << "} ";
//        }
//        cout << endl;
//    }
//    for (int i=1; i<=n; i++){
//        cout << anc[i] << " ";
//    }
//    cout << endl;
    for (int i=1; i<=n; i++){
        for (auto in:adj[i]){
            int u = i;
            int v = in.fi;
            int val = in.se;
            if (val == 0) continue;
            if (ID[anc[u]] > ID[anc[v]]) swap(u,v);

            int pu = anc[u];
            int pv = anc[v];
            int idu = ID[pu];
            int idv = ID[pv];
            int delta = distfor[u] + distrev[v] + val;
            for (int idx=idv-1; idx>=idu; idx--){
                if (ans[idx] > delta){
//                    cout << idx << " " << u << " " << v << " " << delta << endl;
                }
                ans[idx] = min(ans[idx],delta);
            }
        }
    }
    for (int i=1; i<k; i++){
        if (ans[i] == INF) cout << -1 << endl;
        else cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
//    freopen(NAME".inp","r",stdin);
//    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

