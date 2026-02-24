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

const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int ptr[N];
vector<pii> adj[N];
int a[2][N];
int marked[N];
int ans[N];
int freq[N];

void findEuler(int u) {
    while (ptr[u]!=adj[u].size()) {
        int id = adj[u][ptr[u]].fi;
        int tpe = adj[u][ptr[u]].se;
        ++ptr[u];
        if (!marked[id]) {
            ans[id] = tpe;
            marked[id] = 1;
            findEuler(a[tpe^1][id]);
        }
    }
    // cout << u << endl;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        freq[i] = 0;
        adj[i].clear();
        marked[i] = 0;
        ans[i] = 0;
        ptr[i] = 0;
    }
    for (int i=1; i<=n; i++){
        cin >> a[0][i];
        freq[a[0][i]]++;
    }
    for (int i=1; i<=n; i++) {
        cin >> a[1][i];
        // cout << a[0][i] << " " << a[1][i] << endl;
        freq[a[1][i]]++;
    }
    for (int i=1; i<=n; i++){
        if (freq[i]%2) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i=1; i<=n ;i++){
        adj[a[0][i]].push_back({i,0});
        adj[a[1][i]].push_back({i,1});
    }
    for (int i=1; i<=n; i++){
        if (!marked[i]) {
            findEuler(a[0][i]);
        }
    }
    int cnt = 0;
    for (int i=1; i<=n; i++){
        if (ans[i]) ++cnt;
    }
    cout << cnt << endl;
    for (int i=1; i<=n; i++){
        if (ans[i]) cout << i << " ";
    }
    cout << endl;
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

