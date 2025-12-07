/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#include "race.h"
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,k;
vector<pii> adj[N];
int sz[N];
bool vis[N];
int ans;

map<int,int> mp;

int findSize(int u, int p=0){
    sz[u] = 1;
    for (auto [v,w]:adj[u]){
        if (vis[v] || v==p) continue;
        sz[u]+=findSize(v,u);
    }
    return sz[u];
}

int findCentroid(int u, int n, int p=0){
    for (auto [v,w]:adj[u]){
        if (vis[v] || v==p) continue;
        if (sz[v] > n/2) return findCentroid(v,n,u);
    }
    return u;
}

void dfsCalc(int u, int dist, int p=0, int depth = 1){
    if (k-dist>=0 && mp.count(k-dist)){
        ans = min(ans,depth + mp[k-dist]);
    }
//    cout << u << " " << ans << endl;
    for (auto [v,w]:adj[u]){
        if (vis[v] || v==p) continue;
        dfsCalc(v,dist+w,u,depth+1);
    }
}

void dfsIns(int u, int dist, int p=0, int depth = 1){
    if (!mp.count(dist)) mp[dist] = depth;
    else mp[dist] = min(mp[dist],depth);
    for (auto [v,w]:adj[u]){
        if (vis[v] || v==p) continue;
        dfsIns(v,dist+w,u,depth+1);
    }
}

void buildCentroid(int u, int p=0){
    findSize(u);

    int c = findCentroid(u,sz[u]);
//    cout << "centroid: " <<  c << endl;
    vis[c] = true;
    mp[0] = 0;
    for (auto [v,w]:adj[c]){
        if (vis[v]) continue;
        dfsCalc(v,w);
        dfsIns(v,w);
    }
//    cout << ans << endl;
    mp.clear();
    for (auto [v,w]:adj[c]){
        if (vis[v]) continue;
        buildCentroid(v,c);
    }
}

signed best_path(int _n, int _k, int h[][2], int l[]){
    n = _n;
    k = _k;
    for (int i=0; i<n-1; i++){
        int u,v;
        u = h[i][0];
        v = h[i][1];
        ++u;
        ++v;
//        tie(u,v) = h[i];
        adj[u].push_back({v,l[i]});
        adj[v].push_back({u,l[i]});
    }
    ans = n+1;
    buildCentroid(1);
    if (ans == n+1) return  -1;
    return ans;
}

//int _n, _k;
//int _h[N][2];
//int _l[N];


//void solve(){
//    cin >> _n >> _k;
//    for (int i=0; i<_n-1; i++){
//        int u,v,w;
//        cin >> u >> v >> w;
//        _h[i][0] = u;
//        _h[i][1] = v;
//        _l[i] = w;
//    }
//    cout << best_path(_n,_k,_h, _l);
//}
//
//signed main(){
//    cin.tie(0) -> sync_with_stdio(0);
//    if (fopen(TEXT".inp","r")){
//        freopen(TEXT".inp","r",stdin);
//        freopen(TEXT".out","w",stdout);
//    }
//
//    int testCount = 1;
////    cin >> testCount;
//    while (testCount--){
//        solve();
//    }
//
//    return 0;
//}
