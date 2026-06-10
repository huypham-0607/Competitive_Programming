/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
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
const long long LLINF = 1e14+3;

//Starts here

struct SegmentTree{
    struct Node{
        pii val;
        Node(){
            val = {0,0};
        }
    };

    int n;
    vector<Node> IT;

    void comb(Node& i, Node& l, Node& r){
        i.val = max(l.val,r.val);
    }

    void init(int _n) {
        n = _n;
        IT.clear();
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val = {0,l};
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int val){
        if (r < x || x < l) return;
        if (l==r){
            IT[idx].val.fi = val;
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val);
        update(idx*2+1,mid+1,r,x,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    pii getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return {0,0};
        if (x <= l && r <= y){
            return IT[idx].val;
        }

        int mid = (l+r)/2;
        return max(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));

    }
} IT;

struct SegmentTree2{
    struct Node{
        int val,cnt;
        Node(){
            val = 0;
            cnt = 0;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node l, Node r){
        Node i;
        if (l.val == r.val) {
            i.val = l.val;
            i.cnt = l.cnt + r.cnt;
        }
        else {
            i.val = max(l.val,r.val);
            i.cnt = ((l.val > r.val)?l.cnt:r.cnt);
        }
        return i;
    }

    void init(int _n) {
        n = _n;
        IT.clear();
        IT.resize(n*4+10, Node());
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

    Node getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return Node();
        if (x <= l && r <= y){
            return IT[idx];
        }

        int mid = (l+r)/2;
        return comb(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));

    }
} IT2;

namespace Comb {
    using ll = long long;

    const int MD = 1e9+7;
    const int N = 5e5+10;
    const int LG = 30;

    int invFac[N+1];
    int fac[N+1];

    int binPow(int a, int b){
        ll res = 1;
        for (int lg = LG-1; lg>=0; lg--){
            res = res*res%MD;
            if ((1LL<<lg)&b) res = res*a%MD;
        }
        return res;
    }

    int invMod(int x, int MD){
        return binPow(x,MD-2);
    }

    int nCk(int n, int k){
        return 1LL*fac[n]*invFac[k]%MD*invFac[n-k]%MD;
    }

    struct Init {
        Init() {
            fac[0] = 1;
            invFac[0] = 1;
            for (int i = 1; i <= N; i++){
                fac[i] = (1LL*fac[i-1]*i%MD);
                invFac[i] = invMod(fac[i],MD);
            }
        }
    } _init;
}


int n;
int a[N];

int miku(int l,int r) {
    if (l>r) return 1;
    int res = 1;
    int pos=0,val;
    // cout << "l,r: " << l << " " << r << endl;
    for (int i=0; i<=(r-l)/2; i++){
        // cout << i << " ";
        pos = l+i; val = a[pos];
        if ((pos-l+1) * (r-pos+1) == val) break;
        pos = r-i; val = a[pos];
        if ((pos-l+1) * (r-pos+1) == val) break;
    }
    // cout << endl;
    if ((pos-l+1) * (r-pos+1) != val) return 0;
    res = (res*Comb::nCk(r-l,pos-l))%MD;
    res = (res*miku(l,pos-1))%MD;
    res = (res*miku(pos+1,r))%MD;
    return res;
}

void solve(){
    cin >> n;
    IT.init(n);
    IT2.init(n);
    for (int i=1; i<=n; i++){
        cin >> a[i];
        IT.update(1,1,n,i,a[i]);
        IT2.update(1,1,n,i,a[i]);
    }

    int ans = miku(1,n);
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

