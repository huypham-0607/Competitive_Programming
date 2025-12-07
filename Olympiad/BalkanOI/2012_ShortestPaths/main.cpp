/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e3+50;
const int INF = 1e9+7;
const long long LLINF = 1e15+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,s,e,k;
vector<pii> a[N];
int ID[N];
int dist[N];
set<pii> sp;
int alt[N][N];
int pre[N];
int meow[N][N];
int ans[N];

priority_queue<piii,vector<piii>,greater<piii>> pq;

void Dijkstra(){
    while (!pq.empty()){
        int u = pq.top().se.se;
        int id = pq.top().se.fi;
        int d1 = pq.top().fi;

//        cout  << u << " " << id << " " << d1 << endl;

        pq.pop();

        if (!ID[u]) ID[u] = id;
        else {
            int x = min(id,ID[u]);
            int y = max(id,ID[u]);
            if (x!=y){
                alt[x][y] = min(alt[x][y],d1+dist[u]);
            }
            continue;
        }

        for (auto in:a[u]){
            int v = in.fi;
            int d2 = in.se;
            if (sp.find({u,v}) == sp.end()){
//                if (ID[v]) continue;
//                cout << v << " " << d2 << endl;
                if (dist[v] > d1+d2){
                    dist[v] = d1+d2;
                }
                pq.push({d1+d2,{id,v}});
            }
        }
//        cout << endl;
    }
}

/*Solution*/
void solve(){
    cin >> n >> m >> s >> e;
    for (int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
        meow[u][v] = w;
        meow[v][u] = w;
    }
    cin >> k;
    int prev = 0;
    for (int i=1; i<=n+10; i++){
        for (int j=1; j<=n; j++){
            alt[i][j] = LLINF;
        }
    }
    for (int i=1; i<=n+10; i++){
        dist[i] = LLINF;
        ans[i] = LLINF;
    }
    for (int i=1; i<=k; i++){
        int x;
        cin >> x;
//        ID[x] = i;
        dist[x] = 0;
        pq.push({0,{i,x}});
        if (i!=1){
            pre[i] = pre[i-1] + meow[prev][x];
            sp.insert({x,prev});
            sp.insert({prev,x});
        }
        prev = x;
    }
    Dijkstra();

    for (int i=1; i<=k-1; i++){
        for(int j=k; j>=i+1; j--){
            ans[j] = min({ans[j],ans[j+1],alt[i][j]+pre[i]+pre[k]-pre[j]});
        }
    }

    for (int i=2; i<=k; i++){
        if (ans[i] == LLINF) cout << -1;
        else cout << ans[i];
        if (i<k) cout << endl;
    }
//
//    cout << endl;
//
//    for (int i=1; i<=n; i++){
//        cout << dist[i] << " " << ID[i] << " " << pre[i] << endl;
//    }
//    cout << endl << endl;
//    for (int i=1; i<=k; i++){
//        for (int j=1; j<=k; j++){
//            if (alt[i][j] == LLINF) cout << 0 << " ";
//            else cout << alt[i][j] << " ";
//        }
//        cout << endl;
//    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

