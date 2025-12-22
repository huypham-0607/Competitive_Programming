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
const int N = 505;
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
vector<int> parent;
vector<vector<int>> res;
vector<vector<int>> adj;
vector<vector<int>> cap;

//Flow

int Find_Aug(int s, int e){
    for (int i=1; i<=n; i++){
        parent[i] = -1;
    }
//    cout << "rawr" << endl;
    parent[s] = -2;
    queue<pii> q;
    q.push({s,INF});
    while (!q.empty()){
        int u = q.front().fi;
        int val = q.front().se;
        q.pop();

//        cout << u << " " << val << endl;

        for (int v:adj[u]){
//            cout << v << endl;
            if (parent[v]==-1 && cap[u][v]){
                parent[v] = u;
                int new_val = min(val,cap[u][v]);
                if (v == e){
                    return new_val;
                }
                q.push({v,new_val});
            }
        }
    }
    return 0;
}

/*Solution*/
void solve(){
    cin >> n >> m;
    parent.resize(n+5);
    adj.resize(n+5);
    cap.resize(n+5,vector<int>(n+5,0));
    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] = 1;
    }
    int ans = 0;
    int new_flow;
//    for (int i=0; i<=n+1; i++){
//        for (int j=0; j<=n+1; j++){
//            if (cap[i][j] == INF) cout << "inf" << " ";
//            else cout << cap[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        for (int j=0; j<=5; j++){
//            cout << cnt[i][j] << " ";
//        }
//        cout << endl;
//    }
//    for (int i=0; i<=n+1; i++){
//        cout << parent[i] << " ";
//    }
//    cout << endl;
    int cnt = 0;
    while (new_flow = Find_Aug(1,n)){
        ans+=new_flow;
//        cout << "new: "<< new_flow << endl;
        int u = n;
        res.push_back(vector<int>());
        while (u!=1){
            int v = parent[u];
            res[cnt].push_back(u);
//            cout << v << endl;
            cap[v][u] -= new_flow;
            cap[u][v] += new_flow;
            u = v;
        }
        res[cnt].push_back(1);
        ++cnt;
    }
    cout << cnt << endl;
    for (int i=0; i<cnt; i++){
        cout << res[i].size() << endl;
        while (!res[i].empty()){
            cout << res[i].back() << " ";
            res[i].pop_back();
        }
        cout << endl;
    }
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
