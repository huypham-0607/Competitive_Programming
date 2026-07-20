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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
vector<int> adj[N];
int f[N];
int g[N];

void calc_f(int u, int p){
    int cnt = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        ++cnt;
        calc_f(v, u);
    }
    if (cnt%2) {
        for (auto v:adj[u]){
            if (v==p) continue;
            f[u] += f[v];
        }
    }
    else f[u] = 1;
}

void calc_g(int u, int p){
    int cnt = (u==1)?0:1;
    int sz = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        ++cnt;
        ++sz;
    }

    vector<int> pref(sz+2,0), suf(sz+2,0);

    int idx = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        ++idx;
        pref[idx] = suf[idx] = f[v];
    }

    ffor(i,1,sz){
        pref[i] += pref[i-1];
    }
    rfor(i,sz,1){
        suf[i] += suf[i+1];
    }
    
    idx = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        ++idx;
        if (cnt%2) {
            g[v] = pref[idx-1]+suf[idx+1]+g[u];
        }
        else {
            g[v] = 1;
        }

        calc_g(v,u);
    }
}

int ans;

void get_ans(int u, int p){
    int cnt = (u==1)?0:1;

    for (auto v:adj[u]){
        if (v==p) continue;
        ++cnt;
    }

    if (cnt%2){
        for (auto v:adj[u]){
            if (v==p) continue;
            ans += f[v];
        }
    }
    else {
        int cum = 0;
        for (auto v:adj[u]){
            if (v==p) continue;
            ans += cum*f[v];
            cum += f[v];
        }
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        get_ans(v,u);
    }
}

void solve(){
    cin >> n;
    ffor (i,1,n) {
        adj[i].clear();
        f[i] = g[i] = 0;
    }
    ffor(i,1,n-1){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = 0;
    calc_f(1,0);
    // ffor(i,1,n){
    //     cout << f[i] << " ";
    // }
    // cout << endl;
    get_ans(1,0);
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

