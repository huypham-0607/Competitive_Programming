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
int n,m;
bool vis[N];
vector<piii> a[N];
map<int,int> dcolor[N];
map<int,int> tcolor[N];
int dist[N];
priority_queue<pii,vector<pii>,greater<pii>> pq;

void Dijkstra(){
    for (int i=1; i<=n; i++){
        dist[i] = LLINF;
    }
    dist[1] = 0;
    pq.push({0,1});
    while (!pq.empty()){
        int d1 = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        if (d1 > dist[u]) continue;

        vis[u] = true;

        for (auto in:a[u]){
            int v = in.fi;
            int clr = in.se.fi;
            int d2 = in.se.se;

            if (vis[v]) continue;

            int distcolor = dist[u];
            if (dcolor[u].find(clr)!=dcolor[u].end()) distcolor = min(distcolor,dcolor[u][clr]);
            distcolor += tcolor[u][clr]-d2;
            if (distcolor < dist[v]){
                dist[v] = distcolor;
                pq.push({distcolor,v});
            }

            int dnew = dist[u] + d2;
            if (dnew < dist[v]){
                dist[v] = dnew;
                pq.push({dnew,v});
            }
            if (dcolor[v].find(clr) == dcolor[v].end() || dist[u] < dcolor[v][clr]){
                dcolor[v][clr] = dist[u];
            }
        }
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u,v,c,w;
        cin >> u >> v >> c >> w;
        tcolor[u][c]+=w;
        tcolor[v][c]+=w;
        a[u].push_back({v,{c,w}});
        a[v].push_back({u,{c,w}});
    }
    Dijkstra();
//    for (int i=1; i<=n; i++){
//        cout << dist[i] << endl;
//    }
    if (dist[n] == LLINF) cout << -1 << endl;
    else cout << dist[n] << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
