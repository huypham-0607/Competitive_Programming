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
const int N = 2e3+10;
const int INF = 1e9+7;
const long long LLINF = 1e13+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,k,s,e;
int alt[N][N],meow[N][N];
bool lucky[N];
vector<pii> adj[N];
int ans[N],ID[N],pre[N];
int up[N],dist[N];
set<pii> sp;
vector<piii> edges;
vector<pii> a[N];
priority_queue<piii,vector<piii>,greater<piii>> pq;

//Dijkstra
void dijkstra(){
    while (!pq.empty()){
        int d1 = pq.top().fi;
        int u = pq.top().se.fi;
        int p = pq.top().se.se;
        pq.pop();

        if (d1 > dist[u]) continue;

        if (p){
            adj[p].push_back({u,dist[u]-dist[p]});
        }

        for (auto in:a[u]){
            int v = in.fi;
            int d2 = in.se;

            if (d1+d2 < dist[v]){
                dist[v] = d1+d2;
                pq.push({dist[v],{v,u}});
            }
        }
    }
}

void dfs(int u,int rep){
    if (lucky[u]) up[u] = u;
    else up[u] = rep;
    for (auto in:adj[u]){
        int v = in.fi;
        dfs(v,up[u]);
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
        edges.push_back({w,{u,v}});
    }
    cin >> k;
    int prev = 0;
    int dst = 0;
    for (int i=1; i<=n+1; i++){
        dist[i] = LLINF;
        ans[i] = LLINF;
        for (int j=1; j<=n; j++){
            alt[i][j] = LLINF;
        }
    }
    for (int i=1; i<=k; i++){
        int x;
        cin >> x;
        lucky[x] = true;
        ID[x] = i;

        if (i==1){
            dist[x] = dst;
            pre[i] = dst;
            pq.push({dst,{x,0}});
        }
        if (i!=1){
            dst+=meow[x][prev];
            dist[x] = dst;
            pre[i] = dst;
            pq.push({dst,{x,prev}});
            sp.insert({x,prev});
            sp.insert({prev,x});
        }

        prev = x;
    }

    dijkstra();
    dfs(s,s);
    for (auto in:edges){
        int u = in.se.fi;
        int v = in.se.se;
        int w = in.fi;

        if (sp.find({u,v}) != sp.end()) continue;

        if (ID[up[u]] > ID[up[v]]) swap (u,v);
        int i = ID[up[u]];
        int j = ID[up[v]];
        int dst = pre[i]+pre[k]-pre[j] + (dist[u] - dist[up[u]]) + (dist[v] - dist[up[v]]) + w;
        for (int idx = i+1; idx<=j; idx++){
            ans[idx] = min(ans[idx],dst);
        }
    }
    for (int i=2; i<=k; i++){
        if (ans[i] >= LLINF) cout << -1;
        else cout << ans[i];
        if (i<k) cout << endl;
    }

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
