#pragma GCC optimization O2
#pragma GCC optimization "unroll-loop"
#pragma target ("avx2")

#include <bits/stdc++.h>
#define ll int
#define ld long double
#define fs first
#define sc second
using namespace std;
typedef pair<ll,ll> LL;
const ll N = 2e5 + 9;
const ll inf = 1e9 + 7;
vector<LL> g[N];
ll n,x,y,w,dp[N][2][2],ans,val1[N],val2[N];

void DFS(ll u,ll p){
    ll child = 0; multiset<ll> s;
    for (auto i : g[u]) if (i.fs != p) DFS(i.fs,u),child++;
    dp[u][0][0] = dp[u][0][1] = 0;
    if (!child) dp[u][1][0] = dp[u][1][1] = -inf;
    for (auto i : g[u]){
        ll v = i.fs,cost = i.sc;
        if (v == p) continue;
        dp[u][0][0] += max(dp[v][1][0] + cost,dp[v][0][0]);
        val1[v] = dp[v][0][1] + cost - max(dp[v][1][0] + cost,dp[v][0][0]);
        val2[v] = dp[v][0][0] + cost - max(dp[v][1][0] + cost,dp[v][0][0]); s.insert(val2[v]);
    }
    for (auto i : g[u]){
        ll v = i.fs,cost = i.sc;
        if (v == p) continue;
        ll now = dp[u][0][0] - max(dp[v][1][0] + cost,dp[v][0][0]) + dp[v][0][0] + cost;
        dp[u][1][0] = max(dp[u][1][0],now);
        dp[u][1][1] = max(dp[u][1][1],now - dp[v][0][0] + dp[v][0][1]);
    }
    for (auto i : g[u]){
        ll v = i.fs,cost = i.sc;
        if (v == p) continue;
        ll now = dp[u][0][0] - max(dp[v][1][0] + cost,dp[v][0][0]) + max(dp[v][1][1] + cost,dp[v][0][1]);
        dp[u][0][1] = max(dp[u][0][1],now);
    }


    if (child < 2) return;
    for (auto i : g[u]){
        ll v = i.fs,cost = i.sc;
        if (v == p) continue;
        s.erase(s.find(val2[v]));
        dp[u][0][1] = max(dp[u][0][1],dp[u][0][0] + val1[v] + *s.rbegin());
        s.insert(val2[v]);
    }
}
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
    #define task "beads"
    freopen(task".inp","r",stdin);
    freopen(task".ans","w",stdout);
    cin>>n;
    for (ll i = 1;i < n;i++){
        cin>>x>>y>>w;
        g[x].push_back({y,w}); g[y].push_back({x,w});
    }
    DFS(1,0);
    cout<<max(dp[1][0][0],dp[1][0][1]);
}
