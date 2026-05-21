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

int n,m,k,root;
vector<int> adj[N];
int has_racer[N];
int speed[N];
int ans[N];
int is_special[N];
int depth[N];

bool compare(pii x, pii y, int pivot) {
    pii a = {(x.fi - pivot)*speed[x.se],speed[x.fi]};
    pii b = {(y.fi - pivot)*speed[y.se],speed[y.se]};

    return (a < b);
}

vector<pii> *DFS(int u, int p) {
    depth[u] = depth[p]+1;
    vector<pii> *cur = new vector<pii>();

    if (has_racer[u] != 0) {
        cur->push_back({depth[u],has_racer[u]});
    }

    vector<vector<pii>*> child;
    
    for (auto v:adj[u]) {
        if (v==p) continue;
        vector<pii>* tmp = DFS(v,u);
        if (tmp->size() > cur->size()) {
            swap(tmp,cur);
        }
        child.push_back(tmp);
    }

    for (auto it:child) {
        for (auto x:(*it)) {
            cur->push_back(x);
        }
    }

    if (is_special[u]) {
        vector<pii>* res = new vector<pii>();

        for (int i = 0; i < cur->size(); i++){
            res->push_back((*cur)[i]);
            int idx = res->size()-1;
            while (idx!=0 && compare((*res)[idx], (*res)[idx-1], depth[u])) {
                swap((*res)[idx],(*res)[idx-1]);
                --idx;
            }

            // while (idx!=0 && ((*res)[idx].fi-depth[u])*speed[(*res)[idx].se]
            //         < ((*res)[idx-1].fi-depth[u])*speed[(*res)[idx-1].se]) {

            // }
            if (res->size() > k) res->pop_back();
        }

        swap(cur,res);
    }

    // cout << "Node: " << u << "\n";
    // for (int i=0; i<cur->size(); i++){
    //     cout << (*cur)[i].se << " ";
    // }
    // cout << endl;

    return cur;
}

void solve(){
    cin >> n >> m >> k;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=m; i++){
        int p,v; cin >> p >> v;
        ans[i] = -1;
        has_racer[p] = i;
        speed[i] = v;
    }
    cin >> root;
    int x; cin >> x;
    for (int i=1; i<=x; i++){
        int p; cin >> p;
        is_special[p] = 1;
    }
    
    vector<pii>* res = DFS(root,0);
    for (int i=0; i<res->size(); i++) {
        ans[(*res)[i].se] = ((*res)[i].fi - depth[root])*speed[(*res)[i].se];
    }

    for (int i=1; i<=m; i++){
        cout << ans[i] << endl;
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

