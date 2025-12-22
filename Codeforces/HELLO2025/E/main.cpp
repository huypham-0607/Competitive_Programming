/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 405;
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
int n,m,q;
//int dist[N][N];
vector<pii> adj[N];
//vector<pii> lst[N][N];
int ans[N][N][N];
int d1[N],d2[N];
//bool vis1[N],vis2[N];
vector<piii> edge;

void BFS01(int s, int val, int d[]){
    deque<pii> dq;
    for (int i=1; i<=n; i++){
        if (i==s) d[i] = 0;
        else d[i] = INF;
    }
    dq.push_front({s,0});
    while (!dq.empty()){
        int u = dq.front().fi;
        int w = dq.front().se;
        dq.pop_front();

//        if (vis[u]) continue;
//        vis[u] = true;
        if (w>d[u]) continue;

        for (auto in:adj[u]){
            int v,delta,w2; tie(v,delta) = in;
            if (delta<=val){
                w2 = 0;
//                d[v] = d[u];
//                dq.push_front(v);
            }
            else{
                w2 = 1;
//                d[v] = d[u]+1;
//                dq.push_back(v);
            }
            if (w+w2<d[v]){
                d[v] = w+w2;
                if (w2==1){
                    dq.push_back({v,d[v]});
                }
                else{
                    dq.push_front({v,d[v]});
                }
            }
        }
    }
}

void Magic(int s, int e, int x){
    BFS01(s,x,d1);
    BFS01(e,x,d2);

//    cout << s << " " << e << ":" << endl;
//    for (int i=1; i<=n; i++){
//        cout << d1[i] << " ";
//    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << d2[i] << " ";
//    }
//    cout << endl;

    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
//            lst[i][j].push_back({min(d1[i]+d2[j]+1,d1[j]+d2[i]+1),x});
            int k = min({d1[i]+d2[j]+1,d1[j]+d2[i]+1,d1[i]+d1[j]+1,d2[i]+d2[j]+1});
            ans[i][j][k] = min(ans[i][j][k],x);
            ans[j][i][k] = min(ans[i][j][k],x);
        }
    }
}

/*Solution*/
void solve(){
    cin >> n >> m >> q;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            for (int k=0; k<=n; k++){
                ans[i][j][k] = INF;
            }
//            dist[i][j] = 0;
        }
    }
    for (int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
//        dist[u][v] = w;
//        dist[v][u] = w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edge.push_back({{u,v},w});
    }

    for (int i=0; i<(int)edge.size(); i++){
        Magic(edge[i].fi.fi,edge[i].fi.se,edge[i].se);
    }


    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            for (int k=1; k<=n; k++){
                ans[i][j][k] = min(ans[i][j][k-1],ans[i][j][k]);
            }
        }
    }

//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << i << " " << j << ": ";
//            for (int k=1; k<=m; k++){
//                cout << ans[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//    }

    for (int id=1; id<=q; id++){
        int u,v,w; cin >> u >> v >> w;
//        w = min(w,n);
//        if (n==400) cout << w << " ";
        else cout << ans[u][v][w] << " ";
    }
    cout << endl;

    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    edge.clear();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
