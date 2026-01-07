/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "1572F"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
// #define int long long

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

namespace IT{
    int n;
    ll sum[4*N];
    int cnt[4*N];
    int lazy[4*N];

    void applyAdd(int idx, int val) {
        sum[idx] += (ll)val*cnt[idx];
        lazy[idx] += val;
    }

    void propagate(int idx){
        if (lazy[idx]!=0) {
            int val = lazy[idx];
            applyAdd(idx<<1,val);
            applyAdd(idx<<1|1,val);
        }

        lazy[idx] = 0;
    }

    void comb(int i, int l, int r){
        sum[i] = sum[l] + sum[r];
    }

    void build(int idx, int l, int r){
        cnt[idx] = (r-l+1);
        if (l==r){
            sum[idx] = 1;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        comb(idx,idx*2,idx*2+1);
    }

    void init(int _n) {
        n = _n;
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        memset(lazy,0,sizeof(lazy));
        build(1,1,n);
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
        comb(idx,idx*2,idx*2+1);
    }

    ll getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return 0;
        if (x <= l && r <= y){
            return sum[idx];
        }

        propagate(idx);

        int mid = (l+r)/2;
        return getVal(idx*2,l,mid,x,y) + getVal(idx*2+1,mid+1,r,x,y);
    }

};

namespace ITq{
    int n;
    int val1[4*N],val2[4*N],cnt[4*N];
    int lazy[4*N];

    void applyMin(int idx, int val) {
        if (val < val1[idx]) {
            val1[idx] = val;
            lazy[idx] = val;
        }
    }

    void propagate(int idx){
        if (lazy[idx]!=0) {
            int val = lazy[idx];
            applyMin(idx<<1,val);
            applyMin(idx<<1|1,val);
        }

        //Reset idx
        lazy[idx] = 0;
    }

    void comb(int i, int l, int r){
        if (val1[l] < val1[r]) swap(l,r);

        val1[i] = val1[l];
        if (val1[l] == val1[r]) {
            cnt[i] = cnt[l] + cnt[r];
            val2[i] = max(val2[l],val2[r]);
        }
        else {
            cnt[i] = cnt[l];
            val2[i] = max(val2[l],val1[r]);
        }
    }


    void build(int idx, int l, int r){
        if (l==r){
            val1[idx] = l;
            val2[idx] = 0;
            cnt[idx] = 1;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        comb(idx,idx*2,idx*2+1);
    }

    void init(int _n) {
        n = _n;
        memset(val1,0,sizeof(val1));
        memset(val2,0,sizeof(val2));
        memset(cnt,0,sizeof(cnt));
        memset(lazy,0,sizeof(lazy));
        build(1,1,n);
    }

    void updateMin(int idx, int l, int r, int x, int y, int val){
        if (y < l || r < x || val1[idx] <= val) return;
        if (x <= l && r <= y && val2[idx] < val){
            IT::update(1,1,n,val+1,val1[idx],-cnt[idx]);
            applyMin(idx,val);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        updateMin(idx*2,l,mid,x,y,val);
        updateMin(idx*2+1,mid+1,r,x,y,val);
        comb(idx,idx*2,idx*2+1);
    }

    void updateSet(int idx, int l, int r, int x, int val) {
        if (x < l || r < x) return;
        if (l==r) {
            IT::update(1,1,n,l,val1[idx],-1);
            IT::update(1,1,n,l,val,1);
            val1[idx] = val;
            return;
        }

        propagate(idx);

        int mid = (l+r)>>1;
        updateSet(idx<<1,l,mid,x,val);
        updateSet(idx<<1|1,mid+1,r,x,val);
        comb(idx,idx<<1,idx<<1|1);
    }
}

int n,q;

void solve(){
    cin >> n >> q;
    ITq::init(n);
    IT::init(n);
    while (q--){
        int id,x,y; cin >> id >> x >> y;
        // cerr << "Query: " << id << " " << x << " " << y << endl;
        if (id == 1) {
            ITq::updateMin(1,1,n,1,x-1,x-1);
            ITq::updateSet(1,1,n,x,y);
        }
        else {
            ll ans = IT::getVal(1,1,n,x,y);
            cout << ans << endl;
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

