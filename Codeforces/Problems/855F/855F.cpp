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

int n;

struct LazySegmentTree{
    struct Node{
        int val1,val2,cnt,sum;
        Node(){
            val1 = 0;
            val2 = 0;
            cnt = 0;
            sum = 0; gh
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;

    void applyMin(int idx, int val) {
        IT[idx].sum -= (IT[idx].val1-val)*IT[idx].cnt;
        IT[idx].val1 = val;
        
        lazy[idx] = val;
    }

    void propagate(int idx){
        if (lazy[idx]!=-1) {
            int val = lazy[idx];
            //Update idx*2
            applyMin(idx*2,val);
            //Update idx*2+1
            applyMin(idx*2+1,val);
        }

        //Reset idx
        lazy[idx] = -1;
    }

    void comb(Node& i, Node l, Node r){
        if (l.val1 < r.val1) swap(l,r);
        
        i.val1 = l.val1;
        if (l.val1 == r.val1) {
            i.val2 = max(l.val2,r.val2);
            i.cnt = l.cnt + r.cnt;
        } else {
            i.val2 = max(l.val2,r.val1);
            i.cnt = l.cnt;
        }
        i.sum = l.sum + r.sum;
    }

    LazySegmentTree(int _n, int a[]) {
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, -1);
        build(1,1,n,a);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val1 = 0;
            IT[idx].val2 = -1;
            IT[idx].cnt = 1;
            IT[idx].sum = 0;
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
            // Update logic

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

        }

        propagate(idx);

        int mid = (l+r)/2;
        return max(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));

    }

} IT;


void solve(){
    cin >> n >> q;
    for (int i=1; i<=n)
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

