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
int depth[N], max_depth[N];;
int ans = 0;

void DFS(int u, int p) {
    ++ans;
    depth[u] = depth[p]+1;
    max_depth[u] = depth[u];
    int ccnt = 0;
    pii mx = {depth[u],depth[u]};
    for (auto v:adj[u]) {
        if (v==p) continue;
        ++ccnt;
        DFS(v,u);
        max_depth[u] = max(max_depth[u],max_depth[v]);
        if (mx.fi < max_depth[v]) {
            mx.se =  mx.fi;
            mx.fi = max_depth[v];
        }
        else if (mx.se < max_depth[v]) {
            mx.se = max_depth[v];
        }
    }
    if (ccnt>1) ans += mx.se - depth[u];
    // cout << u << " " << ccnt << " " << mx.se << " " << ans << endl;
}

void solve(){
    cin >> n;
    ffor(i,1,n) adj[i].clear();
    ffor(i,2,n) {
        int j; cin >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    ans = 0; DFS(1,0);
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

