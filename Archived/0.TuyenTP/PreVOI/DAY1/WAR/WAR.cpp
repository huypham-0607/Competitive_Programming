#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "WAR"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int T,n,m;

/*Inititalization*/
void Init(){

}

/*Subtask1*/
bool CheckSub1(){
    return false;
}

void SolveSub1(){

}

//DINITZ
struct Node{
    int u,v,flow,cap;
    Node(int _u, int _v, int _cap): u(_u), v(_v), cap(_cap){
        flow = 0;
    }
};
int s,t;
int edgecnt = 0;
vector<Node> edge;
vector<int> adj[N];
int level[N],ptr[N];

void AddEdge(int u, int v, int cap){
    edge.emplace_back(u,v,cap);
    edge.emplace_back(v,u,cap);
    adj[u].push_back(edgecnt);
    adj[v].push_back(edgecnt+1);
    edgecnt+=2;
}

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
            if ((res = DFS(v,min(pushed,edge[id].cap-edge[id].flow)))){
                edge[id].flow+=res;
                edge[id^1].flow-=res;
                return res;
            }
        }
    }
    return 0;
}

ll Dinitz(){
    ll max_flow = 0;
    while (BFS()){
        memset(ptr,0,sizeof(ptr));
        int flow;
        while ((flow = DFS(s,INF))){
            max_flow+=flow;
        }
    }
    return max_flow;
}

/*Subtask2*/
bool CheckSub2(){
    return true;
}

void SolveSub2(){
    cin >> T >> n >> m;
    for (int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
        u+=1;
        v+=1;
        AddEdge(u,v,w);
    }
    if (T == 1){
        ll ans = LLINF;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (i==j) continue;
                s = i;
                t = j;
                ans = min(ans,Dinitz());
                for (int id=0; id<edgecnt; id++){
                    edge[id].flow = 0;
                }
            }
        }
        cout << ans << endl;
    }
    else{
        ll ans = 0;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (i==j) continue;
                s = i;
                t = j;
                ans = ans+Dinitz();
                for (int id=0; id<edgecnt; id++){
                    edge[id].flow = 0;
                }
            }
        }
        cout << ans << endl;
    }
}

/*Subtask3*/
bool CheckSub3(){
    return false;
}

void SolveSub3(){

}

/*Subtask4*/
bool CheckSub4(){
    return false;
}

void SolveSub4(){

}

/*Driver Code*/
signed main(){
//    freopen(NAME".inp","r",stdin);
//    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();

    if (CheckSub1()) return SolveSub1(),0;
    if (CheckSub2()) return SolveSub2(),0;
    if (CheckSub3()) return SolveSub3(),0;
    if (CheckSub4()) return SolveSub4(),0;

    return 0;
}
