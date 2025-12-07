/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 40010;
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
int a[210][210];
int pairX[N],pairY[N],dist[N];
bool visX[N],visY[N];

bool BFS(){
    memset(visX,0,sizeof(visX));
    memset(visY,0,sizeof(visY));
    queue<int> q;
    for (int i=1; i<=n; i++){
        if (pairX[i] == 0){
            dist[i] = 0;
            q.push(i);
        }
        else dist[i] = INF;
    }
    dist[0] = INF;
    while (!q.empty()){
        int x = q.front();
        q.pop();

        visX[x] = true;
        for (auto y:adj[x]){
            int v = pairY[y];
            visY[y] = true;
            if (dist[v]==INF){
                dist[v] = dist[x]+1;
                q.push(v);
            }
        }
    }
    return (dist[0]!=INF);
}

bool DFS(int u){
    if (u == 0) return true;
    for (auto y:adj[u]){
        int v = pairY[y];
        if (dist[v] == dist[u]+1 && DFS(v)){
            pairX[u] = y;
            pairY[y] = u;
            return true;
        }
    }
    dist[u] = INF;
    return 0;
}

int Hopcroft_Karp(){
    int matching = 0;
    memset(pairX,0,sizeof(pairX));
    memset(pairY,0,sizeof(pairY));
    while (BFS()){
//        cout << dist[0] << endl;
        for (int i=1; i<=n; i++){
            if (pairX[i] == 0 && DFS(i)){
                ++matching;
            }
        }
    }
    return matching;
}

bool vis[210][210];

void DFSsus(int i, int j){
    vis[i][j] = true;
    if (a[i][j+1] && visX[m*(i-1)+j] && !vis[i][j+1]){
        DFSsus(i,j+1);
    }
    if (a[i][j-1] && visX[m*(i-1)+j-1] && !vis[i][j-1]){
        DFSsus(i,j-1);
    }
    if (a[i+1][j] && !visY[m*(i-1)+j] && !vis[i+1][j]){
        DFSsus(i+1,j);
    }
    if (a[i-1][j] && !visY[m*(i-2)+j] && !vis[i-1][j]){
        DFSsus(i-1,j);
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            char c; cin >> c;
            if (c=='#') a[i][j] = 1;
        }
    }

//    int t = 0;
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=m; j++){
//            if (a[i][j+1]) ++t;
//            if (a[i+1][j]) ++t;
//        }
//    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (!a[i][j]) continue;
            if (a[i-1][j]){
                if (a[i][j+1]){
                    adj[m*(i-1)+j].push_back(m*(i-2)+j);
                }
                if (a[i][j-1]){
                    adj[m*(i-1)+(j-1)].push_back(m*(i-2)+j);
                }
            }
            if (a[i+1][j]){
                if (a[i][j+1]){
                    adj[m*(i-1)+j].push_back(m*(i-1)+j);
                }
                if (a[i][j-1]){
                    adj[m*(i-1)+(j-1)].push_back(m*(i-1)+j);
                }
            }
        }
    }

//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=m; j++){
//            int u = m*(i-1)+j;
//            cout << m*(i-1)+j << ": ";
//            for (auto v:adj[u]){
//                cout << v << " ";
//            }
//            cout << endl;
//        }
//    }

    int sn = n;
    n = m*n;

    Hopcroft_Karp();

    n = sn;

//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=m; j++){
//            int val = m*(i-1)+j;
//            cout << pairX[val] << " " << pairY[val] << endl;
//        }
//    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i][j] && !vis[i][j]){
                ++ans;
                DFSsus(i,j);
            }
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
