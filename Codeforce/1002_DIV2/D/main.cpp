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
const int N = 1010;
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
int n,s1,s2,m1,m2;
vector<int> adj1[N], adj2[N];
vector<piii> adj[N][N];
ll dist[N][N];
set<pii> st1,st;
bool avail[N];

void Dijkstra(int s1, int s2){
    priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>> pq;
    pq.push({0,{s1,s2}});
    while (!pq.empty()){
        ll d = pq.top().fi;
        int u1 = pq.top().se.fi;
        int u2 = pq.top().se.se;
        pq.pop();

        if (d > dist[u1][u2]) continue;

        for (auto in:adj[u1][u2]){
            ll delta = in.se;
            int v1 = in.fi.fi;
            int v2 = in.fi.se;

            if (delta + d < dist[v1][v2]){
                dist[v1][v2] = delta + d;
                pq.push({delta+d,{v1,v2}});
            }
        }
    }
}

/*Solution*/
void solve(){
    cin >> n >> s1 >> s2;
    cin >> m1;
    for (int i=1; i<=m1; i++){
        int u,v; cin >> u >> v;
        if (u>v) swap(u,v);
        st1.insert(make_pair(u,v));
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    cin >> m2;
    for (int i=1; i<=m2; i++){
        int u,v; cin >> u >> v;
        if (u>v) swap(u,v);
        pii edge = make_pair(u,v);
        if (st1.count(edge)){
            avail[u] = true;
            avail[v] = true;
        }
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            for (auto x:adj1[i]){
                for (auto y:adj2[j]){
                    adj[i][j].push_back({{x,y},abs(x-y)});
                }
            }
        }
    }
    for (int i=1; i<=n; i++){

    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dist[i][j] = LLINF;
        }
    }
    dist[s1][s2] = 0;

    Dijkstra(s1,s2);

    ll ans = LLINF;
    for (int i=1; i<=n; i++){
        if (avail[i] && dist[i][i]!=LLINF){
            ans = min(ans,dist[i][i]);
        }
    }
    if (ans == LLINF) cout << -1 << endl;
    else cout << ans << endl;

    st1.clear();
    for (int i=1; i<=n; i++){
        adj1[i].clear();
        adj2[i].clear();
        avail[i] = false;
        for (int j=1; j<=n; j++){
            adj[i][j].clear();
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
