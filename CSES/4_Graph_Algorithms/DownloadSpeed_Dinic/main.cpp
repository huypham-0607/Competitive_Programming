/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "DownloadSpeed"

using namespace std;

/*Constants*/
const int N = 510;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

struct Node{
    int u,v,flow,cap;

    Node(int _u, int _v, int _cap): u(_u), v(_v), cap(_cap){
        flow = 0;
    }
};

/*Global Variables*/
int n,m,s,e;
int edgecnt = 0;
vector<int> adj[N];
vector<Node> edge;

void AddEdge(int u, int v, int cap){
    edge.push_back(Node(u,v,cap));
    edge.push_back(Node(v,u,0));
    adj[u].push_back(edgecnt);
    adj[v].push_back(edgecnt+1);
    edgecnt+=2;
}

//Dinic
int level[N],ptr[N];

bool BFS(){
    queue<int> q;
    memset(level,-1,sizeof(level));
    level[s] = 0;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (auto id:adj[u]){
            int v = edge[id].v;
            if (level[v]!=-1 || edge[id].flow == edge[id].cap) continue;
            level[v] = level[u]+1;
            q.push(v);
        }
    }
    return (level[e]!=-1);
}

int DFS(int u, int pushed){
    if (pushed == 0) return 0;
    if (u == e) return pushed;

    for (int &idx = ptr[u]; idx<(int)adj[u].size(); idx++){
        int id = adj[u][idx];
        int v = edge[id].v;
        if (level[v] == level[u]+1 && edge[id].flow!=edge[id].cap){
            int delta = min(pushed,edge[id].cap - edge[id].flow);
            int res = DFS(v,delta);
            if (res){
                edge[id].flow+=res;
                edge[id^1].flow-=res;
                return res;
            }
        }
    }

    return 0;
}

ll Dinic(){
    ll max_flow = 0;
    while (BFS()){
        memset(ptr,0,sizeof(ptr));
        int res;
        while ((res = DFS(s,INF))){
            max_flow+=res;
        }
    }
    return max_flow;
}

/*Solution*/
void solve(){
    cin >> n >> m;
    s=1;e=n;
    for (int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
        AddEdge(u,v,w);
    }
    ll ans = Dinic();
    cout << ans << endl;
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
