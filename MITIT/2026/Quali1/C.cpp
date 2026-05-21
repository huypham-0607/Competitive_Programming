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

struct SegmentTree{
    struct Node{
        int mn;
        Node(){
            mn = INF;
        }
    };

    int n;
    vector<Node> IT;

    void comb(Node& i, Node& l, Node& r){
        i.mn = min(l.mn,r.mn);
    }

    SegmentTree(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].mn = 0;
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
            IT[idx].mn = val;
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val);
        update(idx*2+1,mid+1,r,x,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    int getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return INF;
        if (x <= l && r <= y){
            return IT[idx].mn;
        }

        int mid = (l+r)/2;
        return min(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));
    }
};

int n,q;
int a[N];

void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    int l = 1, mid = (n/2) + ((n%2) ? 1 : 0), r = n;
    int nl = mid, nr = r - mid;
    int sl = 0, sr = 0;
    
    SegmentTree ITL(nl), ITR(nr);
    for (int i=1; i<=mid; i++){
        ITL.update(1,1,nl,i,a[i]);
        sl+=a[i];
    }
    for (int i=1; i<=nr; i++){
        ITR.update(1,1,nr,i,a[mid+i]);
        sr+=a[mid+i];
    }

    pii tmp = {ITL.getVal(1,1,nl,1,nl), ITR.getVal(1,1,nr,1,nr)};
    int res1 = sl+((n%2)?min(tmp.fi,tmp.se):max(tmp.fi,tmp.se))-tmp.fi;
    int res2 = sr+((n%2)?max(tmp.fi,tmp.se):min(tmp.fi,tmp.se))-tmp.se;
    cout << res1 << " " <<  res2 << endl;

    for (int i=1; i<=q; i++){
        int x,w; cin >> x >> w;
        if (x <= mid) {
            ITL.update(1,1,nl,x,w);
            sl-=a[x];
            a[x] = w;
            sl+=a[x];
        }
        else{ 
            ITR.update(1,1,nr,x-mid,w);
            sr-=a[x];
            a[x] = w;
            sr+=a[x];
        }
        pii tmp = {ITL.getVal(1,1,nl,1,nl), ITR.getVal(1,1,nr,1,nr)};
        int res1 = sl+((n%2)?min(tmp.fi,tmp.se):max(tmp.fi,tmp.se))-tmp.fi;
        int res2 = sr+((n%2)?max(tmp.fi,tmp.se):min(tmp.fi,tmp.se))-tmp.se;
        cout << res1 << " " <<  res2 << endl;
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

