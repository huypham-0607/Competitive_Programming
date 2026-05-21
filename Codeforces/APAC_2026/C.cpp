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
typedef pair<pii, int> piii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
vector<pii> adj[N];
vector<piii> edges;
int ecnt[N];
int deg[N];
int ord[N];
int ans[N];
int vis[N];

void solve(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        if (u > v) swap(u,v);
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        ++ecnt[u];
        ++ecnt[v];
        edges.push_back({{u,v},i});
    }
    sort(all(edges));
    for (int i=1; i<=n; i++){
        cin >> ord[i];
    }

    if (ord[1] != 1) {
        cout << "impossible" << endl;
        return;
    }

    int assw = 100000000;

    stack<int> st;
    st.push(1);
    for (auto [v,id]:adj[1]) {
        deg[v]++;
    }
    vis[1] = 1;
    for (int i=2; i<=n; i++){

        while (!st.empty() && deg[st.top()] == ecnt[st.top()]) {
            st.pop();
        }

        int u = st.top();
        pii e = {u,ord[i]};
        // cerr << "edge: " << e.fi << " " << e.se << " " << deg[e.fi] <<  endl;
        
        if (e.fi > e.se) swap(e.fi,e.se);

        piii tmp = make_pair(e,0);
        int idx = lower_bound(all(edges),tmp) - edges.begin();
        if (idx == edges.size() || edges[idx].fi != e) {
            cout << "impossible" << endl;
            return;
        }
        ans[edges[idx].se] = assw--;

        st.push(ord[i]);
        for (auto [v,id]:adj[ord[i]]) {
            deg[v]++;
        }
        vis[ord[i]] = 1;
    }

    for (int i=0; i<m; i++){
        if (!ans[i]) ans[i] = 1;
    }

    for (int i=0; i<m; i++){
        cout << ans[i] << " ";
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
