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
pii info[N];
vector<piii> adj[N];
vector<piii> adj2[N];
int cowtype[N];
bool vis[N];
bool vis2[N];
bool occ[N];
int parent[N];
deque<int> dq;

int susedge=0;

void DFS(int u, int p){
    parent[u] = p;
    vis[u] = true;
    for (auto in:adj[u]){
        int v = in.fi;

        if (v==p) continue;

        if (!vis[v]){
            adj2[u].push_back(in);
            adj2[v].push_back({u,{(in.se.fi%2)+1,in.se.se}});
            DFS(v,u);
        }
        else susedge = in.se.se;
    }
}

void BFS(int s){
    queue<int> q;
    vis2[s] = true;
    q.push(s);
    while (!q.empty()){
        int u =q.front();
//        cout << u << endl;
        q.pop();

        for (auto in:adj2[u]){
            int v = in.fi;
            int tpe = in.se.fi;
            int id = in.se.se;

            if (!vis2[v]){
                vis2[v] = true;
                cowtype[id] = tpe;
                dq.push_back({id});
                q.push(v);
            }
        }
    }
}

void BFS2(int s){
    queue<int> q;
    vis2[s] = true;
    q.push(s);
    while (!q.empty()){
        int u =q.front();
//        cout << u << endl;
        q.pop();

        for (auto in:adj2[u]){
            int v = in.fi;
            int tpe = in.se.fi;
            int id = in.se.se;

            if (!vis2[v]){
                vis2[v] = true;
                if (!occ[info[id].fi]){
                    occ[info[id].fi] = true;
                    cowtype[id] = 1;
                }
                else{
                    occ[info[id].se] = true;
                    cowtype[id] = 2;
                }
                dq.push_back({id});
                q.push(v);
            }
        }
    }
}

void SolveComp(int s){
    susedge = 0;
    DFS(s,0);
//    cout << "S: " << s << endl;
//    cout << "sus: " << susedge << endl;
    if (susedge){
        dq.push_back(susedge);
        cowtype[susedge] = 1;
        BFS(info[susedge].fi);
    }
    else{
        BFS2(s);
    }
}

/*Solution*/
void solve(){
    cin >> m >> n;
    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        info[i] = {u,v};
        adj[u].push_back({v,{2,i}});
        adj[v].push_back({u,{1,i}});
    }
    for (int i=1; i<=n; i++){
        if (!vis[i]) SolveComp(i);
    }

    int ans = m;

//    deque<int> dq;

    for (int i=1; i<=m; i++){
        if (cowtype[i]){
            --ans;
//            if (cowtype[i] == 1) dq.push_front(i);
//            else dq.push_back(i);
        }
    }

//    for (int i=1; i<=n; i++){
//        cout << parent[i] << " ";
//    }
//    cout << endl;
    cout << ans << endl;
    while (!dq.empty()){
        cout << dq.front() << endl;
        dq.pop_front();
    }
    for (int i=1; i<=m; i++){
        if (!cowtype[i]) cout << i << endl;
    }
}

/*Driver Code*/
signed main(){
//    freopen("cereal2.inp","r",stdin);
//    freopen("cereal2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
