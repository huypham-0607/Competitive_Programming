/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int B = 316;
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
struct Query{
    int l,r,block,id;
    Query(int _l,int _r,int _block,int _id): l(_l), r(_r), block(_block), id(_id){};
    bool operator<(const Query& x)const{
        if (block==x.block){
            if (block%2) return r>x.r;
            else return r<x.r;
        }
        else return block<x.block;
    }
};

int n,q;
int a[N];
ll ans[N];
vector<int> cc;
vector<Query> query;

struct BinaryIndexedTree{
    int n;
    vector<int> BIT;

    BinaryIndexedTree(int _n): n(_n){
        BIT.resize(n+10);
    };

    void Update(int idx, int val){
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    ll Query(int idx){
        ll res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    ll Get(int l, int r){
        return Query(r) - Query(l-1);
    }
};



/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=0; i<n; i++){
        cin >> a[i];
        cc.push_back(a[i]);
    }

    sort(all(cc));
    cc.resize(unique(all(cc))-cc.begin());
    for (int i=0; i<n; i++){
        a[i] = lower_bound(all(cc),a[i]) - cc.begin() +1;
    }

    BinaryIndexedTree BIT((int)cc.size());

    for (int i=1; i<=q; i++){
        int l,r; cin >> l >> r;
        --r;
        int block = l/B;
        query.push_back(Query(l,r,block,i));
    }

    sort(all(query));

    int n = cc.size();
    int l = 0, r = -1;
    ll res = 0;

    for (auto in:query){
//        cout << in.l << " " << in.r << endl;
        while (l>in.l){
            --l;
            res+=BIT.Get(1,a[l]-1);
            BIT.Update(a[l],1);
        }
        while (r<in.r){
            ++r;
            res+=BIT.Get(a[r]+1,n);
            BIT.Update(a[r],1);
        }
        while (l<in.l){
            res-=BIT.Get(1,a[l]-1);
            BIT.Update(a[l],-1);
            ++l;
        }
        while (r>in.r){
            res-=BIT.Get(a[r]+1,n);
            BIT.Update(a[r],-1);
            --r;
        }
        ans[in.id] = res;
    }
    for (int i=1; i<=q; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
