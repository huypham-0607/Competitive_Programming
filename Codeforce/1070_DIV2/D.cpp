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
const int MD = 998244353;
const long long LLINF = 1e18;

//Starts here

int n,m;
int a[N];
vector<pii> edges;
vector<pii> ve;
vector<int> adj[N];
int deg[N];
set<int> st;
map<int,int> nxt[N];

void solve(){
    cin >> n >> m;
    edges.clear();
    ve.clear();
    for (int i=1; i<=n; i++){
        adj[i].clear();
        deg[i] = 0;
        nxt[i].clear();
    }
    st.clear();
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        ve.push_back({a[i],i});
        st.insert(a[i]);
    }
    sort(all(ve));
    for (int i=1; i<=m; i++){
        int x,y; cin >> x >> y;
        x = lower_bound(all(ve),make_pair(a[x],x)) - ve.begin()+1;
        y = lower_bound(all(ve),make_pair(a[y],y)) - ve.begin()+1;
        edges.push_back({x,y});
    }

    int ans = 0;

    for (int i=1; i<=n; i++){
        a[i] = ve[i-1].fi;
    }
    for (auto [u,v]:edges) {
        if (u < v && a[u] < a[v]) {
            adj[u].push_back(v);
            deg[v]++;
        }
        if (u!=v) {
            ++ans;
            int sum = a[u] + a[v];
            if (sum <= LLINF && st.count(sum)) {
                nxt[v][sum]++;
            }
        }
    }

    priority_queue<int,vector<int>,greater<int>> q;
    for (int i=1; i<=n; i++){
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.top();
        q.pop();

        for (auto v:adj[u]) {
            int val = a[v];

            if (nxt[u].count(val)){
                int cnt = nxt[u][val];
                ans = (ans + cnt)%MD;
                int sum = a[u] + val;
                if (sum <= LLINF && st.count(sum)) {
                    nxt[v][sum] = (nxt[v][sum] + cnt)%MD;
                }
            }

            --deg[v];
            if (!deg[v]) q.push(v);
        }
    }
    
    cout << ans << endl;
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

