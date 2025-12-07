/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
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
//Dinic

struct Node{
    int u,v,cap,flow;
    Node(int _u, int _v, int _cap): u(_u), v(_v), cap(_cap){
        flow = 0;
    }
};

vector<int> adj[N];
vector<Node> edge;
int edgecnt = 0;
int level[N], ptr[N];


bool BFS(){
    queue<int> q;
    memset(level,-1,sizeof(level));
    level[1] = 0;
    q.push(1);
    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (auto id:adj[u]){
            if (level[edge[id].v]!=-1 || edge[id].flow == edge[id].cap) continue;
            level[edge[id].v] = level[u]+1;
            q.push(edge[id].v);
        }
    }
    return (level[n]!=-1);
}

int DFS(int u, int pushed){
    if (pushed == 0) return 0;
    if (u==n) return pushed;
    int res = 0;
    for (int &idx = ptr[u]; idx<adj[u].size(); idx++){
        int id = adj[u][idx];
        if (edge[id].cap == edge[id].flow || level[edge[id].v] != level[u]+1) continue;
        if ((res = DFS(edge[id].v,min(edge[id].cap - edge[id].flow,pushed)))){
            edge[id].flow+=res;
            edge[id^1].flow-=res;
            return res;
        }
    }
    return res;
}

int Dinitz(){
    int max_flow = 0;
    while (BFS()){
        memset(ptr,0,sizeof(ptr));
        int flow;
        while ((flow = DFS(1,LLINF))){
            max_flow+=flow;
        }
    }
    return max_flow;
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int idx=1; idx<=m; idx++){
        int u,v,w; cin >> u >> v >> w;
        edge.emplace_back(u,v,w);
        edge.emplace_back(v,u,w);
        adj[u].push_back(edgecnt);
        adj[v].push_back(edgecnt+1);
        edgecnt+=2;
    }
//    for (int i=0; i<edgecnt; i++){
//        cout << edge[i].u << " " << edge[i].v << " " << edge[i].cap << endl;
//    }
    cout << Dinitz() << endl;
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
