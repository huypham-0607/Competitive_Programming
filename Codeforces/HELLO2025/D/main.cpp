/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,q;
int val[N];

struct Node{
    int sz, maxl, maxr, minl, minr, best;

    Node(){
        sz = 1;
        maxl = 0;
        maxr = 0;
        minl = 0;
        minr = 0;
        best = -1;
    }
};

Node Comb(Node l, Node r){
    Node res;
    res.sz = l.sz + r.sz;
    res.maxl = max(l.maxl,r.maxl-l.sz);
    res.maxr = max(l.maxr-r.sz,r.maxr);
    res.minl = min(l.minl,r.minl+l.sz);
    res.minr = min(l.minr+r.sz,r.minr);
    res.best = max({l.best,r.best,l.maxr - r.minl, r.maxl - l.minr});
    return res;
}

struct SegTree{
    int n;
    vector<Node> ST;

    void Build (int idx, int l, int r, int val[]){
        if (l==r){
            ST[idx].sz = 1;
            ST[idx].maxl = val[l]-1;
            ST[idx].maxr = val[l]-1;
            ST[idx].minl = val[l]+1;
            ST[idx].minr = val[l]+1;
            ST[idx].best = -1;
            return;
        }

        int mid = (l+r)/2;
        Build(idx*2,l,mid,val);
        Build(idx*2+1,mid+1,r,val);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    void Init(int _n, int val[]){
        n = _n;
        ST.clear();
        ST.resize(4*n+10);
        Build(1,1,n,val);
    }

    void Update(int idx, int l, int r, int x, int val){
        if (x<l || r<x) return;
        if (l==r){
            ST[idx].sz = 1;
            ST[idx].maxl = val-1;
            ST[idx].maxr = val-1;
            ST[idx].minl = val+1;
            ST[idx].minr = val+1;
            ST[idx].best = -1;
            return;
        }
        int mid = (l+r)/2;
        Update(idx*2,l,mid,x,val);
        Update(idx*2+1,mid+1,r,x,val);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }
} ST;

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> val[i];
    }
    ST.Init(n,val);
    cout << ST.ST[1].best+1 << endl;
    for (int id=1; id<=q; id++){
        int x; int val;
        cin >> x >> val;
        ST.Update(1,1,ST.n,x,val);
        cout << ST.ST[1].best+1 << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
