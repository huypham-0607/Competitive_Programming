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
int f[N];
int g[N];
int p[N];

void calcf(int u, int par) {
    p[u] = par;
    f[u] = 1;
    for (auto v:adj[u]) {
        if (v==par) continue;
        calcf(v,u);
        f[u] += f[v];
    }
}

void calcg(int u, int p) {
    int sum = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        sum += f[v];
    }

    for (auto v:adj[u]) {
        if (v==p) continue;
        g[v] = g[u] + 1 + sum - f[v];
        calcg(v,u);
    }
}

int findCentroid(int u, int n, int p=0){
    for (auto v:adj[u]){
        if (v==p) continue;
        if (f[v]>n/2) return findCentroid(v,n,u);
    }
    return u;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n%2) {
        cout << 1 << " " << adj[1][0] << endl; 
        cout << 1 << " " << adj[1][0] << endl; 
        return;
    }

    calcf(1,0);
    calcg(1,0);

    int x = findCentroid(1,n,0);

    // cout << x << endl;

    // for (int i=1; i<=n; i++){
    //     cout << p[i] << endl;
    // }

    for (auto v:adj[x]) {
        if (f[v] == (n+1)/2) {
            if (v==p[x]) continue;
            int tmp = 0;
            for (auto u:adj[v]) {
                if (u==p[v]) continue;
                tmp = u;
            }
            if (tmp) {
                cout << v << " " << tmp << endl;
                cout << tmp << " " << x << endl;
                return;
            }
        }
    }

    if (g[x] == (n+1)/2) {
        if (p[p[x]] != 0) {
            int tmp = p[p[x]];
            cout << p[x] << " " << tmp << endl;
            cout << tmp << " " << x << endl;
            return;
        }
        else {
            int tmp = 0;
            for (auto v:adj[p[x]]) {
                if (v!=x) {
                    tmp = v;
                    break;
                }
            }
            if (tmp!=0) {
                cout << p[x] << " " << tmp << endl;
                cout << tmp << " " << x << endl;
                return;
            }
        }
    }

    cout << 1 << " " << adj[1][0] << endl; 
    cout << 1 << " " << adj[1][0] << endl; 
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

