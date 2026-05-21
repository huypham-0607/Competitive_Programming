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

const int N = 3e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here
struct LazySegmentTree{
    int n;
    vector<int> IT;
    vector<int> lazy;

    void apply(int idx, int val) {
        IT[idx] += val;
        lazy[idx] += val;
    }

    void propagate(int idx){
        int val = lazy[idx];
        //Update idx*2
        apply(idx*2,val);
        
        //Update idx*2+1
        apply(idx*2+1,val);

        //Reset idx
        lazy[idx] = 0;
    }

    void comb(int& i, int& l, int& r){
        i = max(l,r);
    }

    void init (int _n) {
        n = _n;
        IT.resize(n*4+10, 0);
        lazy.resize(n*4+10, 0);
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx] = 0;
            lazy[idx] = 0;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int y, int val){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            apply(idx,val);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val);
        update(idx*2+1,mid+1,r,x,y,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    int walk(int idx, int l, int r) {
        // cout << idx << " " << l << " " << r << " " << IT[idx] << endl;
        if (l == r) {
            if (IT[idx] > 0) return l;
            else return -1;
        }

        propagate(idx);

        int mid = (l+r)/2;
        // cout << IT[idx*2] << " " << IT[idx*2+1] << endl;
        int res;
        if (IT[idx*2+1] > 0) {
            res = walk(idx*2+1,mid+1,r);
        }
        else {
            res = walk(idx*2,l,mid);
        }
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
        return res;
    }

    int getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return 0;
        if (x <= l && r <= y){
            return IT[idx];
        }

        propagate(idx);

        int mid = (l+r)/2;
        return max(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));
    }

} IT;

int n,m,q;
int a[N],b[N];

void solve(){
    cin >> n >> m;
    int len = (int)1e6;
    IT.init(len);


    for (int i=1; i<=n; i++){
        int x; cin >> x;
        a[i] = x;
        IT.update(1,1,len,1,x,1);
    }

    for (int i=1; i<=m; i++){
        int x; cin >> x;
        b[i] = x;
        IT.update(1,1,len,1,x,-1);
    }

    cin >> q;
    for (int i=1; i<=q; i++){
        int id, pos, val;
        cin >> id >> pos >> val;
        if (id == 1) {
            IT.update(1,1,len,1,a[pos],-1);
            a[pos] = val;
            IT.update(1,1,len,1,a[pos],1);
        }
        else {
            IT.update(1,1,len,1,b[pos],1);
            b[pos] = val;
            IT.update(1,1,len,1,b[pos],-1);
        }

        int ans = IT.walk(1,1,len);
        cout << ans << endl;
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

