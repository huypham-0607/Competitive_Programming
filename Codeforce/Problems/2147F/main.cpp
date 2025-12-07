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
int n,q;

//Segment Tree Lazy
struct SegmentTree{
    struct Node{
        int val, sum, last, first, lb, rb;
        Node(){
            val = INF;
            sum = lb = rb = first = last = 0;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;

    void add(int idx, int x){
        IT[idx].val += x;
        lazy[idx] += x;
    }

    void propagate(int idx){
        add(idx*2,lazy[idx]);
        add(idx*2+1,lazy[idx]);
        lazy[idx] = 0;
    }

    Node comb(Node l, Node r){
        if (l.val == INF) return r;
        if (r.val == INF) return l;

        Node i;

        i.val = min(l.val,r.val);
        i.sum = 0;
        if (l.val != i.val){
            l.first = r.first;
            l.last = l.lb-1;
            l.sum = (l.rb-(l.lb-1))*(l.rb-(l.lb-1));
        }
        if (r.val != i.val){
            r.first = r.rb;
            r.last = l.last;
            r.sum = (r.rb-(r.lb-1))*(r.rb-(r.lb-1));
        }
        i.lb = l.lb;
        i.rb = r.rb;
        i.first = l.first;
        i.last = r.last;
        i.sum = l.sum + r.sum + (l.rb - l.last)*(r.first - (r.lb-1)) + (r.rb - (r.lb-1))*(l.rb - (l.lb-1));

        return i;
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].lb = l;
            IT[idx].rb = l;
            IT[idx].first = l;
            IT[idx].last = l;
            IT[idx].val = 0;
            IT[idx].sum = 1;
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
            add(idx,val);
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

    int get(){
        return IT[1].sum;
    }

    void init(int _n){
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, 0);
        build(1,1,n);
    }

    void printdb(Node res, int x, int y){
        cout << "Node " << x << "," << y << ":" << endl;
        cout << res.sum << " " << res.val << " " << res.first << " " << res.last << endl;
    }

    void db(int x, int y){
        Node res = getNode(1,1,n,x,y);
        printdb(res,x,y);
    }

    void dbdfs(int idx, int l, int r){
        if (l==r){
            printdb(IT[idx],l,r);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        dbdfs(idx*2,l,mid);
        dbdfs(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
        printdb(IT[idx],l,r);
    }
};

/*Solution*/
void solve(){
    cin >> n >> q;
    vector<int> a(n+10,0), b(n+10,0);
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }

    SegmentTree IT;
    IT.init(n);

//    IT.db(1,n);
    for (int i=1; i<=n; i++){
        int l = min(a[i],b[i]);
        int r = max(a[i],b[i])-1;
        IT.update(1,1,n,l,r,1);
    }
//    IT.db(1,n);

    while (q--){
        int id,x,y; cin >> id >> x >> y;
        int l,r;
        l = min(a[x],b[x]); r = max(a[x],b[x])-1;
        IT.update(1,1,n,l,r,-1);
        l = min(a[y],b[y]); r = max(a[y],b[y])-1;
        IT.update(1,1,n,l,r,-1);
        if (id == 1) swap(a[x],a[y]);
        if (id == 2) swap(b[x],b[y]);
        l = min(a[x],b[x]); r = max(a[x],b[x])-1;
        IT.update(1,1,n,l,r,1);
        l = min(a[y],b[y]); r = max(a[y],b[y])-1;
        IT.update(1,1,n,l,r,1);
        cout << IT.get() << endl;
    }

}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
        freopen("main.out","w",stdout);
    }

    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
