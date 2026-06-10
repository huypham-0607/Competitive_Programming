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

struct LazySegmentTree{
    struct Node{
        int val,cnt;
        Node(){
            val = LLINF;
            cnt = 0;
        }
        Node(int _val, int _cnt){
            val = _val;
            cnt = _cnt;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;

    void applyAdd(int idx, int val) {
        IT[idx].val = (IT[idx].val + val)%MD;
        lazy[idx] = (lazy[idx] + val)%MD;
    }

    void propagate(int idx){
        int val = lazy[idx];
        //Update idx*2
        applyAdd(idx*2,val);

        //Update idx*2+1
        applyAdd(idx*2+1,val);

        //Reset idx
        lazy[idx] = 0;
    }

    static Node comb(Node l, Node r){
        Node i;
        if (l.val == r.val) {
            i.val = l.val;
            i.cnt = (l.cnt+r.cnt)%MD;
        }
        else {
            i.val = min(l.val,r.val);
            i.cnt = ((l.val<r.val)?l.cnt:r.cnt);
        }
        return i;
    }

    LazySegmentTree(int _n, int val) {
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, 0);
        build(1,1,n,val);
    }

    void build(int idx, int l, int r, int val){
        if (l==r){
            IT[idx].val = val;
            IT[idx].cnt = 0;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid,val);
        build(idx*2+1,mid+1,r,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int y, int val){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            applyAdd(idx,val);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val);
        update(idx*2+1,mid+1,r,x,y,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void updatePointNode(int idx, int l, int r, int x, Node val){
        if (x < l || r < x) return;
            // cout << idx << " " << l << " " << r << " " << x << endl;
        if (l==r){
            IT[idx] = comb(IT[idx],val);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        updatePointNode(idx*2,l,mid,x,val);
        updatePointNode(idx*2+1,mid+1,r,x,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
        // cout << idx << " " << l << " " << r << " " << IT[idx].val << " " << IT[idx].cnt << endl;
    }

    Node getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return Node();
        if (x <= l && r <= y){
            return IT[idx];
        }

        propagate(idx);

        int mid = (l+r)/2;
        return comb(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));
    }

};


int n;
vector<pii> v;
vector<int> nen;

int get_pos(int i) {
    return nen[i-1];
}

void solve(){
    cin >> n;
    
    for (int i=1; i<=n; i++){
        int l,r; cin >> r >> l;
        v.push_back({l,r});
        nen.push_back(l);
        nen.push_back(r);
    }
    sort(all(nen)); nen.resize(unique(all(nen))-nen.begin());
    nen.push_back(0);

    int mxl = 0;
    for (int i=0; i<n; i++){
        v[i].fi = lower_bound(all(nen),v[i].fi)-nen.begin()+1;
        v[i].se = lower_bound(all(nen),v[i].se)-nen.begin()+1;
        mxl = max(mxl,v[i].fi);
    }
    sort(all(v),[&](pii x, pii y){return x.se < y.se;});

    LazySegmentTree ITpos(nen.size(),LLINF), ITval(nen.size(),LLINF);
    int m = nen.size();

    int prev = 0;

    // cout << mxl << endl;

    LazySegmentTree::Node ans(LLINF,0);
    ITval.updatePointNode(1,1,m,1,LazySegmentTree::Node(0,1));
    ITpos.updatePointNode(1,1,m,1,LazySegmentTree::Node(0,1));

    for (auto [l,r]:v) {
        // cout << "l,r: " << l << " " << r << endl;
        ITval.update(1,1,m,1,m,get_pos(r)-prev);
        prev = get_pos(r);
        
        int bound = ITpos.getVal(1,1,m,1,l).val;
        // cout << bound << endl;
        bound = ((bound>0)?0:-bound);

        // cout << bound << endl;

        auto node = ITval.getVal(1,1,m,bound+1,l);
        if (node.val >= LLINF) {
            node.val = 0;
            node.cnt = 1;
        }
        else {
            node.val-=(get_pos(r)-get_pos(l));
        }

        // cout << node.val << " " << node.cnt << endl;

        if (r>mxl) {
            ans = LazySegmentTree::comb(ans,node);
        }
        
        ITpos.updatePointNode(1,1,m,r,LazySegmentTree::Node(-l,1));
        ITval.updatePointNode(1,1,m,r,node);
    }

    cout << ans.cnt << endl;
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

