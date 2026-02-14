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

const int N = 5050;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int ch[N];
vector<int> adj[N];
int tin[N],tout[N];
int org[N];
int timedfs = 0;
int pre[N][N];

void dfs(int u, int p) {
    tin[u] = ++timedfs;
    org[timedfs] = u;

    for (auto v:adj[u]) {
        if (v==p) continue;
        dfs(v,u);
    }

    tout[u] = timedfs;
}

int get(int i1,int j1,int i2,int j2) {
    return (pre[i1][j1] - pre[i1][j2+1]+MD - pre[i2+1][j1]+MD + pre[i2+1][j2+1])%MD;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        timedfs = 0;
        adj[i].clear();
    }
    for (int i=1; i<=n+1; i++){
        for (int j=1; j<=n+1; j++){
            pre[i][j] = 0;
        }
    }
    for (int i=1; i<=n; i++){
        char c; cin >> c;
        ch[i] = c-'a';
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);

    for (int i=n; i>0; i--){
        for (int j=n; j>0; j--){
            pre[i][j] = (pre[i][j] + pre[i+1][j] + pre[i][j+1] - pre[i+1][j+1]+MD)%MD;
            // cout << i << " " << j << " " << pre[i][j] << endl;
            if (ch[org[i]] == ch[org[j]]) {
                // cout << "YES" << endl;
                int u = org[i];
                int v = org[j];
                pre[i][j] = (pre[i][j] + get(tin[u]+1,tin[v]+1,tout[u],tout[v])+1)%MD;
            }
            // cout << pre[i][j] << endl;
        }
    }

    // for (int u=1; u<=n; u++){
    //     cout << tin[u] << " " << tout[u] << endl;
    // }
    // for (int i=1; i<=n; i++){
    //     cout << org[i] << endl;
    // }
    for (int u=1; u<=n; u++){
        int res = get(tin[u], tin[u], tout[u], tout[u]);
        cout << res << " ";
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

