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

const int N = 2e5+10;
const int LG = 18;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m,q;
int a[N];
int b[N];
int nxt[N];
int up[LG][N];
int reach[N];

struct SegmentTree{
    struct Node{
        int val;
        Node(){
            val = INF;
        }
    };

    int n;
    vector<Node> IT;

    void comb(Node& i, Node& l, Node& r){
        i.val = min(l.val,r.val);
    }

    SegmentTree(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val = LLINF;
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
            IT[idx].val = val;
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val);
        update(idx*2+1,mid+1,r,x,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    int getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return LLINF;
        if (x <= l && r <= y){
            return IT[idx].val;
        }

        int mid = (l+r)/2;
        return min(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));

    }
};


void solve(){
    cin >> n >> m >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    ffor(i,1,m) cin >> b[i];
    for (int i=1; i<=n; i++){
        nxt[a[i]] = a[(i%n)+1];
    }
    
    vector<int> last(n+1,m+1);
    for (int lg=0; lg<LG; lg++){
        up[lg][m+1] = m+1;
    }

    SegmentTree IT(m);

    for (int i=m; i>0; i--){
        up[0][i] = last[nxt[b[i]]];
        // cout << last[nxt[b[i]]] << endl;
        for (int lg=1; lg<LG;lg++){
            up[lg][i] = up[lg-1][up[lg-1][i]];
        }
        // for (int lg=0; lg<LG; lg++){
        //     cout << up[lg][i] << " ";
        // }
        // cout << endl;
        int u = i;
        for (int lg=LG-1; lg>=0; lg--){
            if ((n-1)&(1<<lg)) {
                u = up[lg][u];
            }
        }
        // cout << u << endl;
        IT.update(1,1,m,i,u);
        last[b[i]] = i;
    }

    for (int i=1; i<=q; i++){
        int u,v; cin >> u >> v;
        // cout << IT.getVal(1,1,m,u,v) << endl;
        cout << ((IT.getVal(1,1,m,u,v)<=v)?1:0);
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

