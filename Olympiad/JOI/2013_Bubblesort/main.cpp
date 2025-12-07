/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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

//Segment Tree

struct SegmentTree{
    struct Node{
        int cnt;
        Node(){
            cnt = 0;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node l, Node r){
        if (l.cnt == 0) return r;
        if (r.cnt == 0) return l;

        Node i;
        i.cnt = l.cnt + r.cnt;

        return i;
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].cnt = 0;
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
            IT[idx].cnt+=val;
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val);
        update(idx*2+1,mid+1,r,x,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    int getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return 0;
        if (x <= l && r <= y){
            return IT[idx].cnt;
        }

        int mid = (l+r)/2;
        return getVal(idx*2,l,mid,x,y)+getVal(idx*2+1,mid+1,r,x,y);

    }

    void init(int _n){
        n = _n;
        IT.clear();
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }
} IT;

int n,m;
int a[N],dp[N];
int lpos[N],rpos[N];
vector<int> pos[N];
vector<pii> lse, rse;
int x,y;

void update(int l, int r){
    while (x<l){
        for (auto i:pos[x]) IT.update(1,1,n,i,-1);
        ++x;
    }
    while (l<x){
        --x;
        for (auto i:pos[x]) IT.update(1,1,n,i,1);
    }
    while (y<r){
        ++y;
        for (auto i:pos[y]) IT.update(1,1,n,i,1);
    }
    while (r<y){
        for (auto i:pos[y]) IT.update(1,1,n,i,-1);
        --y;
    }
}

void DnC(int l, int r, int optl, int optr){
    if (l>r) return;

    int mid = (l+r)/2;
    dp[mid] = -INF;
    int optm = optl;

//    cout << "Mid: " << mid << endl;
//    if (mid == 136){
//        cout << l << " " << r << " " << optl << " " << optr << endl;
//    }

    for (int i=optl; (i<=optr && lse[i].se <= min(lse[optr].se,rse[mid].se)); i++){
        int valueL = lse[i].fi;
        int valueR = rse[mid].fi;
        int posL = lse[i].se;
        int posR = rse[mid].se;
//        if (valueL < valueR) continue;
//        if (mid == 136){
//            cout << i << endl;
//            cout << valueL << " " << valueR << " " << posL << " " << posR << endl;
//        }
        update(valueR,valueL);
        int cnt = 0;
        cnt = IT.getVal(1,1,n,posL,posR)*2;
        int dec = 0;
        dec += pos[valueR].end() - lower_bound(all(pos[valueR]),posL);
        dec += upper_bound(all(pos[valueL]),posR) - pos[valueL].begin();
        dec += 1;

//        cout << cnt << " " << dec << endl;
        int sum = cnt - dec;
        if (dp[mid]<sum){
            dp[mid] = sum;
            optm = i;
        }
    }

    DnC(l,mid-1,optl,optm);
    DnC(mid+1,r,optm,optr);
}

void solve(){
    vector<int> nen;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        nen.push_back(a[i]);
    }
//    if (is_sorted(a+1,a+1+n)){
//        cout << 1 << endl;
//        return;
//    }

    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());
    m = nen.size();

    for (int i=1; i<=m; i++){
        lpos[i] = INF;
        rpos[i] = 0;
    }

    for (int i=1; i<=n; i++){
        a[i] = lower_bound(all(nen),a[i]) - nen.begin()+1;
        pos[a[i]].push_back(i);
        lpos[a[i]] = min(lpos[a[i]],i);
        rpos[a[i]] = max(rpos[a[i]],i);
//        cout << a[i] << endl;
    }

    int totalInv = 0;
    IT.init(m);
    for (int i=1; i<=n; i++){
        int val = IT.getVal(1,1,m,a[i]+1,m);
//        cout << i << " " << val << endl;
        totalInv += val;
        IT.update(1,1,m,a[i],1);
    }

    lse.push_back({0,0});
    rse.push_back({0,0});
    for (int i=1; i<=m; i++){
        while (lse.size() > 1 && lse.back().se > lpos[i]){
            lse.pop_back();
        }
        lse.push_back({i,lpos[i]});
        if (rse.size()<=1 || rse.back().se < rpos[i]){
            rse.push_back({i,rpos[i]});
        }
    }

//    for (int i=1; i<=m; i++){
//        cout << i << endl;
//        for (auto x:pos[i]) cout << x << " ";
//        cout << endl;
//    }

//    for (auto in:lse){
//        cout << in.fi << " " << in.se << endl;
//    }
//    cout << endl;
//    for (auto in:rse){
//        cout << in.fi << " " << in.se << endl;
//    }
//    cout << endl;

    IT.init(n);
    x = 1; y = 0;

    DnC(1,rse.size()-1,1,lse.size()-1);

    int best = -INF;
    if (m!=n){
        best = 0;
    }
    for (int i=1; i<=(int)rse.size()-1; i++){
        best = max(best,dp[i]);
//        cout << dp[i] << endl;
    }

//    cout << totalInv << " " << best << endl;

    cout << totalInv - best << endl;

}

/*Driver Code*/
signed main(){
//    cin.tie(0) -> sync_with_stdio(0);
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
