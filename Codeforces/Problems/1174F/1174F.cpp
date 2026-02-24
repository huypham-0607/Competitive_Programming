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

int curpos = 0;
vector<int> order(N);
int parent[N], sz[N], depth[N];
int root[N], pos[N];

void dfsHLD(int u, int p) {
    sz[u] = 1;
    for (auto v:adj[u]) {
        if (v==p) continue;
        parent[v] = u;
        depth[v] = depth[u]+1;
        dfsHLD(v,u);
        sz[u] += sz[v];
    }
}

int chead[N],ctail[N];

void buildHLD(int u, int r) {
    pos[u] = ++curpos;
    order[curpos] = u;
    if (u==r) chead[r] = pos[u];
    ctail[r] = max(ctail[r],pos[u]);
    root[u] = r;
    
    int nxt = 0;

    for (auto v:adj[u]) {
        if (v==parent[u]) continue;
        if (!nxt || sz[nxt] < sz[v]) {
            nxt = v;
        }
    }

    if (nxt) {
        buildHLD(nxt,r);
    }

    for (auto v:adj[u]) {
        if (v==parent[u] || v==nxt) continue;
        buildHLD(v,v);
    }
}

void askd(int u) {
    cout << "d" << " " << u << endl;
    cout.flush();
}

void asks(int u) {
    cout << "s" << " " << u << endl;
    cout.flush();
}

void answer(int u) {
    cout << "!" << " " << u << endl;
    cout.flush();
}

void solve(){
    int cur = 1;

    askd(cur);
    cin >> d;
    

    order.push_back(0);
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

