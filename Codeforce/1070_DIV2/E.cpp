/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "E"

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

/*
    | Segment Tree - Lazy Propagation |
    Desc: Range Update Range Queries in O(n*log(n)).
    Source: KawakiMeido
    State: Untested lmao
*/

struct LazySegmentTree{
    struct Node{
        int val,cnt,mx;
        Node(){
            mx = 0;
            val = LLINF;
            cnt = -1;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;

    LazySegmentTree(int _n) {
        init(_n);
    }

    void propagate(int idx){
        int x = lazy[idx];
        if (x!=-1) {
            //Update idx*2
            IT[idx*2].val = x*IT[idx*2].cnt;
            IT[idx*2].mx = x;
            lazy[idx*2] = x;

            //Update idx*2+1
            IT[idx*2+1].val = x*IT[idx*2+1].cnt;
            IT[idx*2+1].mx = x;
            lazy[idx*2+1] = x;
        }
        //Reset idx
        lazy[idx] = -1;
    }

    Node comb(Node l, Node r){
        if (l.cnt == -1) return r;
        if (r.cnt == -1) return l;

        Node i;
        i.val = l.val + r.val;
        i.cnt = l.cnt + r.cnt;
        i.mx = max(l.mx, r.mx);

        return i;
    }

    void build(int idx, int l, int r){
        lazy[idx] = -1;
        if (l==r){
            IT[idx].val = INF; 
            IT[idx].cnt = 1;
            IT[idx].mx = INF;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int y, int val){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            IT[idx].val = val*IT[idx].cnt;
            IT[idx].mx = val;
            lazy[idx] = val;
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val);
        update(idx*2+1,mid+1,r,x,y,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    Node getNode(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return Node();
        if (x <= l && r <= y){
            return IT[idx];
        }

        propagate(idx);

        int mid = (l+r)/2;
        return comb(getNode(idx*2,l,mid,x,y),getNode(idx*2+1,mid+1,r,x,y));

    }

    void init(int _n){
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, 0);
        build(1,1,n);
    }
};


int n;
int a[N],b[N];
int l[N],r[N];
vector<int> query;

void solve(){
    cin >> n;
    query.clear();
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        query.push_back(x);
    }

    deque<pii> dq;
    for (int i=1; i<=n; i++){
        while (!dq.empty() && dq.back().fi <= a[i]) dq.pop_back();
        if (dq.empty()) l[i] = 1;
        else l[i] = dq.back().se+1;
        dq.push_back({a[i],i});
    }
    dq.clear();
        for (int i=n; i>0; i--){
        while (!dq.empty() && dq.back().fi <= a[i]) dq.pop_back();
        if (dq.empty()) r[i] = n;
        else r[i] = dq.back().se-1;
        dq.push_back({a[i],i});
    }

    // for (int i=1; i<=n; i++){
    //     cout << l[i] << " " << r[i] << endl;
    // }

    LazySegmentTree IT(n);

    vector<pii> v;
    for (int i=1; i<=n; i++){
        v.push_back({b[i],i});
    }

    sort(all(v),greater<pii>());
    for (auto [val,idx]: v){
        IT.update(1,1,n,l[idx],r[idx],val);
        auto node = IT.getNode(1,1,n,1,n);
        // cout << node.val << " cnt:" << node.cnt << endl;
    }

    auto node = IT.getNode(1,1,n,1,n);
    cout << node.val - node.mx << " ";

    for (auto x:query) {
        IT.update(1,1,n,l[x],r[x],0);
        auto node = IT.getNode(1,1,n,1,n);
        cout << node.val - node.mx << " ";
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

