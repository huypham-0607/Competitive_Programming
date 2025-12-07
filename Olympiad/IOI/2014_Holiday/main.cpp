/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>
#include "holiday.h"

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

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

//Segment Tree
//Lmao

struct SegmentTree{
    struct Node{
        int sum,cnt;
        Node(){
            cnt = 0;
            sum = 0;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node l, Node r){
        if (l.cnt == 0) return r;
        if (r.cnt == 0) return l;

        Node i;
        i.cnt = l.cnt + r.cnt;
        i.sum = l.sum + r.sum;

        return i;
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].cnt = 0;
            IT[idx].sum = 0;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int cnt, int val){
        if (r < x || x < l) return;
        if (l==r){
            IT[idx].cnt = cnt;
            IT[idx].sum = val;
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,cnt,val);
        update(idx*2+1,mid+1,r,x,cnt,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    int walk(int idx, int l, int r, int cnt){
        if (l==r){
            if (IT[idx].cnt <= cnt) return IT[idx].sum;
            return 0;
        }

        int mid = (l+r)/2;
        if (IT[idx*2].cnt >= cnt){
            return walk(idx*2,l,mid,cnt);
        }
        else{
            return IT[idx*2].sum+walk(idx*2+1,mid+1,r,cnt-IT[idx*2].cnt);
        }
    }

    Node getNode(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return Node();
        if (x <= l && r <= y){
            return IT[idx];
        }

        int mid = (l+r)/2;
        return comb(getNode(idx*2,l,mid,x,y),getNode(idx*2+1,mid+1,r,x,y));

    }

    void init(int _n){
        n = _n;
        IT.clear();
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }
} IT;


int n,s,d;
int order[N];
int curidx = -1;
vector<pii> va,vb;
vector<int> dpl,dpr;


void update(int mid, vector<pii>& v){
    while (curidx<min(mid,(int)v.size()-1)){
        ++curidx;
        IT.update(1,1,n,v[curidx].fi,1,v[curidx].se);
    }
    while (curidx>min(mid,(int)v.size()-1)){
        IT.update(1,1,n,v[curidx].fi,0,0);
        --curidx;
    }
}

void DnC1(int l, int r, int optl, int optr, vector<int>& dp, vector<pii>& v){
    if (l>r) return;

    int mid = (l+r)/2;
    dp[mid] = 0;

//    cout << "mid: " << mid << " " << optl << " " << optr << endl;

    int optm = optl;
    for (int i=optl; i<=min(mid,optr); i++){
        update(i,v);
        int val = IT.walk(1,1,n,(mid-i));
//        cout << i << " " << val << endl;
        if (val > dp[mid]){
            dp[mid] = val;
            optm = i;
        }
    }

//    cout << optm << endl;

    DnC1(l,mid-1,optl,optm,dp,v);
    DnC1(mid+1,r,optm,optr,dp,v);
}

void DnC2(int l, int r, int optl, int optr, vector<int>& dp, vector<pii>& v){
    if (l>r) return;

    int mid = (l+r)/2;
    dp[mid] = 0;

//    cout << mid << endl;

    int optm = optl;
    for (int i=optl; i<=min(mid/2,optr); i++){
        update(i,v);
        int val = IT.walk(1,1,n,(mid-i*2));
        if (val > dp[mid]){
            dp[mid] = val;
            optm = i;
        }
    }

//    cout << optm << endl;

    DnC2(l,mid-1,optl,optm,dp,v);
    DnC2(mid+1,r,optm,optr,dp,v);
}

long long findMaxAttraction(signed _n, signed _s, signed _d, signed a[]){
    n = _n;
    s = _s;
    d = _d;
    va.resize(s+1);
    vb.resize(n-s);
    iota(order,order+n,0);
    sort(order,order+n,[&](int x, int y){return a[x]>a[y];});
//    for (int i=0; i<n; i++){
//        cout << order[i] << " ";
//    }
//    cout << endl;
    for (int i=0; i<n; i++){

        if (order[i] > s) vb[order[i]-s] = {i+1,a[order[i]]};
        if (order[i] < s) va[s-order[i]] = {i+1,a[order[i]]};
    }

//    for (auto x:va){
//        cout << x.fi << " " << x.se << endl;
//    }
//    cout << endl;
//    for (auto x:vb){
//        cout << x.fi << " " << x.se << endl;
//    }
//    cout << endl;

    dpl.resize(d+2);
    dpr.resize(d+2);

    int ans = 0;

    IT.init(n);
    curidx = -1;
    DnC1(1,d,1,(int)va.size()-1,dpl,va);
    update(-1,va);
    DnC2(1,d,1,(int)vb.size()-1,dpr,vb);
//    cout << "passed" << endl;

//    for (int i=0; i<=d; i++){
//        cout << dpl[i] << " " << dpr[i] << endl;
//    }
//    cout << endl;

    for (int i=0; i<=d; i++){
        ans = max(ans,dpl[i] + dpr[d-i]);
        if (i!=d) ans = max(ans,dpl[i] + dpr[d-i-1] + a[s]);
    }

    update(-1,vb);
    DnC2(1,d,1,(int)va.size()-1,dpl,va);
    update(-1,va);
    DnC1(1,d,1,(int)vb.size()-1,dpr,vb);

    for (int i=0; i<=d; i++){
        ans = max(ans,dpl[i] + dpr[d-i]);
        if (i!=d) ans = max(ans,dpl[i] + dpr[d-i-1] + a[s]);
    }

    return ans;
}

//signed _a[N];
//
//void solve(){
//    signed _n, _s, _d;
//    cin >> _n >> _s >> _d;
//    for (int i=0; i<_n; i++){
//        cin >> _a[i];
//    }
//    cout << findMaxAttraction(_n, _s, _d, _a);
//}
//
//signed main(){
////    cin.tie(0) -> sync_with_stdio(0);
//    if (fopen(TEXT".inp","r")){
//        freopen(TEXT".inp","r",stdin);
//        freopen(TEXT".out","w",stdout);
//    }
//
//    int testCount = 1;
////    cin >> testCount;
//    while (testCount--){
//        solve();
//    }
//
//    return 0;
//}
