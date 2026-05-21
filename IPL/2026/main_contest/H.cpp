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
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

struct LazySegmentTree{
    struct Node{
        int val,cnt;
        Node(){
            val = 0;
            cnt = 0;
        }
    };

    int n;
    vector<Node> IT;

    void comb(Node& i, Node& l, Node& r){
        i.val = l.val + r.val;
        i.cnt = l.cnt + r.cnt;
    }

    LazySegmentTree(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].cnt = 0;
            IT[idx].val = 0;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void updateVal(int idx, int l, int r, int x, int val, int cnt){
        if (x < l || r < x) return;
        if (x <= l && r <= x){
            IT[idx].val += val;
            IT[idx].cnt += cnt;
            return;
        }

        int mid = (l+r)/2;
        updateVal(idx*2,l,mid,x,val,cnt);
        updateVal(idx*2+1,mid+1,r,x,val,cnt);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    int walk(int idx, int l, int r, int val, int prev, int cnt) {
        // cout << idx << " " << l << " " << r << " " << prev << " " << cnt << endl;
        if (l == r) {
            if (prev + IT[idx].val >= val) return cnt+IT[idx].cnt;
            else return cnt;
        }

        int mid = (l+r)/2;

        if (prev + IT[idx*2].val >= val) {
            return walk(idx*2+1,mid+1,r,val,prev+IT[idx*2].val,cnt+IT[idx*2].cnt);
        }
        else {
            return walk(idx*2,l,mid,val,prev,cnt);
        }
    }
};

int n,k;
int a[N],b[N],pos[N];

void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        a[i]-=k;
    }
    vector<pii> v;
    for (int i=1; i<=n; i++){
        cin >> b[i];
        v.push_back({a[i],i});
    }
    sort(all(v),greater<pii>());
    for (int i=0; i<n; i++){
        pos[v[i].se] = i+1;
    }

    // for (int i=1; i<=n; i++){
    //     cout << pos[i] << endl;
    // }

    LazySegmentTree IT(n);
    for (int i=1; i<=n; i++){
        if (b[i] == 2) {
            IT.updateVal(1,1,n,pos[i],a[i],1);
        }
    }

    int ans = IT.walk(1,1,n,0,0,0);
    // cout << ans << endl;

    for (int i=1; i<=n; i++){
        // cout << "Iter " << i << endl;
        if (b[i] == 1) {
            IT.updateVal(1,1,n,pos[i],a[i],1);
        }
        else {
            IT.updateVal(1,1,n,pos[i],-a[i],-1);
        }
        ans = max(ans,IT.walk(1,1,n,0,0,0));
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

