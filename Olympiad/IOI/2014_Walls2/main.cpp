/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>
#include "wall.h"

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

const int N = 2e6+10;
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
        int ub,lb;
        Node(){
            ub = LLINF;
            lb = 0;
        }
    };

    int n;
    vector<Node> IT;

    void add(int idx, Node x){
        if (IT[idx].ub > x.ub) IT[idx].ub = x.ub;
        if (IT[idx].lb > x.ub) IT[idx].lb = x.ub;
        if (IT[idx].ub < x.lb) IT[idx].ub = x.lb;
        if (IT[idx].lb < x.lb) IT[idx].lb = x.lb;
    }

    void propagate(int idx){
        add(idx*2,IT[idx]);
        add(idx*2+1,IT[idx]);
        IT[idx] = Node();
    }

    Node comb(Node l, Node r){
        if (l.ub == LLINF) return r;
        if (r.ub == LLINF) return l;

        Node i = Node();

        return i;
    }

    void build(int idx, int l, int r){
        if (l==r){

            IT[idx].ub = 0;
            IT[idx].lb = 0;

            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
    }

    void update(int idx, int l, int r, int x, int y, int val, int op){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            Node tmp = Node();
            if (op) tmp.ub = val;
            else tmp.lb = val;
            add(idx,tmp);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val,op);
        update(idx*2+1,mid+1,r,x,y,val,op);
    }

    Node getNode(int idx, int l, int r, int x){
        if (x < l || r < x) return Node();
        if (l == r){
            return IT[idx];
        }

        propagate(idx);

        int mid = (l+r)/2;
        return comb(getNode(idx*2,l,mid,x),getNode(idx*2+1,mid+1,r,x));

    }

    void init(int _n){
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }
} IT;

int n,k;

void buildWall(signed _n, signed _k, signed op[], signed left[], signed right[], signed height[], signed finalHeight[]) {
    n = _n;
    k = _k;
    IT.init(n);
    for (int i=0; i<k; i++) {
        int l = left[i] +1;
        int r = right[i]+1;
        IT.update(1,1,n,l,r,height[i],op[i]-1);
//        for (int idx=1; idx<=n; idx++) {
//            LazySegmentTree::Node res = IT.getNode(1,1,n,idx);
//            cout << res.lb << " " << res.ub << endl;
//        }
//        cout << endl;
    }

    for (int i=1; i<=n; i++) {
        LazySegmentTree::Node res = IT.getNode(1,1,n,i);
//        cout << res.lb << " " << res.ub << endl;
        finalHeight[i-1] = res.lb;
    }

}

//signed _n,_k;
//signed op[N],l[N],r[N],height[N],finalHeight[N];
//
//void solve(){
//
//    cin >> _n >> _k;
//    for (int i=0; i<_k; i++){
//        cin >> op[i] >> l[i] >> r[i] >> height[i];
//    }
//
//    buildWall(_n, _k, op,l,r,height,finalHeight);
//
//    for (int i=0; i<n; i++){
//        cout << finalHeight[i] << " ";
//    }
//    cout << endl;
//}
//
///*Driver Code*/
//signed main(){
//    cin.tie(0) -> sync_with_stdio(0);
//    if (fopen(TEXT".inp","r")){
//        freopen(TEXT".inp","r",stdin);
//        freopen(TEXT".out","w",stdout);
//    }
//
//    int testCount = 1;
////    cin >> testCount;
//    while (testCount--){
//        solve();
//    }
//
//    return 0;
//}
