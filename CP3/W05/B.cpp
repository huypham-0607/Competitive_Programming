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

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
vector<int> adj[N];
int bcnt[N];
int dp[N];
int c[N];
int mul[N];


void DFS(int u, int p) {
    bcnt[u] = (c[u]? 1 : 0);
    
    int m = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        DFS(v,u);
        bcnt[u] += bcnt[v];
        if (bcnt[v]) ++m;
    }

    // cout << "IDX: " << u << endl;
    if (!bcnt[u]) {
        return;
    }

    vector<int> pref(m+2);
    vector<int> suf(m+2);
    vector<int> mullocal(m+2);
    pref[0] = pref[m+1] = 1;
    suf[0] = suf[m+1] = 1;

    int idx = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        if (!bcnt[v]) continue;
        ++idx;
        pref[idx] = dp[v];
        mullocal[idx] = mul[v];
    }

    for (int i=m; i>0; i--){
        suf[i] = (pref[i]*suf[i+1])%MD;
    }
    for (int i=1; i<=m; i++){
        pref[i] = (pref[i]*pref[i-1])%MD;
    }

    // for (int i=1; i<=m; i++){
        // cout << pref[i] << " " << suf[i] << " " << mullocal[i] << endl;
    // }

    if (m == 0) {
        mul[u] = 1;
    }
    else if (m == 1) {
        if (c[u]) {
            mul[u] = pref[1]; 
        }
        else {
            mul[u] = mullocal[1];
            dp[u] = pref[1];
        }
    }
    else {
        if (c[u]) {
            mul[u] = pref[m];
        }
        else {
            dp[u] += pref[m];
            for (int i = 1; i<=m; i++){
                
                mul[u] = (mul[u] + (pref[i-1]*suf[i+1]%MD*mullocal[i]%MD))%MD;
            }
        }
    }
    dp[u] = (dp[u]+mul[u]);
}

void solve(){
    cin >> n;
    for (int u=2; u<=n; u++){
        int v; cin >> v;
        ++v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for (int i=1; i<=n; i++){
        cin >> c[i];
    }
    
    int pivot = 0;
    for (int i=1; i<=n; i++){
        if (c[i] == 1) {
            pivot = i;
            DFS(i,0);
            break;
        }
    }

    // cout << pivot << endl;
    // for (int i=1; i<=n; i++){
    //     cout << dp[i] << " " << mul[i] << endl;
    // }
    // for (int i=1; i<=n; i++){
    //     cout << bcnt[i] << endl;
    // }
    cout << dp[pivot] << endl;
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

