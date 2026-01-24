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

struct DSU{
    int n;
    vector<int> parent;

    void Init(int _n){
        n = _n;
        parent.resize(n,0);
        for (int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int Find(int x){
        return (x == parent[x])? x : parent[x] = Find(parent[x]);
    }

    bool IsSame(int u, int v){
        return (Find(u) == Find(v));
    }

    void Union(int u, int v){
        int x = Find(u);
        int y = Find(v);
        if (x!=y){
            parent[y] = x;
        }
    }
};

int n,m;
int SOScnt[(1<<22)+10];
int SOS[(1<<22)+10];
vector<int> v;

void solve(){
    cin >> n >> m;
    DSU dsu;
    dsu.Init((1<<n));
    for (int mask=0; mask<(1<<n); mask++){
        SOS[mask] = -1;
    }
    for (int i=1; i<=m; i++){
        int x; cin >> x;
        v.push_back(x);
        SOS[x] = x;
        SOScnt[x^((1<<n)-1)] = 1;
    }

    for (int lg=0; lg<n; lg++){
        for (int mask=(1<<n)-1; mask>=0; mask--){
            if (!(mask&(1<<lg))) SOScnt[mask] = SOScnt[mask] + SOScnt[mask^(1<<lg)];
        }
    }

    int ans = m;

    for (int lg=0; lg<n; lg++){
        for (int mask=0; mask<(1<<n);mask++){
            if (mask&(1<<lg)) {
                if (SOScnt[mask]!=0) {
                    int x = SOS[mask];
                    int y = SOS[mask^((1<<lg))];
                    if (x != -1 && y!=-1) {
                        if (!dsu.IsSame(x,y)) {
                            --ans;
                            dsu.Union(x,y);
                        }
                    }
                }
                SOS[mask] = max(SOS[mask],SOS[mask^(1<<lg)]);
            }
        }
    }

    for (auto x:v){
        int adj = SOS[x^((1<<n)-1)];
        if (adj == -1) continue;
        if (!dsu.IsSame(x,adj)) {
            --ans;
            dsu.Union(x,adj);
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

