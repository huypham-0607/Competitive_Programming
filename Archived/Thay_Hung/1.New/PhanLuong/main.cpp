/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;
const int LG = 17;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

//Global Variables
int n,timedfs=0,m,q;

int ans[N],num[N],low[N];
vector<piii> a[N];
vector<int> adj[N];
int bridge[N];
int cnt[N];

void DFSTREE(int u, int p, int prev, int dir){
    if (p!=0) adj[p].push_back(u);
    bridge[u] = prev;
    num[u] = low[u] = ++timedfs;
    ans[prev] = dir;

    for (auto in:a[u]){
        if (in.se.fi==prev) continue;
        int v = in.fi;
        if (!num[in.fi]){
            DFSTREE(in.fi,u,in.se.fi,in.se.se);
            low[u] = min(low[u],low[v]);
        }
        else{
            low[u] = min(low[u],num[v]);
        }
    }
    if (low[u] == num[u]){
        isbridge[prev] = true;
    }
}

void DFSANS(int u, int p){
    for (auto v:adj[u]){
        if (v==p) continue;
        DFSANS(v,u);
        cnt[u]+=cnt[v];
    }
    if (isbridge[bridge[u]]){
        int idx = bridge[u];
        if (cnt[u] == 0) ans[idx] = 0;
        else if (cnt[u]<0) ans[idx] = (ans[idx]%2)+1;
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back({v,{i,1}});
        a[v].push_back({u,{i,2}});
    }
    DFSTREE(1,0,0,1);
    cin >> q;
    while (q--){
        int u,v;
        cin >> u >> v;
//        int lca = LCA(u,v);
        cnt[u] += -1;
        cnt[v] += 1;
    }
    DFSANS(1,0);
    for (int i=1; i<=m; i++){
        if (isbridge[i]){
            if (ans[i] == 0) cout << "X";
            else if (ans[i] == 1) cout << "P";
            else cout << "T";
        }
        else cout << "X";
    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << bridge[i] << " " << num[i] << " "  << low[i] << " " << cnt[i] << endl;
//    }
//    for (int i=1; i<=m; i++){
//        cout << isbridge[i] << endl;
//    }
}

/*Driver Code*/
signed main(){
//    freopen("PHANLUONG.inp","r",stdin);
//    freopen("PHANLUONG.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
