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

const int N = 5e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k,x;
vector<int> adj[N];
int ccnt[N];
int state[N];
int dist[N];

void dfs(int u, int p) {
    ccnt[u] = 0;
    state[u] = 0;
    dist[u] = 0;
    int cnt = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        ccnt[u]++;
        dfs(v,u);
        dist[u] += dist[v];
        cnt += state[v];
    }

    if (ccnt[u] == 0) {
        state[u] = 1;
        dist[u] = 0;
    }
    if (ccnt[u] == 1) {
        dist[u]++;
        state[u] = cnt;
    }
    else {
        cnt = 0;
        pii mn = {INF,INF};
        for (auto v:adj[u]) {
            if (v==p) continue;
            if (dist[v]+1 < mn.fi) {
                mn.se = mn.fi;
                mn.fi = dist[v]+1;
            }
            else if (dist[v]+1 < mn.se) {
                mn.se = dist[v]+1;
            }
        }
        if (mn.fi + mn.se - 1 <= k) {
            state[u] = 1;
        }
        if (state[u]) {
            dist[u] = 0;
        }
        else {
            dist[u] = mn.fi;
        }
    }
}

void solve(){
    cin >> n >> k >> x;
    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(x,0);

    // for (int i=1; i<=n; i++){
    //     cout << ccnt[i] << " " << dist[i] << " " << state[i] << endl;
    // }

    if (ccnt[x] >= 2 && state[x]) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

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

