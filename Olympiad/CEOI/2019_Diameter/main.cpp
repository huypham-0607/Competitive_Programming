/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,q,W;
vector<int> adj[N];

struct Node{
    int ans,mxhi,mxlo,head,length;
    Node(int _ans = 0, int _mxhi = 0, int _mxlo = 0, int _head = 0, int _length = 0){
        ans = _ans;
        mxhi = _mxhi;
        mxlo = _mxlo;
        head = _head;
        length = _length;
    }

    void init(int _ans, int _mxhi, int _mxlo, int _head, int _length){
        ans = _ans;
        mxhi = _mxhi;
        mxlo = _mxlo;
        head = _head;
        length = _length;
    }

    friend Node comb(Node l, Node r) {
        if (l.ans == -1) return r;
        if (r.ans == -1) return l;
        Node i;
        i.head = l.head;
        i.length = l.length + r.head + r.length;
        i.mxhi = max(l.mxhi, r.mxhi + r.head + l.length);
        i.mxlo = max(r.mxlo, l.mxlo + r.head + r.length);
        i.ans = max({l.ans, r.ans, l.mxlo + r.head + r.mxhi});
        return i;
    }
};

struct SegmentTree{
    int n;
    vector<Node> IT;

    void update(int idx, int l, int r, int x, Node val){
        if (r < x || x < l) return;
        if (l==r){
            IT[idx] = val;
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val);
        update(idx*2+1,mid+1,r,x,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    Node get(int idx, int l, int r, int x, int y){
        if (r < x || y < l) return Node(-1);
        if (x <= l && r <= y) return IT[idx];
        int mid = (l+r)/2;
        return comb(
            get(idx*2,l,mid,x,y),
            get(idx*2+1,mid+1,r,x,y));
    }

    void Init(int _n){
        n = _n;
        IT.resize(4*n+10);
    }
} ST;

//HLD
int curpos = 0;
int parent[N], sz[N], depth[N];
int root[N], pos[N];
int posmax[N];
set<pii,greater<pii>> mxlen[N], mxans[N];
pii smxlen[N], smxans[N];

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
    posmax[r] = pos[u];
    root[u] = r;

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

void updateHLD(int x, int w){
//    cout << "HLD: " << x << " " << w << endl;
    Node tmp = ST.get(1,1,n,pos[x],pos[x]);
    tmp.head = w;
    ST.update(1,1,n,pos[x],tmp);
    int u = x;
    while (root[u]!=1){
//        cout << u << ":" << endl;
        tmp = ST.get(1,1,n,pos[root[u]],posmax[root[u]]);
        int v = parent[root[u]];
        mxlen[v].erase(smxlen[root[u]]);
        mxans[v].erase(smxans[root[u]]);
        smxlen[root[u]] = {tmp.mxhi+tmp.head,root[u]};
        smxans[root[u]] = {tmp.ans,root[u]};
        mxlen[v].insert(smxlen[root[u]]);
        mxans[v].insert(smxans[root[u]]);

        tmp = ST.get(1,1,n,pos[v],pos[v]);
        int mx1 = 0, mx2 = 0, mxans1;
        if (mxlen[v].size() >= 1) mx1 = (*mxlen[v].begin()).fi;
        if (mxlen[v].size() >= 2) mx2 = (*(++mxlen[v].begin())).fi;
        if (mxans[v].size() >= 1) mxans1 = (*mxans[v].begin()).fi;
//        cout << mx1 << " " << mx2 << " " << mxans1 << endl;
        tmp.mxlo = tmp.mxhi = mx1;
        tmp.ans = max(mxans1,mx1+mx2);
        ST.update(1,1,n,pos[v],tmp);
        u = v;
    }
}

int getHLD(){
    Node tmp = ST.get(1,1,n,pos[1],posmax[1]);
    return tmp.ans;
}

vector<pair<pii,int>> edge;

/*Solution*/
void solve(){
    cin >> n >> q >> W;
    for (int i=1; i<n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.push_back({{u,v},w});
    }
    dfsHLD(1);
    buildHLD(1,1);

    ST.Init(n);

    for (auto [uv,w]:edge){
        auto [u,v] = uv;
        if (pos[u] > pos[v]) updateHLD(u,w);
        else updateHLD(v,w);
    }

//    for (int i=1; i<=n; i++){
//        Node tmp = ST.get(1,1,n,pos[i],pos[i]);
//        cout << tmp.ans << " " << tmp.head << " " << tmp.length << " " << tmp.mxhi << " " << tmp.mxlo << endl;
//    }

    int lastans = 0;
    while (q--){
        int id, w; cin >> id >> w;
        id = (id+lastans)%(n-1);
        w = (w+lastans)%W;
        int u = edge[id].fi.fi;
        int v = edge[id].fi.se;
        if (pos[u] > pos[v]) updateHLD(u,w);
        else updateHLD(v,w);
        int ans = getHLD();
        cout << ans << endl;
        lastans = ans;
    }

//    for (int i=1; i<=n; i++){
//        cout << i << " " << pos[i] << " " << root[i] << endl;
//    }
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
