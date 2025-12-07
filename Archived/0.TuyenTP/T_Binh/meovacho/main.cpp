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

/*Global Variables*/
int n,m,v;

//Hopcroft_Karp
vector<int> adj[N];
int pairX[N],pairY[N],dist[N];
pii lstX[N],lstY[N];
int Xcnt=0, Ycnt = 0;

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

        for (auto y:adj[x]){
            int v = pairY[y];
            if (dist[v] == INF){
                dist[v] = dist[x]+1;
                q.push(v);
            }
        }
    }
    return (dist[0]!=INF);
}

bool DFS(int x){
    if (x==0) return true;
    for (auto y:adj[x]){
        int v = pairY[y];
        if (dist[v] == dist[x]+1 && DFS(v)){
            pairX[x] = y;
            pairY[y] = x;
            return true;
        }
    }

    dist[x] = INF;
    return false;
}

int Hopcroft_Karp(){
    int matching = 0;
    while (BFS()){
        for (int i=1; i<=n; i++){
            if (pairX[i] == 0 && DFS(i)){
                ++matching;
            }
        }
    }
    return matching;
}

/*Solution*/
void solve(){
    cin >> n >> m >> v;
    for (int i=1; i<=v; i++){
        char c1,c2; int id1,id2;
        cin >> c1 >> id1 >> c2 >> id2;
        if (c1 == 'C'){
            lstX[++Xcnt] = {id1,id2};
        }
        else{
            lstY[++Ycnt] = {id1,id2};
        }
    }
    for (int i=1; i<=Xcnt; i++){
        for (int j=1; j<=Ycnt; j++){
            if ((lstX[i].fi == lstY[j].se) || (lstX[i].se == lstY[j].fi)){
                adj[i].push_back(j);
            }
        }
    }

    n = Xcnt;

    cout << v-Hopcroft_Karp() << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
