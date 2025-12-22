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
int n;
vector<int> adj[N];
int deg[N];

void DFS(int u, int p, int check){
    int cnt = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        int nextcheck = (check+1)%2;
        ++cnt;
        if (!p){
            if (cnt == 1){
                cout << v << " " << u << endl;
            }
            else {
                cout << u << " " << v << endl;
                nextcheck = (nextcheck+1)%2;
            }
        }
        else{
            if (!check) cout << v << " " << u << endl;
            else cout << u << " " << v << endl;
        }
        DFS(v,u,nextcheck);
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        adj[i].clear();
        deg[i] = 0;
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }

//    for (int i=1; i<=n; i++){
//        cout << deg[i] << " ";
//    }
//    cout << endl;
    for (int i=1; i<=n; i++){
        if (deg[i] == 2){
            cout << "YES" << endl;
            DFS(i,0,0);
            return;
        }
    }
    cout << "NO" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
