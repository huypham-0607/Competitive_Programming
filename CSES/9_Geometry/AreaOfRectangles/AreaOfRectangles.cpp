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

int n;

/*
    | Segment Tree - Lazy Propagation |
    Desc: Range Update Range Queries in O(n*log(n)).
    Source: KawakiMeido
    State: Tested (Works with Beats)
*/

struct LazySegmentTree{
    struct Node{
        int val,cnt;
        Node(){
            val = 0;
            cnt = 0;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;

    void propagate(int idx){
        int x = lazy[idx];
        //Update idx*2
        IT[idx*2].val+=x;
        lazy[idx*2]+=x;
        //Update idx*2+1
        IT[idx*2+1].val+=x;
        lazy[idx*2+1]+=x;
        //Reset idx
        lazy[idx] = 0;
    }

    Node comb(Node l, Node r){
        Node i = Node();
        if (l.val > r.val) swap(l,r);

        i.val = l.val;
        if (l.val == r.val) i.cnt = l.cnt + r.cnt;
        else i.cnt = l.cnt;
        return i;
    }

    LazySegmentTree(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, 0);
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val = 0;
            IT[idx].cnt = 1;

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
            IT[idx].val += val;
            lazy[idx] += val;
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

};


void solve(){
    cin >> n;
    LazySegmentTree IT((int)2e6);
    vector<pair<pii,pii>> query;
    for (int i=1; i<=n; i++){
        int l,r,s,e; cin >> l >> s >> r >> e;
        l+=(int)1e6+1;
        r+=(int)1e6;
        s+=(int)1e6+1;
        e+=(int)1e6+1;
        query.push_back({{s,1},{l,r}});
        query.push_back({{e,-1},{l,r}});
    }
    sort(all(query));
    int idx = 0;

    ll ans = 0;
    for (int lvl = 1; lvl<=(int)2e6; lvl++){
        while (idx!=query.size() && query[idx].fi.fi == lvl) {
            auto in = query[idx];
            auto [l,r] = in.se;
            int val = in.fi.se;
            IT.update(1,1,(int)2e6,l,r,val);

            ++idx;
        }

        auto res = IT.getNode(1,1,(int)2e6,1,(int)2e6);
        if (res.val==0) {
            ans += (int)2e6-res.cnt;
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

