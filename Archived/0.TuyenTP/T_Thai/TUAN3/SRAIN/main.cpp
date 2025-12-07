/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
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
int a[N],b[N];
pair<pii,pii> query[N];
vector<pair<int,pii>> v,del;

struct SegmentTree{
    pii ST[N*4];
    int lazy[N*4];

    void Propagate(int idx){
        int delta = lazy[idx];
        ST[idx*2].fi += delta*ST[idx*2].se;
        lazy[idx*2] += delta;
        ST[idx*2+1].fi += delta*ST[idx*2+1].se;
        lazy[idx*2+1] += delta;
        lazy[idx] = 0;
    }

    pii Comb(pii x, pii y){
        return make_pair(x.fi+y.fi,x.se+y.se);
    }

    void Build(int idx, int l, int r, int a[]){
        if (l==r){
            ST[idx] = {a[l],1};
            return;
        }
        int mid = (l+r)/2;
        Build(idx*2,l,mid,a);
        Build(idx*2+1,mid+1,r,a);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    void UpdateAdd(int idx, int l, int r, int x, int y, int val){
        if (y<l || r<x) return;
        if (x<=l && r<=y){
            ST[idx].fi += val*ST[idx].se;
            lazy[idx] += val;
            return;
        }
        Propagate(idx);
        int mid = (l+r)/2;
        UpdateAdd(idx*2,l,mid,x,y,val);
        UpdateAdd(idx*2+1,mid+1,r,x,y,val);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    void UpdateRed(int idx, int l, int r, int x){
        if (x<l || r<x) return;
        if (l==r){
            ST[idx].se -= 1;
            return;
        }
        Propagate(idx);
        int mid = (l+r)/2;
        UpdateRed(idx*2,l,mid,x);
        UpdateRed(idx*2+1,mid+1,r,x);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    int Get(int idx, int l, int r, int x, int y){
        if (y<l || r<x) return 0;
        if (x<=l && r<=y) return ST[idx].fi;
        Propagate(idx);
        int mid = (l+r)/2;
        return Get(idx*2,l,mid,x,y)+Get(idx*2+1,mid+1,r,x,y);
    }
} ST;

struct SegmentTreeWalk{
    int ST[4*N];

    void Update(int idx, int l, int r, int x, int val){
        if (x<l || r<x) return;
        if (l==r){
            ST[idx]+=val;
            return;
        }
        int mid = (l+r)/2;
        Update(idx*2,l,mid,x,val);
        Update(idx*2+1,mid+1,r,x,val);
        ST[idx] = ST[idx*2] + ST[idx*2+1];
    }

    pii Query(int idx, int l, int r, int val){
        if (l==r){
            return make_pair(l,ST[idx]-val);
        }
        int mid = (l+r)/2;
        if (ST[idx*2]>val) return Query(idx*2,l,mid,val);
        else return Query(idx*2+1,mid+1,r,val-ST[idx*2]);
    }

    pii Get(int val, int q){
        if (ST[1]<=val) return make_pair(q+1,0);
        else return Query(1,1,q,val);
    }
} STW;

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i] >> b[i];
    }
    ST.Build(1,1,n,a);
    cin >> q;
    for (int i=1; i<=q; i++){
        int id,l,r,d=0;
        cin >> id >> l >> r;
        if (id==0) cin >> d;
        query[i] = {{id,d},{l,r}};
        if (id == 0){
            v.push_back({l,{i,d}});
            v.push_back({r+1,{i,-d}});
        }
    }
    int idx = 0;
    sort(v.begin(),v.end());
    for (int i=1; i<=n; i++){
        while (idx!=v.size() && v[idx].fi == i){
            STW.Update(1,1,q,v[idx].se.fi,v[idx].se.se);
            ++idx;
        }
        pii res = STW.Get(b[i]-a[i],q);
//        cout << STW.ST[1] << " " << v[idx].fi << endl;
//        cout << i << " " << res.fi << " " << res.se << endl;
        del.push_back({res.fi,{i,res.se}});
    }
    sort(all(del));
    idx = 0;
    for (int i=1; i<=q; i++){
        if (query[i].fi.fi == 0){
            int val = query[i].fi.se;
            int l = query[i].se.fi;
            int r = query[i].se.se;
            ST.UpdateAdd(1,1,n,l,r,val);
        }
        else{
            int l = query[i].se.fi;
            int r = query[i].se.se;
            cout << ST.Get(1,1,n,l,r) << endl;
        }

        while (idx!=del.size() && del[idx].fi == i){
            int pos = del[idx].se.fi;
            int val = del[idx].se.se;
//            cout << pos << " " << del[idx].fi << " " << val << endl;
            ST.UpdateAdd(1,1,n,pos,pos,-val);
            ST.UpdateRed(1,1,n,pos);
            ++idx;
        }
    }
}

/*Driver Code*/
signed main(){
//    freopen("K.inp","r",stdin);
//    freopen("K.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

