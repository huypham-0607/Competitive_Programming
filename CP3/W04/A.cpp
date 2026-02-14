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

struct SegmentTree{
    struct Node{
        int val,pos;
        Node(){
            val = INF;
            pos = INF;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node l, Node r){
        Node i = Node();

        if (l.val == r.val) {
            i.val = l.val;
            if (l.pos < r.pos) i.pos = l.pos;
            else i.pos = r.pos;
        }
        else if (l.val < r.val) {
            i = l;
        }
        else {
            i = r;
        }

        return i;
    }

    SegmentTree(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val = INF;
            IT[idx].pos = l;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int val){
        if (r < x || x < l) return;
        if (l==r){
            IT[idx].val = val;
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val);
        update(idx*2+1,mid+1,r,x,val);
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
};

struct SegmentTree2{
    struct Node{
        int val,pos;
        Node(){
            val = 0;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node l, Node r){
        Node i = Node();

        i.val = l.val + r.val;

        return i;
    }

    SegmentTree2(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val = 1;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int val){
        if (r < x || x < l) return;
        if (l==r){
            IT[idx].val = val;
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val);
        update(idx*2+1,mid+1,r,x,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    int getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return 0;
        if (x <= l && r <= y){
            return IT[idx].val;
        }

        int mid = (l+r)/2;
        return getVal(idx*2,l,mid,x,y)+getVal(idx*2+1,mid+1,r,x,y);
    }
};


int n;

void solve(){
    cin >> n;

    SegmentTree IT(n);
    SegmentTree2 ITcnt(n);
    IT.build(1,1,n);
    vector<int> v;
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        IT.update(1,1,n,i,x);
        v.push_back(x);
    }

    sort(all(v));

    int ans = 0;
    int curpos = 0;
    for (int i=0; i<n; i++){
        int val = v[i];
        auto res = IT.getNode(1,1,n,curpos+1,n);
        // cout << i << " " << res.val << " " << res.pos << endl;
        if (res.val <= val) {
            ans += ITcnt.getVal(1,1,n,curpos,res.pos);
            curpos = res.pos;
            IT.update(1,1,n,res.pos,INF);
            ITcnt.update(1,1,n,res.pos,0);
        }
        else {
            ans += ITcnt.getVal(1,1,n,curpos,n);
            curpos = 0;
            res = IT.getNode(1,1,n,curpos+1,n);
            

            // cout << "extra: " << res.val << " " << res.pos << endl;
            ans += ITcnt.getVal(1,1,n,curpos,res.pos);
            curpos = res.pos;
            IT.update(1,1,n,res.pos,INF);
            ITcnt.update(1,1,n,res.pos,0);
        }
    }
    cout << ans << endl;
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

