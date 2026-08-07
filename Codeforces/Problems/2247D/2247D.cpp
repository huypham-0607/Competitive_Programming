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

const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

struct SegmentTree{
    struct Node{
        int mx,mn,ans;
        Node(){
            mx = INF;
            mn = INF;
            ans = 0;
        }
    };

    int n;
    vector<Node> IT;

    void comb(Node& i, Node& l, Node& r, int val){
        i.mx = max(l.mx,r.mx);
        i.mn = min(l.mn,r.mn);
        i.ans = max(l.ans,r.ans);
        if (l.mx > r.mn){
            i.ans = val;
        }
        // cout << l.mx << " " << l.mn << " " << l.ans << endl;
        // cout << r.mx << " " << r.mn << " " << r.ans << endl;
        // cout << i.mx << " " << i.mn << " " << i.ans << endl;
    }

    SegmentTree(int _n) {
        n = _n;
        // N is 
        IT.resize(n*4+10, Node());
        build(1,0,n);
    }

    void build(int idx, int l, int r){
        if (l==r-1){
            IT[idx].mx = IT[idx].mn = INF;
            return;
        }

        int mid = l+(r-l)/2;
        int msb = (1<<(63-__builtin_clzll(l^mid)));
        build(idx*2,l,mid);
        build(idx*2+1,mid,r);
        comb(IT[idx],IT[idx*2],IT[idx*2+1],msb);
    }

    void update(int idx, int l, int r, int x, int val){
        if (r <= x || x < l) return;
        // cout << "idx:" << idx << endl;
        if (l==r-1){
            IT[idx].mn = IT[idx].mx = val;
            return;
        }
        int mid = l+(r-l)/2;
        int msb = (1<<(63-__builtin_clzll(l^mid)));
        update(idx*2,l,mid,x,val);
        update(idx*2+1,mid,r,x,val);
        // cout << "comb: " << l << " " << mid << endl;
        comb(IT[idx],IT[idx*2],IT[idx*2+1],msb);
    }

    int getVal(){
        return IT[1].ans;
    }
};


int n,q;

void solve(){
    cin >> n >> q;
    int m = (1<<(64-__builtin_clzll(n-1)));
    // cout << "m" << m << endl;
    SegmentTree IT(m);
    frep(i,0,n){
        int x; cin >> x;
        IT.update(1,0,m,i,x);
    }
    cout << IT.getVal() << endl;
    ffor(uwu,1,q){
        int x,val; cin >> x >> val;
        IT.update(1,0,m,x,val);
        cout << IT.getVal() << endl;
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

