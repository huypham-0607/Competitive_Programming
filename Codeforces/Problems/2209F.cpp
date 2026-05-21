/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
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

const int N = 3e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k;
int a[N];
vector<int> adj[N];

bool cmp(pii u, pii v) {
    if (u.fi == v.fi) {
        return u.se < v.se;
    }
    else return (u.fi > v.fi);
}

int leaf[N];
pii f[N];
pii g[N];

void calcf(int u, int p) {
    if (leaf[u]) f[u] = {0,u};

    for (auto v:adj[u]) {
        if (v==p) continue;
        calcf(v,u);
        pii tmp = f[v]; tmp.fi++;
        f[u] = (cmp(tmp,f[u]))?tmp:f[u];
    }
}

void upt(pair<pii,pii> &in, pii u) {
    if (cmp(u,in.fi)) {
        in.se = in.fi;
        in.fi = u;
    }
    else if(cmp(u,in.se)) in.se = u;
}

void calcg(int u, int p){
    pair<pii,pii> in = {{g[u].fi+1,g[u].se},{-INF,INF}};
    if (leaf[u]) upt(in,make_pair(0,u));

    for (auto v:adj[u]) {
        if (v==p) continue;
        upt(in,make_pair(f[v].fi+1,f[v].se));
    }

    for (auto v:adj[u]) {
        if (v==p) continue;
        if (make_pair(f[v].fi+1,f[v].se) == in.fi) g[v] = in.se;
        else g[v] = in.fi;
        calcg(v,u);
    }
}

priority_queue<pair<pii,int>> suf;
priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>>> pref;
int ans;
int ver;
int last[N];
int val[N];
int ispref[N];

void add_pq(int u) {
    while (!pref.empty() && pref.top().se < last[pref.top().fi.se]) pref.pop();
    while (!suf.empty() && suf.top().se < last[suf.top().fi.se]) suf.pop();
    if (pref.size() < k) {
        ispref[u] = 1;
        ans += val[u];
        pref.push({{val[u],u},last[u]});
        return;
    }

    if (!pref.empty() && val[u] > pref.top().fi.fi) {
        auto in = pref.top(); pref.pop();

        ispref[in.fi.se] = 0;
        ans -= in.fi.fi;
        suf.push(in);

        ispref[u] = 1;
        ans += val[u];
        pref.push({{val[u],u},last[u]});
    }
    else {
        ispref[u] = 0;
        suf.push({{val[u],u},last[u]});
    }
}

void rm_pq(int u) {
    while (!pref.empty() && pref.top().se < last[pref.top().fi.se]) pref.pop();
    while (!suf.empty() && suf.top().se < last[suf.top().fi.se]) suf.pop();

    if (ispref[u]) {
        ispref[u] = 0;
        ans -= val[u];
        if (!suf.empty()) {
            auto in = suf.top(); suf.pop();
            while (!suf.empty() && suf.top().se < last[suf.top().fi.se]) suf.pop();

            ispref[in.fi.se] = 1;
            ans += in.fi.fi;
            pref.push(in);
        }
    }
}

void upt_pq(int u, int delta) {
    ++ver;
    last[u] = ver;

    rm_pq(u);
    val[u] += delta;
    add_pq(u);
}

int res = 0;

void DFS(int u, int p){
    res = max(res,a[u] + ans);
    // cout << u << endl;
    // for (int i=1; i<=n; i++){
    //     cout << ispref[i] << " ";
    // }
    // cout << endl;
    // for (int i=1; i<=n; i++){
    //     cout << val[i] << " ";
    // }
    // cout << endl << endl;

    for (auto v:adj[u]) {
        if (v==p) continue;
        upt_pq(g[v].se,a[u]);
        upt_pq(f[v].se,-a[v]);
        DFS(v,u);
        upt_pq(g[v].se,-a[u]);
        upt_pq(f[v].se,a[v]);
    }
}

void solve(){
    cin >> n >> k;
    ffor(i,1,n){
        cin >> a[i];
        adj[i].clear();
    }
    for (int i=1; i<n; i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ffor(u,1,n){
        if (adj[u].size()==1) leaf[u]=1;
        f[u] = g[u] = {-INF,INF};
    }

    calcf(1,0);
    calcg(1,0);

    while (!pref.empty()) pref.pop();
    while (!suf.empty()) suf.pop();

    for (int i=1; i<=n; i++){
        last[i] = 0;
        val[i] = 0;
        ispref[i] = 0;
    }

    for (int i=2; i<=n; i++){
        val[f[i].se] += a[i];
    }

    // for (int i=1; i<=n; i++){
    //     cout << f[i].se << " " << g[i].se << endl;
    // }

    ans = 0;
    ver = 0;
    res = 0;
    --k;
    for (int i=1; i<=n; i++){
        add_pq(i);
    }

    DFS(1,0);

    cout << res << endl;
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

