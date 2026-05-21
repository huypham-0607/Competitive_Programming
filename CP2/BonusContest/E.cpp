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
const int LG = 17;
const int K = 5;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m,k,q;

struct node {
    int k;
    vector<vector<int>> v;

    node(int _k = 1): k(_k) {
        v.resize(k,vector<int>(k,INF));
    }
};

node combine(node a, node b, int k) {
    node res = node(k);
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            res.v[i][j] = INF;
        }
    }
    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++){
            for (int mid=0; mid<k; mid++){
                res.v[i][j] = min(res.v[i][j], a.v[i][mid]+b.v[mid][j]);
            }
        }
    }
    return res;
}

int adj[N][K];
node st[LG][N];

void solve(){
    cin >> k >> n >> m >> q;
    int bound = (n-1)/k+1;
    for (int i=0; i<k*(bound+1); i++){
        for (int j=0; j<k; j++){
            adj[i][j] = INF;
        }
    }
    for (int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u][v%k] = min(adj[u][v%k],w);
    }
    for (int lg=0; lg<LG; lg++){
        st[lg][bound] = node(k);
    }
    for (int i=bound-1; i>=0; i--){
        st[0][i] = node(k);
        for (int u=0; u<k; u++){
            for (int v=0; v<k; v++) {
                st[0][i].v[u][v] = adj[i*k + u][v];
            }
        }

        for (int lg=1; lg<LG; lg++){
            int v = i+(1<<(lg-1));
            st[lg][i] = (v >= bound) ? node(k) : combine(st[lg-1][i],st[lg-1][v],k);
        }
    }

    // for (int i=0; i<bound; i++){
    //     cout << "bound: " << i << endl;
    //     for (int lg=0; lg<LG; lg++){
    //         cout << "lg: " << lg << endl;
    //         for (int u=0; u<k; u++){
    //             for (int v=0; v<k; v++){
    //                 cout << ((st[lg][i].v[u][v] >= INF) ? -1 : st[lg][i].v[u][v]) << " ";
    //             }
    //             cout << endl;
    //         }
    //     }
    //     cout << endl;
    // }

    for (int i=1; i<=q; i++){
        int u,v; cin >> u >> v;
        int du = u%k, dv = v%k;
        u = u/k; v = v/k;
        // cout << u << " " << v << endl;
        // cout << du << " " << dv << endl;
        if (u == v) {
            if (du == dv) cout << 0 << endl;
            else cout << -1 << endl;
            continue;
        }
        int delta = v - u;
        node mat = node(k);
        int cur = u;
        for (int idx=0; idx<k; idx++){
            mat.v[idx][idx] = 0;
        }
        for (int lg = LG-1; lg>=0; lg--){
            if (delta&(1<<lg)) {
                mat = combine(mat,st[lg][cur],k);
                cur = cur + (1<<lg);
            }
        }

        // for (int u=0; u<k; u++){
        //     for (int v=0; v<k; v++){
        //         cout << ((mat.v[u][v] >= INF) ? -1 : mat.v[u][v]) << " ";
        //     }
        //     cout << endl;
        // }

        int res = mat.v[du][dv];
        if (res >= INF) {
            cout << -1 << endl;
        }
        else cout << res << endl;
    }
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

