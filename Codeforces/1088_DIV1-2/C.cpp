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

int n,k;
int a[N];
int b[N];
int mark[N];
int cnta[N];
int cntb[N];
int col[N];

struct DSU{
    int n;
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
} DSU;

void solve(){
    cin >> n >> k;
    DSU.init(n);
    for (int i=1; i<=n; i++){
        cnta[i] = cntb[i] = 0;
        col[i] = -1;
        mark[i] = 0;
    }
    for (int i=1; i<=n; i++){
        cin >> a[i];
    } 
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }


    queue<pii> q;
    for (int i=k+1; i<=n; i++){
        if (a[i] != a[i-k]) {
            mark[i] = true;
            q.push({i,a[i]});
            q.push({i-k,a[i-k]});
        }
        else {
            DSU.merge(i,i-k);
        }
    }

    while (!q.empty()) {
        auto [i,x] = q.front(); q.pop();
        if (b[i] != -1 && x != b[i]) {
            cout << "NO" << endl;
            return;
        }
        b[i] = x;
    }

    // for (int i=1; i<=n; i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;

    // cout << "gawr" << endl;
    
    for (int i=1; i<=n; i++){
        int p = DSU.find(i);
        // cout << p << endl;
        if (col[p] != -1 && b[i] != -1 && col[p] != b[i]) {
            cout << "NO" << endl;
            return;
        }
        if (b[i] != -1) col[p] = b[i];
    }

    // cout << "woof" << endl;
    
    for (int i=1; i<=n; i++){
        int p = DSU.find(i);
        if (col[p]!=-1) b[i] = col[p];

    }

    // for (int i=1; i<=n; i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;

    for (int i=1; i<=k; i++){
        ++cnta[a[i]];
        if (b[i] != -1) ++cntb[b[i]];
    }
    for (int i=1; i<=n; i++){
        if (cntb[i] > cnta[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    // cout << "meow" << endl;

    for (int i=k+1; i<k; i++){
        int va = a[i];
        int vb = b[i];
        int vc = a[i-k];
        int vd = b[i-k];

        cnta[a[i]]++;
        if (b[i] != -1) ++cntb[b[i]];
        cnta[a[i-k]]--;
        if (b[i-k] != -1) cntb[b[i-k]]--;

        if (va!=-1 && cntb[va] > cnta[va]) {
            cout << "NO" << endl;
            return;
        }
        if (va!=-1 && cntb[vb] > cnta[vb]) {
            cout << "NO" << endl;
            return;
        }
        if (va!=-1 && cntb[vc] > cnta[vc]) {
            cout << "NO" << endl;
            return;
        }
        if (va!=-1 && cntb[vd] > cnta[vd]) {
            cout << "NO" << endl;
            return;
        }
    }

    // for (int i=1; i<=n; i++){
    //     cout << cnta[i] << " " << cntb[i] << endl;
    // }
    cout << "YES" << endl;
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

