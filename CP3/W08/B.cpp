/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
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

const int N = 3e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
int a[N], st[N];


struct Node{
    int u,v,flow,cap;
    Node(int _u, int _v, int _cap): u(_u), v(_v), cap(_cap){
        flow = 0;
    }
};

int s,t,edgecnt;
vector<Node> edge;
vector<int> adj[N];
int level[N],ptr[N];

void AddEdge(int u, int v, int cap){
    edge.emplace_back(u,v,cap);
    edge.emplace_back(v,u,0);
    adj[u].push_back(edgecnt);
    adj[v].push_back(edgecnt+1);
    edgecnt+=2;
}

bool BFS(){
    queue<int> q;
    memset(level,-1,sizeof(level));
    level[s] = 0;
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
    if (u==t) return pushed;

    int res = 0;

    for (int &pos = ptr[u]; pos<(int)adj[u].size(); pos++){
        int id = adj[u][pos];
        int v = edge[id].v;
        if (level[v] == level[u]+1 && edge[id].flow!=edge[id].cap){
            if ((res = DFS(v,min(pushed,edge[id].cap-edge[id].flow)))){
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
        memset(ptr,0,sizeof(ptr));
        int flow;
        while ((flow = DFS(s,INF))){
            max_flow+=flow;
        }
    }
    return max_flow;
}

int deg[N];
vector<pii> lmao;

void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> st[i];
    }
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        deg[u]++;
        deg[v]++;
        lmao.push_back({u,v});
        AddEdge(i,m+u,1);
        AddEdge(i,m+v,1);
    }

    for (int i=1; i<=m; i++){
        AddEdge(0,i,1);
    }
    
    for (int i=1; i<=n; i++){
        if (st[i] == 1) {
            a[i] += deg[i];
            if (a[i] < 0) {
                cout << "NO" << endl;
                return;
            }
            if (a[i]%2 == 1) {
                cout << "NO" << endl;
                return;
            }
            AddEdge(m+i,n+m+2,a[i]/2);
        } else {
            AddEdge(m+i,n+m+1,INF);
        }
    }

    s = 0;
    t = m+n+2;

    int sum = m;
    for (int i=1; i<=n; i++){
        sum-=(a[i]/2);
    }
    // cout << "Passed edge check" << endl;
    if (sum < 0) {
        cout << "NO" << endl;
        return;
    }

    AddEdge(m+n+1,n+m+2,sum);
    int res = Dinitz();
    
    if (res != m) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (int i=0; i<m; i++){
        if (edge[i*4].flow == edge[i*4].cap) {
            cout << lmao[i].se << " " << lmao[i].fi << endl;
        }
        else {
            cout << lmao[i].fi << " " << lmao[i].se << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

