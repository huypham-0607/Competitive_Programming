/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "438D"

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

struct SegmentTree{
    struct Node{
        int mx,sum;
        Node(){
            mx = -1;
            sum = -1;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node l, Node r){
        if (l.mx == -1) return r;
        if (r.mx == -1) return l;

        Node i;
        i.mx = max(l.mx,r.mx);
        i.sum = l.sum + r.sum;

        return i;
    }

    void build(int idx, int l, int r, int a[]){
        if (l==r){
            IT[idx].mx = a[l];
            IT[idx].sum = a[l];
            return;
        }
        
        int mid = (l+r)/2;
        build(idx*2,l,mid,a);
        build(idx*2+1,mid+1,r,a);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    SegmentTree(int _n, int a[]) {
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n,a); 
    }

    void updateMod(int idx, int l, int r, int x, int y, int val){
        if (r < x || y < l || IT[idx].mx < val) return;
        if (l==r){
            IT[idx].mx = IT[idx].mx%val;
            IT[idx].sum = IT[idx].mx;
            return;
        }
        int mid = (l+r)/2;
        updateMod(idx*2,l,mid,x,y,val);
        updateMod(idx*2+1,mid+1,r,x,y,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void updateSet(int idx, int l, int r, int x, int val) {
        if (r < x || x < l) return;
        if (l==r) {
            IT[idx].mx = val;
            IT[idx].sum = val;
            return;
        }
        int mid = (l+r)/2;
        updateSet(idx*2,l,mid,x,val);
        updateSet(idx*2+1,mid+1,r,x,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    int getSum(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return 0;
        if (x <= l && r <= y){
            return IT[idx].sum;
        }

        int mid = (l+r)/2;
        return getSum(idx*2,l,mid,x,y)+getSum(idx*2+1,mid+1,r,x,y);

    }
};

int n,q;
int a[N];

void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    SegmentTree IT(n,a);

    while (q--){ 
        int id; cin >> id;
        if (id == 1) {
            int l,r; cin >> l >> r;
            cout << IT.getSum(1,1,n,l,r) << endl;
        }
        if (id == 2) {
            int l,r,x; cin >> l >> r >> x;
            IT.updateMod(1,1,n,l,r,x);
        }
        if (id == 3) {
            int pos,x; cin >> pos >> x;
            IT.updateSet(1,1,n,pos,x);
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

