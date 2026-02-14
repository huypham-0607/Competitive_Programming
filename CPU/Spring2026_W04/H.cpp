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
vector<int> adj[N];
vector<pii> ans;

void dfs(int u, int p, int org, bool isUp) {
    if (u==org) {
        dfs(adj[u][0],u,u,0);
        dfs(adj[u][1],u,u,1);
        return;
    }

    if (isUp) {
        ans.push_back({u,p});
    }
    else {
        ans.push_back({p,u});
    }

    for (auto v:adj[u]) {
        if (v==p) continue;
        dfs(v,u,org,!isUp);
    }
}

void solve(){
    cin >> n;
    ans.clear();
    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for (int i=1; i<=n; i++){
        if (adj[i].size() == 2) {
            dfs(i,0,i,0);
            cout << "YES" << endl;
            for (auto [u,v]:ans) {
                cout << u << " " << v << endl;
            }
            return;
        }
    }
    
    cout << "NO" << endl;
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

