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

struct LazySegmentTree{
    struct Node{
        int val;
        Node(){
            val = 0;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;

    void propagate(int idx){
        int val = lazy[idx];
        //Update idx*2
        IT[idx*2].val += val;
        lazy[idx*2]  += val;
        //Update idx*2+1
        IT[idx*2+1].val += val;
        lazy[idx*2+1]+=val;
        //Reset idx
        lazy[idx] = 0;
    }

    void comb(Node& i, Node& l, Node& r){
        //Combine func
        i.val = max(l.val,r.val);
    }

    LazySegmentTree(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, 0);
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            //Build logic
            IT[idx].val = 0;
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
            IT[idx].val += val;
            lazy[idx] +=val;
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val);
        update(idx*2+1,mid+1,r,x,y,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void updateSet(int idx, int l, int r, int x, int y, int val){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            IT[idx].val = val;
            lazy[idx] = 0;
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        updateSet(idx*2,l,mid,x,y,val);
        updateSet(idx*2+1,mid+1,r,x,y,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    int getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return -LLINF;
        if (x <= l && r <= y){
            return IT[idx].val;
        }

        propagate(idx);

        int mid = (l+r)/2;
        return max(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));

    }

};

int a[N];

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    LazySegmentTree IT(n);

    IT.update(1,1,n,1,1,a[1]);
    for (int i=2; i<=n; i++){
        int val = IT.getVal(1,1,n,1,i-1) + a[i];
        IT.update(1,1,n,1,i-1,-a[i]);
        IT.update(1,1,n,i,i,val);
    }
    int ans = -LLINF;
    for (int i=1; i<=n; i++){
        int val = IT.getVal(1,1,n,i,i) - a[i];
        // cout << val << endl;
        ans = max(ans,val); 
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

