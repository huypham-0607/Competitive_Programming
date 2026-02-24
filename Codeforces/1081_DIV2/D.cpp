/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];
int val[N];
int dp[2][N];
int depth[N];
int maxdepth[N];
int tin[N],tout[N];
vector<int> adj[N];
int timedfs = 0;

void dfs(int u, int p) {
    depth[u] = depth[p]+1;
    maxdepth[u] = depth[u];
    tin[u] = ++timedfs;
    val[timedfs] = a[u];
    for (auto v:adj[u] ){
        if (v==p) continue;
        dfs(v,u);
        maxdepth[u] = max(maxdepth[u],maxdepth[v]);
    }
    tout[u] = timedfs;
}

int getval(int l, int r) {
    return val[r] - val[l-1];
}

void calc_f(int u, int p) {
    vector<int> pref(adj[u].size()+2);
    vector<int> suf(adj[u].size()+2);
    vector<int> dp1(adj[u].size()+2);
    vector<int> dpre(adj[u].size()+2);
    vector<int> dsuf(adj[u].size()+2);
    vector<int> sum(adj[u].size()+2);
    int m = 0;
    dp[0][u] = dp[1][u] = 0;
    for (auto v:adj[u]){ 
        if (v==p) continue;
        ++m;
        calc_f(v,u);
        pref[m] = dp[0][v] + getval(tin[v],tout[v]);
        suf[m] = pref[m];
        dp1[m] = dp[1][v] + getval(tin[v],tout[v]);
        sum[m] = getval(tin[v],tout[v]);
        dp[0][u] += (pref[m]);
        dpre[m] = dsuf[m] = maxdepth[v];
    }
    dp[1][u] = dp[0][u];
    for (int i=1; i<=m; i++){
        pref[i] += pref[i-1];
        dpre[i]  = max(dpre[i],dpre[i-1]);
    }
    for (int i=m; i>0; i--){
        suf[i] += suf[i+1];
        dsuf[i] = max(dsuf[i],dsuf[i+1]);
    }

    for (int i=1; i<=m; i++){
        dp[1][u] = max(dp[1][u],dp1[i] + pref[i-1] + suf[i+1]);

        int dist = max(dsuf[i+1],dpre[i-1]);
        if (dist!=0) {
            int delta = dist - depth[u];

            dp[1][u] = max(dp[1][u], pref[m] + sum[i]*delta);
        }
    }
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    timedfs = 0;
    dfs(1,0);
    for (int i=1; i<=n; i++){
        val[i] += val[i-1];
    }

    calc_f(1,0);

    for (int i=1; i<=n; i++){
        cout << dp[1][i] << " ";
    }
    cout << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

