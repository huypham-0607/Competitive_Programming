/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "855F"

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

vector<int> query;

struct LazySegmentTree{
    struct Node{
        int mx1,mx2,cnt,sum,flag;
        Node(){
            mx1 = INF;
            mx2 = 0;
            flag = 0;
            cnt = 0;
            sum = 0;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;
    vector<int> lazyFlag;

    void applyMin(int idx, int val) {
        if (val < IT[idx].mx1) {
            IT[idx].sum -= (IT[idx].mx1-val)*IT[idx].cnt;
            IT[idx].mx1 = val;
            lazy[idx] = val;
        }
    }

    void applyFlag(int idx, int val) {
        IT[idx].flag = val;
        lazyFlag[idx] = val;
    }

    void propagate(int idx){
        if (lazy[idx]!=-1) {
            int val = lazy[idx];
            //Update idx*2
            applyMin(idx*2,val);
            //Update idx*2+1
            applyMin(idx*2+1,val);
        }

        if (lazyFlag[idx]!=-1) {
            int val = lazyFlag[idx];
            applyFlag(idx<<1,val);
            applyFlag(idx<<1|1,val);
        }
        
        //Reset idx
        lazy[idx] = -1;
        lazyFlag[idx] = -1;
    }

    void comb(Node& i, Node l, Node r){
        if (l.mx1 < r.mx1) swap(l,r);

        i.mx1 = l.mx1;
        if (i.mx1 == r.mx1) {
            i.cnt = l.cnt + r.cnt;
            i.mx2 = max(l.mx2,r.mx2);
        }
        else {
            i.cnt = l.cnt;
            i.mx2 = max(l.mx2,r.mx1);
        }
        i.flag = min(l.flag,r.flag);

        i.sum = l.sum + r.sum;
    }

    LazySegmentTree(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, -1);
        lazyFlag.resize(n*4+10,-1);
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].mx1 = INF;
            IT[idx].mx2 = 0;
            IT[idx].flag = 0;
            IT[idx].cnt = 0;
            IT[idx].sum = 0;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int y, int val){
        if (y < l || r < x || IT[idx].mx1 <= val) return;
        if (x <= l && r <= y && IT[idx].mx2 < val){
            applyMin(idx,val);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val);
        update(idx*2+1,mid+1,r,x,y,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void updateFlag(int idx, int l, int r, int x, int y) {
        if (y < l || r < x || IT[idx].flag == 1) return;
        // cout << l << " " << r << endl;
        if (x <= l && r <= y && IT[idx].mx2 == 0) {
            applyFlag(idx,1);
            // cout << "Flag applied" << endl;
            for (int i=l; i<=r; i++){
                query.push_back(i);
            }
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        updateFlag(idx<<1,l,mid,x,y);
        updateFlag(idx<<1|1,mid+1,r,x,y);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void updateCnt(int idx, int l, int r, int x) {
        if (x < l || r < x) return;
        if (l==r) {
            IT[idx].cnt = 1;
            IT[idx].sum += IT[idx].mx1;
            return;
        }

        propagate(idx);

        int mid = (l+r)>>1;
        updateCnt(idx<<1,l,mid,x);
        updateCnt(idx<<1|1,mid+1,r,x);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    int getFlag(int idx, int l, int r, int x) {
        if (x < l || r < x) return 1;
        if (l == r) return IT[idx].flag;

        propagate(idx);

        int mid = (l+r)>>1;
        return min(getFlag(idx<<1,l,mid,x),getFlag(idx<<1|1,mid+1,r,x)); 
    }

    int getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return 0;
        if (x <= l && r <= y){
            return IT[idx].sum;
        }

        propagate(idx);

        int mid = (l+r)/2;
        return getVal(idx*2,l,mid,x,y) + getVal(idx*2+1,mid+1,r,x,y);
    }
};

int n,q;

void solve(){
    n = 1e5;
    LazySegmentTree pos(n),neg(n);
    cin >> q;
    while (q--) {
        int id,l,r,k;
        cin >> id >> l >> r;
        --r;
        if (id == 1) {
            cin >> k;
            if (k > 0) {
                pos.updateFlag(1,1,n,l,r);
                pos.update(1,1,n,l,r,abs(k));
            }
            else {
                neg.updateFlag(1,1,n,l,r);
                neg.update(1,1,n,l,r,abs(k));
            }
            while (query.size()) {
                int x = query.back();
                // cout << x << endl;
                query.pop_back();
                int pf = pos.getFlag(1,1,n,x);
                int nf = neg.getFlag(1,1,n,x);
                // cout << pf << " " << nf << endl;
                if (pf && nf) {
                    pos.updateCnt(1,1,n,x);
                    neg.updateCnt(1,1,n,x);
                }
            }
        }
        else {
            // cout << pos.IT[1].cnt << " " << neg.IT[1].cnt << endl;
            int psum = pos.getVal(1,1,n,l,r);
            int nsum = neg.getVal(1,1,n,l,r);
            cout << psum + nsum << endl;
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

