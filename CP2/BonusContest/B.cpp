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

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e12+10;

//Starts here

int n;
int deg[N];
int w[N];
int f[3][N];
vector<int> adj[N];

void calcf(int u, int p) {
    for (auto v:adj[u]){
        if (v==p) continue;
        calcf(v,u);
    }
    int cnt = 0;

    f[2][u] = w[u];
    for (auto v:adj[u]) {
        if (v==p) continue;
        ++cnt;
        f[0][u] += f[1][v];
        f[2][u] += min(f[0][v], f[1][v]);
    }
    if (cnt == 0) {
        f[0][u] = 0;
    }

    f[1][u] = LLINF;

    vector<int> pref(cnt+2,0),suf(cnt+2,0);
    int idx = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        ++idx;
        pref[idx] = min(f[1][v], f[2][v]);
        suf[idx] = min(f[1][v], f[2][v]);
    }
    for (int i=1; i<=cnt; i++){
        pref[i] += pref[i-1];
    }
    for (int i=cnt; i>0; i--){
        suf[i] += suf[i+1];
    }

    idx = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        ++idx;
        f[1][u] = min(f[1][u], f[2][v] + pref[idx-1] + suf[idx+1]);
    }
}

void solve(){
    cin >> n;
    for (int u=1; u<=n; u++){
        int cnt; cin >> w[u] >> cnt;
        for (int i=0; i<cnt; i++) {
            int v; cin >> v;
            ++v;
            ++deg[v];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    int root = 0;

    // for (int i=1; i<=n; i++){
    //     cout << deg[i] << " ";
    // }
    // cout << endl;

    for (int i=1; i<=n; i++){
        if (deg[i] == 0){
            root = i;
            break;
        }
    }

    calcf(root,0);

    // cout << root << endl;

    // for (int i=1; i<=n; i++){
    //     for (int idx=0; idx<=2; idx++){
    //         cout << f[idx][i] << " ";
    //     }
    //     cout << endl;
    // }

    cout << min(f[1][root],f[2][root]) << endl;
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
