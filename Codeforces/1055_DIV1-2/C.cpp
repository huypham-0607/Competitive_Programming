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
    int val0,val1,lb,rb;
    bool sus;
    Node(){
        val0 = INF;
        val1 = INF;
        lb = INF;
        rb = INF;
        sus = false;
    }

    friend Node comb(Node l, Node r){
        if (l.val0 == INF) return r;
        if (r.val0 == INF) return l;

        Node i;
        i.val0 = l.val0 + r.val0;
        i.val1 = l.val1 + r.val1;
        i.lb = l.lb;
        i.rb = r.rb;
        i.sus = (l.sus || r.sus);
        if (l.rb==r.lb) i.sus = true;

        return i;
    }
};

//Segment Tree
struct SegmentTree{

    int n;
    vector<Node> IT;

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val0 = 0;
            IT[idx].val1 = 0;
            IT[idx].lb = INF;
            IT[idx].rb = INF-1;
            IT[idx].sus = false;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int par, int val){
        if (r < x || x < l) return;
        if (l==r){
            if (par) IT[idx].val1 += val;
            else IT[idx].val0 += val;
            IT[idx].lb = IT[idx].rb = par;
            IT[idx].sus = false;
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,par,val);
        update(idx*2+1,mid+1,r,x,par,val);
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
        IT.update(1,1,n,i,x,1);
    }

    while (q--){
        int l,r; cin >> l >> r;
        Node res = IT.getNode(1,1,n,l,r);
        if (res.val0%3 || res.val1%3){
            cout << -1 << endl;
        }
        else{
            int val = res.val0/3 + res.val1/3;
            if (!res.sus) val++;
            cout << val << endl;
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
