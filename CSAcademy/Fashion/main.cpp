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
const int N = 2e5+10;
const int INF = 1e12+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,t;

//Dinitz
struct Edge{
    int u,v,cap,flow;
    Edge(int _u, int _v, int _cap): u(_u), v(_v), cap(_cap){
        flow = 0;
    }
};

vector<int> adj[N];
int edgecnt = 0;
vector<Edge> edge;
int level[N],ptr[N];

void AddEdge(int u, int v, int cap){
    adj[u].push_back(edgecnt);
    adj[v].push_back(edgecnt+1);
    edge.emplace_back(u,v,cap);
    edge.emplace_back(v,u,0);
    edgecnt+=2;
}

bool BFS(){
    queue<int> q;
    memset(level,-1,sizeof(level));
    level[0] = 0;
    q.push(0);
    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (auto id:adj[u]){
            int v = edge[id].v;
            if (level[v] == -1 && edge[id].flow!=edge[id].cap){
                level[v] = level[u]+1;
                q.push(v);
            }
        }
    }
    return (level[t]!=-1);
}

int DFS(int u, int pushed){
    if (pushed == 0) return 0;
    if (u == t) return pushed;

    int res = 0;

    for (int &pos = ptr[u]; pos<(int)adj[u].size(); pos++){
        int id = adj[u][pos];
        int v = edge[id].v;
        if (level[v] == level[u]+1 && edge[id].flow!=edge[id].cap){
            int delta = edge[id].cap - edge[id].flow;
            if ((res = DFS(v,min(pushed,delta)))){
                edge[id].flow+=res;
                edge[id^1].flow-=res;
                return res;
            }
        }
    }

    return 0;
}

int Dinitz(){
    int max_flow = 0;
    while (BFS()){
        int flow;
        memset(ptr,0,sizeof(ptr));
        while ((flow = DFS(0,LLINF))){
            max_flow+=flow;
        }
    }
    return max_flow;
}

vector<int> ans;

/*Solution*/
void solve(){
    cin >> n >> m;
    int sum = 0;
    t = n+m+1;
    for (int i=1; i<=n; i++){
        int c; cin >> c >> c;
        AddEdge(i,t,c);
    }
    for (int i=1; i<=m; i++){
        int x,y,z,c;
        cin >> x >> y >> z >> c;
        AddEdge(n+i,x,INF);
        AddEdge(n+i,y,INF);
        AddEdge(n+i,z,INF);
        AddEdge(0,n+i,c);
        sum+=c;
    }
    cout << sum-Dinitz() << " ";
    for (int id=0; id<edgecnt; id++){
        if (edge[id].v == t && level[edge[id].u]!=-1){
            ans.push_back(edge[id].u);
        }
    }
    cout << ans.size() << endl;
    for (auto x:ans){
        cout << x << " ";
    }
//    for (int i=0; i<=t; i++){
//        cout << level[i] << endl;
//    }
//    for (auto in:edge){
//        cout << in.u << " " << in.v << " " << in.flow << " " << in.cap << endl;
//    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
