/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "mou"

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
struct LazySegmentTree{
    struct Node{
        int cnt,sum,val,mx;
        Node(){
            cnt = INF;
            val = INF;
            sum = 0;
            mx = 0;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;

    void add(int idx, int x){
        IT[idx].val = x;
        IT[idx].sum = x*(IT[idx].cnt);
        IT[idx].mx = IT[idx].sum;
        lazy[idx] = x;
    }

    void propagate(int idx){
        if (lazy[idx] == INF) return;
        add(idx*2,lazy[idx]);
        add(idx*2+1,lazy[idx]);
        lazy[idx] = INF;
    }

    Node comb(Node l, Node r){
        if (l.cnt == INF) return r;
        if (r.cnt == INF) return l;

        Node i;

        i.cnt = l.cnt + r.cnt;
        i.val = max(l.val,r.val);
        i.sum = l.sum + r.sum;
        i.mx = max(l.mx,l.sum+r.mx);

        return i;
    }

    void build(int idx, int l, int r){
        lazy[idx] = INF;
        if (l==r){
            IT[idx].val = 0;
            IT[idx].cnt = 0;
            IT[idx].sum = 0;
            IT[idx].mx = 0;

            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void updateCnt(int idx, int l, int r, int x, int val) {
        if (x < l || r < x) return;
        if (l == r){
            IT[idx].cnt = val;
            return;
        }
        int mid = (l+r)/2;
        updateCnt(idx*2,l,mid,x,val);
        updateCnt(idx*2+1,mid+1,r,x,val);
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

    pair<int,pii> walk(int idx, int l, int r, int h, int prefh, int pref){
//        cout << idx << " " << l << " " << r << " " << h << " " << prefh << " " << pref << endl;
//        cout << IT[idx].sum << " " << IT[idx].mx << " " << IT[idx].cnt << endl;
        if (l==r){
//            if (prefh+IT[idx].mx > h) return make_pair(pref,make_pair(l-1,prefh));
//            else return make_pair(pref+IT[idx].cnt,make_pair(l,prefh+IT[idx].sum));
            return make_pair(pref,make_pair(l,prefh));
        }

        propagate(idx);

        int mid = (l+r)/2;
        if (prefh + IT[idx*2].mx <= h) {
            return walk(idx*2+1,mid+1,r,h,prefh + IT[idx*2].sum,pref+IT[idx*2].cnt);
        }
        else return walk(idx*2,l,mid,h,prefh,pref);

    }

    pair<int,int> get(int idx, int l, int r, int x) {
        if (x < l || r < x) return make_pair(-1,-1);
        if (l==r) {
            return make_pair(IT[idx].val,IT[idx].cnt);
        }

        propagate(idx);

        int mid = (l+r)/2;
        pii res1 = get(idx*2,l,mid,x);
        pii res2 = get(idx*2+1,mid+1,r,x);
//        cout << "idx: " << idx << endl;
//        cout << res1.fi << " " << res1.se << " " << res2.fi << " " << res2.se << endl;
        if (res1.fi == -1) return res2;
        else return res1;
    }

    void init(int _n){
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, 0);
        build(1,1,n);
    }
}IT;

int n;
vector<int> nen;
vector<pii> update;
vector<pair<pii,pii>> query;

void solve(){
    cin >> n;
    nen.push_back(n);
    char c; cin >> c;
    while (c!='E') {
        if (c == 'I') {
            int l,r,w; cin >> l >> r >> w;
            query.push_back({{1,w},{l-1,r}});
            if (l-1!=0) nen.push_back(l-1);
            nen.push_back(r);
        }
        else {
            int w; cin >> w;
            query.push_back({{0,w},{0,0}});
        }
        cin >> c;
    }

    sort(all(nen));
    nen.resize(unique(all(nen)) - nen.begin());
    for (int i=0; i<(int)query.size(); i++){
        auto &in = query[i];
        if (in.fi.fi == 1){
            if (in.se.fi == 0) in.se.fi = 1;
            else in.se.fi = lower_bound(all(nen),in.se.fi)-nen.begin()+2;
            if (in.se.se == 0) in.se.se = 1;
            else in.se.se = lower_bound(all(nen),in.se.se)-nen.begin()+1;
        }
    }

    int m = nen.size();
    IT.init(m);
    int prev = 0;
    for (int i = 0; i < (int)nen.size(); i++){
//        cout << nen[i] << " ";
        IT.updateCnt(1,1,m,i+1,nen[i]-prev);
        prev = nen[i];
    }
//    cout << endl;

    for (auto in:query) {
//        cout << in.fi.fi << " " << in.fi.se << " " << in.se.fi << " " << in.se.se << endl;
        if (in.fi.fi == 1) {
            int w = in.fi.se;
            auto [l,r] = in.se;
            IT.update(1,1,m,l,r,w);
        }
        else {
//            cout << "Walk: " << endl;
            int h = in.fi.se;
            auto in = IT.walk(1,1,m,h,0,0);
            int prefcnt = in.fi;
            int pos = in.se.fi;
            int curh = in.se.se;
            int val = 0;
            int cnt = 0;
            int delta = h-curh;
            auto res = IT.get(1,1,m,pos);
            val = res.fi;
            cnt = res.se;
//            cout << prefcnt << " " << pos << " " << curh << " " << val << " " << cnt << endl;
            if (val>0) prefcnt += min(delta/val,cnt);
            else prefcnt += cnt;
            cout << prefcnt << endl;
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
