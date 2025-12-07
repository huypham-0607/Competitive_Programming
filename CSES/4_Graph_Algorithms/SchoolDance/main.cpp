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
int n,m,k;
int dist[N];
int pairX[N],pairY[N];
vector<int> adj[N];

bool BFS(){
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

//        cout << x << endl;

        if (dist[x]>=dist[0]) continue;

        for (auto y:adj[x]){
//            cout << y << " ";
            if (dist[pairY[y]] == INF){
                dist[pairY[y]] = dist[x]+1;
                q.push(pairY[y]);
            }
        }
//        cout << endl;
    }

//    cout << dist[0] << endl;

    return (dist[0]!=INF);
}

bool DFS(int x){
    if (x == 0) return true;

    for (auto y:adj[x]){
        int v = pairY[y];
        if (dist[v] == dist[x]+1 && DFS(v)){
            pairY[y] = x;
            pairX[x] = y;
            return true;
        }
    }

    dist[x] = INF;
    return false;
}

int Hopcroft_Karp(){
    int cnt = 0;
    while (BFS()){
        for (int i=1; i<=n; i++){
            if (pairX[i] == 0 && DFS(i)){
                ++cnt;
            }
        }
//        cout << dist[0] << endl;
    }
    return cnt;
}

/*Solution*/
void solve(){
    cin >> n >> m >> k;
    for (int i=1; i<=k; i++){
        int u,v; cin >> u >> v;
        ++u;
        ++v;
        adj[u].push_back(v);
    }
    cout << Hopcroft_Karp() << endl;
    for (int i=1; i<=n; i++){
        if (pairX[i]){
            cout << i-1 << " " << pairX[i]-1 << endl;
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
