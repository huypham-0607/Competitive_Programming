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

int n,m;

struct LazySegmentTree{
    struct Node{
        int val;
        Node(){
            val = 0;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> cnt;
    vector<int> lazy;

    void applyAdd(int idx, int val) {
        IT[idx].val += val*cnt[idx];
        lazy[idx] += val;
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

    void comb(Node& i, Node& l, Node& r){
        i.val = l.val + r.val;
    }

    LazySegmentTree(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        cnt.resize(n*4+10, 0);
        lazy.resize(n*4+10, 0);
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val = 0;
            lazy[idx] = 0;
            cnt[idx] = 1;

            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
        cnt[idx] = cnt[idx*2] + cnt[idx*2+1];
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
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    int getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return 0;
        if (x <= l && r <= y){
            return IT[idx].val;
        }

        propagate(idx);

        int mid = (l+r)/2;
        return getVal(idx*2,l,mid,x,y)+getVal(idx*2+1,mid+1,r,x,y);

    }

};


void solve(){
    cin >> m >> n;

    LazySegmentTree IT(n);

    deque<pii> dq;
    vector<int> v;

    for (int i=1; i<=m; i++){
        // cout << "level: " << i << endl;
        v.clear();
        int l; cin >> l;
        int delta = (n - l);
        v.push_back(0);
        
        for (int idx=1; idx<=l; idx++) {
            int x; cin >> x;
            v.push_back(x);
        }

        dq.clear();
        for (int idx=1; idx<=l; idx++) {
            if (!dq.empty() && dq.front().se < idx-delta) {
                dq.pop_front();
            }

            while (!dq.empty() && dq.back().fi < v[idx]) dq.pop_back();
            dq.push_back({v[idx],idx});

            int lmeo = dq.front().fi;
            if (idx-delta <= 0) lmeo = max(lmeo,0LL);

            // cout << idx << " " << lmeo << endl;
            IT.update(1,1,n,idx,idx,lmeo);
        }

        dq.clear();
        for (int idx=l; idx>0; idx--){
            int pos = n-(l-idx);
            if (pos == l) break;
            if (!dq.empty() && dq.front().se > idx+delta) {
                dq.pop_front();
            }

            while (!dq.empty() && dq.back().fi < v[idx]) dq.pop_back();
            dq.push_back({v[idx],idx});

            int lmeo = dq.front().fi;
            if (idx+delta > l) lmeo = max(lmeo,0LL);

            // cout << pos << " " << lmeo << endl;
            IT.update(1,1,n,pos,pos,lmeo);
        }

        int mx = 0;
        for (int i=1; i<=l; i++){
            mx = max(mx,v[i]);
        }

        if (l+1 <= n-l) {
            IT.update(1,1,n,l+1,n-l,mx);
        }
    }
    for (int i=1; i<=n; i++){
        int res = IT.getVal(1,1,n,i,i);
        cout << res << endl;
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

