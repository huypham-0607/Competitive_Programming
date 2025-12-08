/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "bubblesort2"

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

const int N = 5e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

struct LazySegmentTree{
    struct Node{
        int val;
        Node(){
            val = -INF;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;

    void propagate(int idx){
        //Update idx*2
        IT[idx*2].val += lazy[idx];
        lazy[idx*2] += lazy[idx];

        //Update idx*2+1
        IT[idx*2+1].val += lazy[idx];
        lazy[idx*2+1] += lazy[idx];

        //Reset idx
        lazy[idx] = 0;
    }

    Node comb(Node l, Node r){
        if (l.val == -INF) return r;
        if (r.val == -INF) return l;

        Node i;

        i.val = max(l.val,r.val);

        return i;
    }

    void build(int idx, int l, int r){
        lazy[idx] = 0;
        if (l==r){
            IT[idx].val = 0;
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

    void init(int _n){
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, 0);
        build(1,1,n);
    }
} IT;


int n,q,m;
int a[N], pos[N], val[N];
vector<set<int>> track;

void add(int val, int pos) {
    int premx;
    if (track[val].size() == 0) premx = 0;
    else premx = *(track[val].rbegin());

    track[val].insert(pos);

    int mx;
    if (track[val].size() == 0) mx = 0;
    else mx = *(track[val].rbegin());

    IT.update(1,1,m,val,m,-1);

    IT.update(1,1,m,val,val,mx-premx);    
}

void del(int val, int pos) {
    int premx;
    if (track[val].size() == 0) premx = 0;
    else premx = *(track[val].rbegin());
    track[val].erase(pos);
    int mx;
    if (track[val].size() == 0) mx = 0;
    else mx = *(track[val].rbegin()); 

    IT.update(1,1,m,val,m,1);

    IT.update(1,1,m,val,val,mx-premx);
}

vector<int2> countScans(vector<int2> _a, vector<int2> _pos, vector<int2> _val) {
    vector<int> nen;
    n = _a.size();
    q = _pos.size();
    // cerr << n << " " << q << endl;

    for (int i=1; i<=n; i++){
        a[i] = _a[i-1];
    }

    for (int i=1; i<=q; i++){
        pos[i] = _pos[i-1];
        pos[i]++;
        val[i] = _val[i-1];
    }

    // cerr << "Good" << endl;

    for (int i=1; i<=n; i++){
        nen.push_back(a[i]);
    }

    for (int i=1; i<=q; i++){
        nen.push_back(val[i]);
    }

    sort(all(nen));
    nen.resize(unique(all(nen)) - nen.begin());
    m = nen.size();
    IT.init(m);

    // cerr << m << endl;

    for (int i=1; i<=n; i++){
        a[i] = lower_bound(all(nen),a[i]) - nen.begin() + 1;
    }
    for (int i=1; i<=q; i++){
        val[i] = lower_bound(all(nen),val[i]) - nen.begin() +1;
    }

    track.resize(m+1);
    vector<int2> ans(q);
    
    for (int i=1; i<=n; i++){
        // cerr << a[i] << endl;
        add(a[i],i);    
    }
    for (int i=1; i<=q; i++) {
        int ps = pos[i];
        int vl = val[i];
        // cerr << ps << " " << vl << endl;
        del(a[ps],ps);
        a[ps] = vl;
        // cerr << ps << " " << a[ps] << endl;
        add(a[ps],ps);
        auto res = IT.getNode(1,1,m,1,m);
        ans[i-1] = res.val;
        // for (int x=1; x<=m; x++){
        //     cout << IT.getNode(1,1,m,x,x).val << " ";
        // }
        // cout << endl;
    }
    return ans;
}

// int2 _n, _q;

// void solve(){
//     cin >> _n >> _q;
//     vector<int2> _a(_n), _pos(_q), _val(_q);

//     for (int i=0; i<_n; i++) {
//         cin >> _a[i];
//     }

//     for (int i=0; i<_q; i++) {
//         cin >> _pos[i] >> _val[i];
//     }

//     vector<int2> ans = countScans(_a, _pos, _val);
//     for (int i = 0; i < _q; i++){
//         cout << ans[i] << endl;
//     }
// }

// /*Driver Code*/
// signed main(){
//     // cin.tie(0) -> sync_with_stdio(0);
//     if (fopen(TEXT".inp","r")){
//         freopen(TEXT".inp","r",stdin);
//         freopen(TEXT".out","w",stdout);
//     }

//     int testCount = 1;
// //    cin >> testCount;
//     while (testCount--){
//         solve();
//     }

//     return 0;
// }
