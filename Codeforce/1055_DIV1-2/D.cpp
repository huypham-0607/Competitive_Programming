/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
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
int n,q;

struct Node{
    int val, du;
    Node(){
        val = INF;
        du = INF;
    }

    friend Node comb(Node l, Node r){
        if (l.val == INF) return r;
        if (r.val == INF) return l;

        Node i;
        i.val = l.val + r.val;
        i.du = l.du + r.du;

        return i;
    }
};

//Segment Tree
struct SegmentTree{
    int n;
    vector<Node> IT;

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val = 0;
            IT[idx].du = 0;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int val, int du){
        if (r < x || x < l) return;
        if (l==r){
            IT[idx].val = val;
            IT[idx].du = du;
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val,du);
        update(idx*2+1,mid+1,r,x,val,du);
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

    void init(int _n){
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }
};



/*Solution*/
void solve(){
    cin >> n >> q;
    SegmentTree IT;
    IT.init(n);
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        int du = 0;
        int val = 0;
        int lg = 31-__builtin_clz(x);
        val = lg;
        if (x != (1<<lg)) ++ val;
        if (x == (1<<lg)+1) ++ du;
        IT.update(1,1,n,i,val,du);
    }
    while (q--){
        int l,r; cin >> l >> r;
        Node res = IT.getNode(1,1,n,l,r);
        if (res.du == 0){
            cout << res.val << endl;
        }
        else{
            cout << res.val - (res.du+1)/2 << endl;
        }
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
