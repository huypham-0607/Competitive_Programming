/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<pii,int>
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
int n,m,timedfs=0,q;
vector<piii> adj[N];
int num[N],low[N];
int dir[N];
int pre[N];
int luutmp[N];
bool IsBridge[N];

//DSU
//void Init(){
//    for (int i=1; i<=n; i++){
//        parent[i] = i;
//    }
//}
//
//int Find(int x){
//    return (x == parent[x])? x : parent[x] = Find(parent[x]);
//}
//
//void Union(int u, int v){
//    int x = Find(u);
//    int y = Find(v);
//    if (x!=y){
//        parent[y] = x;
//    }
//}

int DFS(int u, int prev){
    int t = 0;
    bool multie = 0;
    num[u] = low[u] = ++timedfs;
    for (auto in:adj[u]){
        int v = in.fi.fi;
        int id = in.fi.se;
        int dr = in.se;

        if (!multie && v == prev){
            multie = 1;
            continue;
        }
        if (!num[v]){
            int tmp = DFS(v,u);
            t+=tmp;
//            cout << u << " " << v << " " << tmp << endl;
            low[u] = min(low[u],low[v]);
            if (num[v] == low[v]){
//                Union(u,v);
                IsBridge[id] = true;
                if (tmp!= 0){
                    dir[id] = dr;
                    if (tmp<0) dir[id] = -dir[id];
                }
//                adj2[Find(u)].push_back(Find(v));
//                adj2[Find(v)].push_back(Find(u));
            }
        }
        else low[u] = min(low[u],num[v]);
    }
    t+=pre[u];
    return t;
}

/*Solution*/
void solve(){
    cin >> n >> m;
//    cout << n << "_" << m << endl;
//    Init();
    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
//        if (i==12) cout << u << "-" << v << endl;
        adj[u].push_back({{v,i},1});
        adj[v].push_back({{u,i},-1});
    }
    cin >> q;
    for (int i=1; i<=q; i++){
        int u,v; cin >> u >> v;
        pre[u]--;
        pre[v]++;
    }
    for (int i=1; i<=n; i++){
        if (!num[i]) DFS(i,0);
    }
    for (int i=1; i<=m; i++){
//        if (i==7){
//            if (IsBridge[i]) cout << "rawr" << endl;
//            else cout << "ewww" << endl;
//        }
        if (dir[i] == 0) cout << "B";
        else if (dir[i] == 1) cout << "R";
        else cout << "L";
//        cout << luutmp[i] << "-";
    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << low[i] << " ";
//    }
//    cout << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
