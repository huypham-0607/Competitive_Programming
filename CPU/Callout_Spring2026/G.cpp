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
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 5050;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];
vector<pii> edge;
    
vector<int> parent;

void init(int _n){
    n = _n;
    parent.resize(n+1,0);
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
}

int find(int x){
    return (x == parent[x])? x : parent[x] = find(parent[x]);
}

bool isSame(int u, int v){
    return (find(u) == find(v));
}

void merge(int u, int v){
    int x = find(u);
    int y = find(v);
    if (x!=y){
        parent[y] = x;
    }
}


void solve(){
    cin >> n;
    edge.clear();
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            if (a[i]!=a[j]) edge.push_back({i,j});
        }
    }

    vector<pii> ans;
    int cnt = 0;
    init(n);
    for (auto [u,v]:edge) {
        if (find(u)!=find(v)) {
            ++cnt;
            ans.push_back({u,v});
            merge(u,v);
            if (cnt > n-1){
                cout << "UWU" << endl;
                break;
            }
        }
    }
    if (cnt == n-1) {
        cout << "YES" << endl;
        for (auto [u,v]:ans) cout << u << " " << v << endl;
    }
    else cout << "NO" << endl;
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

