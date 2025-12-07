/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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

const int N = 2810;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,A,B,T;

//Dinitz
//Max flow in O(V^2*E)

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

vector<string> aq;
vector<string> bq;
vector<vector<string>> tq(1010);
vector<int> tcnt(1010);
vector<vector<int>> curon(610);
int aj[1010][1010];

int getType(int idx){
    if (idx <= 2*A) return 0;
    if (idx <= 2*A + 2*B) return 1;
    else return 2;
}

void solve(){
    cin >> n >> A >> B >> T;
    vector<string> nen;
    for (int i=1; i<=A; i++){
        string st; cin >> st;
        aq.push_back(st);
        nen.push_back(st);
    }
    for (int i=1; i<=B; i++){
        string st; cin >> st;
        bq.push_back(st);
        nen.push_back(st);
    }
    for (int i=0; i<T; i++){
        cin >> tcnt[i];
        for (int idx=1; idx<=tcnt[i]; idx++){
            string st; cin >> st;
            tq[i].push_back(st);
            nen.push_back(st);
        }
    }
    sort(all(nen));
    nen.resize(unique(all(nen)) - nen.begin());

    int n = 2*A + 2*B + 2*T;

    for (int i=0; i<A; i++){
        int v = lower_bound(all(nen), aq[i])-nen.begin()+1;
        int idx = i*2+1;
        AddEdge(idx,idx+1,1);
        AddEdge(0,idx,INF);
        curon[v].push_back(idx);
    }

    for (int i=0; i<B; i++){
        int v = lower_bound(all(nen), bq[i])-nen.begin()+1;
        int idx = 2*A + i*2 + 1;
        AddEdge(idx,idx+1,1);
        AddEdge(idx+1,n+1,INF);
        curon[v].push_back(idx);
    }
    vector<int> tmp;
    for (int i=0; i<T; i++){
        int idx = 2*A + 2*B + 2*i +1;
        AddEdge(idx,idx+1,1);
        for (int pos = 0; pos < tq[i].size(); pos++){

            int v = lower_bound(all(nen), tq[i][pos]) - nen.begin()+1;
            for (auto idx2:curon[v]){
                int tpe = getType(idx2);
                if (tpe == 0) {
                    AddEdge(idx2+1,idx,1);
                }
                else if (tpe == 1) {
                    AddEdge(idx+1,idx2,1);
                }
                else {
                    int j = (idx2-2*A-2*B-1)/2;
                    if (!aj[i][j]){
                        AddEdge(idx+1,idx2,1);
                        AddEdge(idx2+1,idx,1);
                        aj[i][j] = 1;
                    }
                }
            }
            curon[v].push_back(idx);
        }
    }
    s = 0;
    t = n+1;
    int ans = Dinitz();
    cout << ans << endl;
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

