/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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

//Segment Tree Lazy
//Lmao

//Segment Tree
//Lmao

struct SegmentTree{
    struct Node{
        int val;
        Node(){
            val = -INF;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node l, Node r){
        if (l.val == -INF) return r;
        if (r.val == -INF) return l;

        Node i;
        i.val = max(l.val,r.val);

        return i;
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val = -INF;
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
            IT[idx].val = max(IT[idx].val,val);
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val);
        update(idx*2+1,mid+1,r,x,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    int getNode(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return 0;
        if (x <= l && r <= y){
            return IT[idx].val;
        }

        int mid = (l+r)/2;
        return max(getNode(idx*2,l,mid,x,y),getNode(idx*2+1,mid+1,r,x,y));

    }

    void init(int _n){
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }
};



int n;

void solve(){
    cin >> n;

    vector<pii> v;
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        v.push_back({x,i});
    }

    sort(all(v),[&](pii x, pii y){
         return (x.fi < y.fi) || (x.fi == y.fi && x.se > y.se);});

    SegmentTree IT;
    IT.init(n+10);
    IT.update(1,1,n,n,0);

    queue<pair<int,int>> q;

    int ans = 0;

    for (auto [val,pos]:v) {
        while (!q.empty() &&
            q.front().fi < val-1){
            IT.update(1,1,n,n,q.front().se);
            q.pop();
        }
//        cerr << val << " " << pos << endl;
        int cnt = IT.getNode(1,1,n,pos,n)+1;
        ans = max(ans,cnt);
        q.push({val,cnt});
        IT.update(1,1,n,pos,cnt);
    }

//    cout << ans << " " << n-ans << endl;
    cout << n-ans << endl;
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
