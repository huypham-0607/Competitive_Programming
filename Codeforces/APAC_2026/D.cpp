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

struct SegmentTree{
    struct Node {
        int dp, delta;
        Node() {
            dp = -1;
            delta = -1;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node r, Node l){
        Node i = Node();
        if (l.delta == -1) return r;
        if (r.delta == -1) return l;
        if (l.dp > r.delta) {
            i.dp = l.dp + r.dp - r.delta;
            i.delta = l.delta;
        }
        else {
            i.dp = r.dp;
            i.delta = l.delta + r.delta - l.dp;
        }
        return i;
    }

    void init(int _n) {
        n = _n;
        IT.clear();
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        // cerr << l << " " << r << endl;
        if (l==r){
            IT[idx].dp = 0;
            IT[idx].delta = 0;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int a, int res){
        if (r < x || x < l) return;
        if (l==r){
            if (a > res) {
                IT[idx].dp = a;
                IT[idx].delta = a - res;
            }
            else {
                IT[idx].dp = res;
                IT[idx].delta = 0;
            }
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,a,res);
        update(idx*2+1,mid+1,r,x,a,res);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    Node getNode(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return Node();
        if (x <= l && r <= y){
            return IT[idx];
        }

        int mid = (l+r)/2;
        return comb(getNode(idx*2,l,mid,x,y),getNode(idx*2+1,mid+1,r,x,y));
    }
} IT;


int n,q;
int a[N];
vector<int> adj[N];

int curpos = 0;
int parent[N], sz[N], depth[N];
int root[N], pos[N], ctail[N], chead[N];
int residue[N], cval[N];

void dfsHLD(int u, int p=0){
    sz[u] = 1;
    for (auto v:adj[u]){
        if (v==p) continue;
        parent[v] = u;
        depth[v] = depth[u]+1;
        dfsHLD(v,u);
        sz[u] += sz[v];
    }
}

void buildHLD(int u, int r){
    pos[u] = ++curpos;
    root[u] = r;
    ctail[r] = max(ctail[r],pos[u]);
    chead[r] = min(chead[r],pos[u]);

    int nxt = 0;

    for (auto v:adj[u]){
        if (v==parent[u]) continue;
        if (!nxt || sz[v]>sz[nxt]) nxt = v;
    }

    if (nxt){
        buildHLD(nxt,r);
    }

    for (auto v:adj[u]){
        if (v==parent[u] || v==nxt) continue;
        buildHLD(v,v);
    }
}

void updateHLD(int x, int val){
    // cout << "uptHLD: " << x << " " << val << endl;
    int u = x;

    a[u] = val;
    IT.update(1,1,n,pos[u],a[u],residue[u]);

    while (root[u]!=1){
        int v = parent[root[u]];
        
        auto mx = IT.getNode(1,1,n,chead[root[u]],ctail[root[u]]);

        residue[v] = residue[v] - cval[root[u]] + mx.dp;
        cval[root[u]] = mx.dp;

        // cout << "u: " << u << " " << root[u] << endl;
        // cout << chead[root[u]] << " " << ctail[root[u]] << endl;
        // cout << mx.dp << " " << mx.delta << endl;
        // cout << cval[root[u]] << endl;

        IT.update(1,1,n,pos[v],a[v],residue[v]);

        u = v;
    }
}

int queryHLD() {
    auto tmp = IT.getNode(1,1,n,chead[root[1]],ctail[root[1]]);
    return tmp.dp;
}

void solve(){
    cin >> n >> q;
    curpos = 0;
    for (int i=1; i<=n; i++){
        adj[i].clear();
        root[i] = 0;
        pos[i] = 0;
        ctail[i] = 0;
        chead[i] = INF;
        residue[i] = 0;
        cval[i] = 0;
    }
    for (int u=2; u<=n; u++){
        int v; cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // cerr << n << " " << q << endl;

    dfsHLD(1,0);
    buildHLD(1,1);
    IT.init(n);
    // for (int i=1; i<=n; i++){
    //     cout << chead[i] << " " << ctail[i] << endl;
    // }
    for (int i=1; i<=n; i++){
        cin >> a[i];
        updateHLD(i,a[i]);
        // auto tmp = IT.getNode(1,1,n,chead[root[1]],ctail[root[1]]);
        // cout << "tmp: " << tmp.dp << " " << tmp.delta << endl;
        // auto tmp2 = IT.getNode(1,1,n,pos[1],pos[1]);
        // cout << "tmp2: " << tmp.dp << " " << tmp.delta << endl;
        // cout << IT.getNode(1,1,n,pos[3],pos[3]).dp << " " <<IT.getNode(1,1,n,pos[3],pos[3]).delta;
    }

    cout << queryHLD() << endl;
    for (int i=1; i<=q; i++){
        int x,w; cin >> x >> w;
        updateHLD(x,w);
        cout << queryHLD() << endl;
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

