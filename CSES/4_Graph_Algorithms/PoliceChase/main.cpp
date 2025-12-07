/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1010;
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
int n,m;
vector<int> adj[N];
vector<pii> edges;
int cap[N][N];
int parent[N];

int BFS(){
    for (int i=1; i<=n; i++){
        parent[i] = 0;
    }
    parent[1] = -1;
    queue<pii> q;
    q.push({1,INF});
    while (!q.empty()){
        int u,w; tie(u,w) = q.front();
        q.pop();

        for (auto v:adj[u]){
            if (v==parent[u]) continue;
            if (!parent[v] && cap[u][v]){
                int new_flow = min(w,cap[u][v]);
                parent[v] = u;
                if (v==n) return new_flow;
                q.push({v,new_flow});
            }
        }
    }
    return 0;
}

int Edmond_Karp(){
    int res = 0;
    int val = 0;
//    int id = 0;
    while ((val = BFS())){
//        ++id;
//        if (id == 10) break;
        res+=val;
//        cout << val << endl;
        int u = n;
        while (u!=1){
//            cout << u << endl;
            int v = parent[u];
            cap[v][u]-=val;
            cap[u][v]+=val;
            u = v;
        }
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        if (u==v) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u,v});
        cap[u][v]++;
        cap[v][u]++;
    }
    cout << Edmond_Karp() << endl;
    BFS();

//    for (int i=1; i<=n; i++){
//        cout << parent[i] << endl;
//    }

    for (auto in:edges){
        int u,v; tie(u,v) = in;
        if ((parent[u] == 0 && parent[v]!=0) || (parent[u] != 0 && parent[v] == 0)){
            cout << u << " " << v << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
