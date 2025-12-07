/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1000+10;
const int INF = 1e9+7;
const int LG = 10;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,t=0,ans=0;
vector<int> adj[N];
int up[LG][N];
int depth[N],cost[5*N];
int dp[N][5*N];
int bitmask[N][(1<<LG)+10];
int cur[N][5*N],done[N][5*N];
vector<int> pos[N][5*N],s[N],e[N];
vector<piii> edges;

//LCA

void DFS(int u, int p, int d){
    depth[u] = d;
    up[0][u] = p;
    for (int lg=1; lg<LG; lg++){
        up[lg][u] = up[lg-1][up[lg-1][u]];
    }

    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u,d+1);
    }
}

int Lift(int u,int x){
    for (int lg=0; lg<LG; lg++){
        if (x&(1<<lg)) u = up[lg][u];
    }
    return u;
}

pii GetLCA(int u, int v){
    int res = 0;
    if (depth[u]>depth[v]) swap(u,v);
    res+=depth[v]-depth[u];
//    cout << depth[v] << " " << depth[u] << endl;
    v = Lift(v,depth[v]-depth[u]);
//    cout << u << " " << v << endl;
    if (u==v) return make_pair(u,res);
    for (int lg=LG-1; lg>=0; lg--){
        if (up[lg][u]!=up[lg][v]){
            res+=(1<<lg)*2;
            u = up[lg][u];
            v = up[lg][v];
        }
    }
    res+=2;
    return make_pair(up[0][u],res);
}

void DP(int u, int p){
    int cnt = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        DP(v,u);
        for (int i=1; i<=m; i++){
            if (done[v][i]){
                done[u][i] = 1;
                dp[u][i]+=dp[v][i];
                pos[u][i].push_back(cnt);
            }
            else if (cur[v][i]){
                cur[u][i] = 1;
                dp[u][i]+=dp[v][i];
                pos[u][i].push_back(cnt);
            }
        }
        bitmask[u][(1<<cnt)] = max(bitmask[u][(1<<cnt)],dp[v][0]);
        dp[u][0] = max(dp[u][0],dp[v][0]);
        ++cnt;
    }
    for (auto x:s[u]){
        cur[u][x] = 1;
    }
    for (auto x:e[u]){
        done[u][x] = 1;
        dp[u][x]+=cost[x];
    }
    for (int i=1; i<=m; i++){
        if (done[u][i]){
            int mask = 0;
            for (auto idx:pos[u][i]){
                mask^=(1<<idx);
            }
            bitmask[u][mask] = max(bitmask[u][mask],dp[u][i]);
        }
    }
    for (int mask=1; mask<(1<<cnt); mask++){
        int rawr = __builtin_popcount(mask);
        if (rawr>1){
            for (int idx=0; idx<cnt; idx++){
                if (!(mask&(1<<idx))) continue;
                int premask1 = mask^(1<<idx);
                int premask2 = (1<<idx);
                bitmask[u][mask] = max(bitmask[u][mask],bitmask[u][premask1]+bitmask[u][premask2]);
            }
        }
        if (rawr>2){
            for (int idx1=0; idx1<cnt; idx1++){
                for (int idx2=idx1+1; idx2<cnt; idx2++){
                    if (!(mask&(1<<idx1)) || !(mask&(1<<idx2))) continue;
                    int premask1 = (mask^(1<<idx1))^(1<<idx2);
                    int premask2 = (1<<idx1)^(1<<idx2);
                    bitmask[u][mask] = max(bitmask[u][mask],bitmask[u][premask1]+bitmask[u][premask2]);
                }
            }
        }
    }
    for (int i=1; i<=m; i++){
        if (cur[u][i]){
            int mask = 0;
            for (auto idx:pos[u][i]){
                mask^=(1<<idx);
            }
            dp[u][i]+=bitmask[u][((1<<cnt)-1)^mask];
        }
    }
    for (auto x:e[u]){
        cur[u][x] = 0;
    }
    dp[u][0] = max(dp[u][0],bitmask[u][(1<<cnt)-1]);
    ans = max(ans,dp[u][0]);
}

/*Solution*/
void solve(){
    cin >> n >> m;
    int cnt = 0;
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        if (w==0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else{
            t+=w;
            edges.push_back({w,{u,v}});
        }
    }
    DFS(1,0,1);
    for (auto sus:edges){
        int w = sus.fi;
        int u = sus.se.fi;
        int v = sus.se.se;
        pii in = GetLCA(u,v);
        int lca = in.fi;
        int d = in.se;
//        cout << d << endl;
        if (d%2==0){
            ++cnt;
            cost[cnt] = w;
            s[u].push_back(cnt);
            s[v].push_back(cnt);
            e[lca].push_back(cnt);
//            cout << u << " " << v << endl;
        }
    }
//    cout << t << endl;
    m = cnt;
    DP(1,0);
//    for (int i=1; i<=n; i++){
//        cout << "Node: " << i << endl;
//        for (auto x:s[i]){
//            cout << x << " ";
//        }
//        cout << endl;
//        for (auto x:e[i]){
//            cout << x << " ";
//        }
//        cout << endl << endl;
//    }
//    for (int u=1; u<=n; u++){
//        cout << "Node: " << u << endl;
//        for (int i=1; i<=m; i++) cout << dp[u][i] << " ";
//        cout << endl;
//        for (int i=1; i<=m; i++) cout << cur[u][i] << " ";
//        cout << endl;
//        for (int i=1; i<=m; i++) cout << done[u][i] << " ";
//        cout << endl;
//        cout << dp[u][0] << endl;
//        cout << endl;
//    }
//    for (int mask=0; mask<(1<<10); mask++){
//        ans = max(ans,bitmask[1][mask]);
//    }
    cout << t-ans<< endl;
}

/*Driver Code*/
signed main(){
//    freopen("training.inp","r",stdin);
//    freopen("training.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
