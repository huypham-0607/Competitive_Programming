#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7;
const long long LLINF = 1e18+3;

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

    void applyAdd(int idx, int val) {
        IT[idx].val += val;
        lazy[idx] += val;
    }

    void propagate(int idx){
        int val = lazy[idx];
        if (val) {
            applyAdd(idx*2,val);
            applyAdd(idx*2+1,val);
        } 

        lazy[idx] = 0;
    }

    void comb(Node& i, Node& l, Node& r){
        i.val = min(l.val,r.val);
    }

    LazySegmentTree(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, 0);
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
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
            applyAdd(idx,val);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val);
        update(idx*2+1,mid+1,r,x,y,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    int getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return LLINF;
        if (x <= l && r <= y){
            return IT[idx].val;
        }

        propagate(idx);

        int mid = (l+r)/2;
        return min(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));

    }

};

int n,k;
int a[N];
int delta;

void solve(){
    cin >> n >> k;
    LazySegmentTree IT(n);
    vector<pii> query;
    int sum = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        a[i] = a[i]%k;
        int delta = (a[i]-a[i-1]+k)%k;
        sum+=delta;
        IT.update(1,1,n,i,n,delta);
        query.push_back({delta,i});
    }
    sort(all(query),greater<pii>());
    for (auto [delta,pos]:query) {
        int res = IT.getVal(1,1,n,pos,n);
        int inv_delta = k-delta;
        if (res >= k) {
            sum-=delta;
            IT.update(1,1,n,pos,n,-k);
        }
    }
    cout << sum << endl;
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

