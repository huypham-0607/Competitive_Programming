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
vector<pii> node;
int depth[N];

void dfs(int u, int p) {
    depth[u] = depth[p]+1;
    node.push_back({depth[u],u});
    for (auto v:adj[u]) {
        if (v==p) continue;
        dfs(v,u);
    }
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    node.clear();
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(n,0);
    sort(all(node),greater<pii>());
    int parity = depth[1]%2;
    vector<pii> ans;
    for (auto [d,u]:node) {
        if (u==n) continue;
        ans.push_back({1,0});
        parity = (parity+1)%2;
        if (d%2==parity) {
            ans.push_back({1,0});
            parity = (parity+1)%2;
        }
        ans.push_back({2,u});
    }
    cout << ans.size() << endl;
    for (auto [id,val]:ans) {
        if (id==1) cout << 1 << endl;
        else {
            cout << 2 << " " << val << endl;
        }
    }
    // cout << endl;
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

