/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "2152G"

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

const int N = 250000+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

struct LazySegmentTree{
    struct Node{
        vector<int> cnt;
        vector<vector<int>> state;
        Node(){
            cnt.resize(2,0);
            state.resize(2,vector<int>(2,0));
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;

    void apply(int idx) {
        swap(IT[idx].cnt[0],IT[idx].cnt[1]);
        swap(IT[idx].state[0],IT[idx].state[1]);
        lazy[idx] = (lazy[idx]+1)%2;
    }

    void propagate(int idx){
        if (lazy[idx] == 1) {
            //Update idx*2
            apply(idx*2);

            //Update idx*2+1
            apply(idx*2+1);
        }
        //Reset idx
        lazy[idx] = 0;
    }

    void comb(Node& i, Node& l, Node& r){
        for (int idx=0; idx<2; idx++){
            i.cnt[idx] = l.cnt[idx] + r.cnt[idx];
            i.state[idx][0] = l.state[idx][0];
            if (!l.state[idx][1] && !l.cnt[idx]) i.state[idx][0] = max(i.state[idx][0],r.state[idx][0]);
            i.state[idx][1] = r.state[idx][1];
            if (!r.state[idx][0] && !r.cnt[idx]) i.state[idx][1] = max(i.state[idx][1],l.state[idx][1]);
            if (l.state[idx][1] && r.state[idx][0]) ++i.cnt[idx];
        }
    }

    LazySegmentTree(int _n, int a[]) {
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, 0);
        build(1,1,n,a);
    }

    void build(int idx, int l, int r, int a[]){
        if (l==r){
            int place = a[l]/2;
            int x = a[l]%2;
            IT[idx].state[place][x] = 1;
            return;
            // cout << "Node: " << l << " " << r << endl;
            // cout << IT[idx].cnt[0] << " " << IT[idx].state[0][0] << " " << IT[idx].state[0][1] << endl;
            // cout << IT[idx].cnt[1] << " " << IT[idx].state[1][0] << " " << IT[idx].state[1][1] << endl;
        }


        int mid = (l+r)/2;
        build(idx*2,l,mid,a);
        build(idx*2+1,mid+1,r,a);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
            // cout << "Node: " << l << " " << r << endl;
            // cout << IT[idx].cnt[0] << " " << IT[idx].state[0][0] << " " << IT[idx].state[0][1] << endl;
            // cout << IT[idx].cnt[1] << " " << IT[idx].state[1][0] << " " << IT[idx].state[1][1] << endl;
    }

    void update(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            apply(idx);
            // cout << "Node: " << l << " " << r << endl;
            // cout << IT[idx].cnt[0] << " " << IT[idx].state[0][0] << " " << IT[idx].state[0][1] << endl;
            // cout << IT[idx].cnt[1] << " " << IT[idx].state[1][0] << " " << IT[idx].state[1][1] << endl;
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y);
        update(idx*2+1,mid+1,r,x,y);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
        // cout << "Node: " << l << " " << r  << endl;
        // cout << IT[idx].cnt[0] << " " << IT[idx].state[0][0] << " " << IT[idx].state[0][1] << endl;
        // cout << IT[idx].cnt[1] << " " << IT[idx].state[1][0] << " " << IT[idx].state[1][1] << endl;
    }

    int getVal(int idx, int l, int r, int x, int y, int place){
        if (y < l || r < x) return 0;
        if (x <= l && r <= y){
            return IT[idx].cnt[place];
        }

        propagate(idx);

        int mid = (l+r)/2;
        return getVal(idx*2,l,mid,x,y,place)+getVal(idx*2+1,mid+1,r,x,y,place);

    }
};

int n,q;
int a[N];
int order[2*N];
int tin[N],tout[N];
vector<int> adj[N];

void dfs(int u, int p, int& timedfs){
    order[++timedfs] = 1+2*a[u];
    tin[u] = timedfs;

    for (auto v:adj[u]) {
        if (v==p) continue;
        dfs(v,u,timedfs);
    }

    order[++timedfs] = 2*a[u];
    tout[u] = timedfs;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timedfs = 0;
    dfs(1,0,timedfs);
    LazySegmentTree IT(timedfs,order);
    // for (int i=1; i<=n; i++){
    //     cout << tin[i] << " " << tout[i] << endl;
    // }
    // for (int i=1; i<=timedfs; i++){
    //     cout << order[i] << " ";
    // }
    // cout << endl;
    cout << IT.getVal(1,1,timedfs,1,timedfs,1) << endl;
    cin >> q;
    while (q--){
        int x; cin >> x;
        IT.update(1,1,timedfs,tin[x],tout[x]);
        cout << IT.getVal(1,1,timedfs,1,timedfs,1) << endl;
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

