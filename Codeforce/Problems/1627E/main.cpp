/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define piiii pair<pii,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
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
vector<int> a[N];
//map<pii,bool> vis;
map<pii,int> dist;
map<pii,vector<piii>> adj;
vector<int> fire;
priority_queue<piiii,vector<piiii>,greater<piiii>> pq;

void Dijkstra(int level){
    while (!pq.empty() && pq.top().fi.fi == level){
        int w = pq.top().fi.se;
        pii u = pq.top().se;

        pq.pop();

        if (w > dist[u]) continue;

        for (auto in:adj[u]){
            pii v = in.fi;
            int w2 = in.se;
            if (w+w2 < dist[v]){
                dist[v] = w+w2;
                pq.push({{v.fi,w+w2},v});
            }
        }
    }
}

/*Solution*/
void solve(){
    cin >> n >> m >> k;
    fire.push_back(0);
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        fire.push_back(x);
    }
    for (int i=1; i<=k; i++){
        pii u,v;
        int w;
        cin >> u.fi >> u.se >> v.fi >> v.se >> w;
//        vis[u] = false;
//        vis[v] = false;
        dist[u] = LLINF;
        dist[v] = LLINF;
        a[u.fi].push_back(u.se);
        a[v.fi].push_back(v.se);
        adj[u].push_back({v,-w});
    }
//    vis[{n,m}] = false;
    dist[{n,m}] = LLINF;
    for (int idx=1; idx<=n; idx++){
        if (idx==1) a[idx].push_back(1);
        if (idx==n) a[idx].push_back(m);
        sort(a[idx].begin(),a[idx].end());
        if (a[idx].size() > 1){
            for (int i=0; i<(int)a[idx].size()-1; i++){
                if (a[idx][i] == a[idx][i+1]) continue;
                adj[{idx,a[idx][i]}].push_back({{idx,a[idx][i+1]},(a[idx][i+1]-a[idx][i])*fire[idx]});
                adj[{idx,a[idx][i+1]}].push_back({{idx,a[idx][i]},(a[idx][i+1]-a[idx][i])*fire[idx]});
            }
        }
    }

//    vis[{1,1}] = true;
    dist[{1,1}] = 0;
    pq.push({{1,0},{1,1}});

    for (int i=1; i<=n; i++){
        Dijkstra(i);
//        cout << pq.empty() << endl;
    }

    if (dist[{n,m}] == LLINF){
        cout << "NO ESCAPE" << endl;
    }
    else cout << dist[{n,m}] << endl;
//    cout << dist[{1,1}] << " ";
//    for (int i=1; i<=n; i++){
//        for (auto j:a[i]){
//            cout << dist[{i,j}] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

//    vis.clear();
    while (!pq.empty()) pq.pop();
    adj.clear();
    fire.clear();
    for (int i=1; i<=n; i++){
        a[i].clear();
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
