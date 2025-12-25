/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma once

#define TEXT "AndOrMax"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
//#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 20;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

struct Node{
    int sumAnd,sumOr,lazyAnd,lazyOr,mx;
    Node() {
        sumAnd = (1<<LG)-1;
        sumOr = 0;
        lazyAnd = (1<<LG)-1;
        lazyOr = 0;
        mx = -1;
    }    
};

int n,q;
Node IT[4*N];

void applyAnd(int idx, int val) {
    IT[idx].sumAnd &= val;
    IT[idx].sumOr &= val;
    IT[idx].mx &= val;
    IT[idx].lazyAnd &= val;
    IT[idx].lazyOr &= val;
}

void applyOr(int idx, int val) {
    IT[idx].sumAnd |= val;
    IT[idx].sumOr |= val;
    IT[idx].mx |= val;
    IT[idx].lazyOr |= val; 
}

void propagate(int idx){
    if (IT[idx].lazyAnd != ((1<<LG)-1)) {
        int val = IT[idx].lazyAnd;
        applyAnd(idx<<1,val);
        applyAnd(idx<<1|1,val);

    }
    IT[idx].lazyAnd = ((1<<LG)-1);

    if (IT[idx].lazyOr != 0) {
        int val = IT[idx].lazyOr;
        applyOr(idx<<1,val);
        applyOr(idx<<1|1,val);
    }
    IT[idx].lazyOr = 0;
}

void comb(Node& l, Node& r, Node& i){
    i.sumAnd = l.sumAnd & r.sumAnd;
    i.sumOr = l.sumOr | r.sumOr;
    i.mx = max(l.mx,r.mx);
}

void build(int idx, int l, int r, int a[]){
    IT[idx].lazyAnd = (1<<LG)-1; 
    IT[idx].lazyOr = 0;
    if (l==r){
        IT[idx].mx = a[l];
        IT[idx].sumAnd = a[l];
        IT[idx].sumOr = a[l];
        return;
    }

    int mid = (l+r)/2;
    build(idx*2,l,mid,a);
    build(idx*2+1,mid+1,r,a);
    comb(IT[idx*2],IT[idx*2+1],IT[idx]);
}

void init(int _n, int a[]) {
    build(1,1,n,a);
}

void updateAnd(int idx, int l, int r, int x, int y, int val){
    // cerr << idx << " " << l << " " << r << endl;
    if (y < l || r < x) return;
    int eqClass = (IT[idx].sumAnd|(~IT[idx].sumOr));
    // for (int lg=0; lg<32; lg++){
    //     cerr << ((eqClass&(1<<lg))?1:0) << " ";
    //     cerr << (((~val)&(1<<lg))?1:0) << endl;
    // }
    // cerr << endl;
    if (x <= l && r <= y && (((~val)&eqClass) == (~val))){
        applyAnd(idx,val);
        return;
    }

    propagate(idx);

    int mid = (l+r)/2;
    updateAnd(idx*2,l,mid,x,y,val);
    updateAnd(idx*2+1,mid+1,r,x,y,val);
    comb(IT[idx*2],IT[idx*2+1],IT[idx]);
}

void updateOr(int idx, int l, int r, int x, int y, int val){
    // cerr << idx << " " << l << " " << r << endl;
    if (y < l || r < x) return;
    int eqClass = (IT[idx].sumAnd|(~IT[idx].sumOr));
    if (x <= l && r <= y && (((val)&eqClass) == (val))){
        applyOr(idx,val);
        return;
    }

    propagate(idx);

    int mid = (l+r)/2;
    updateOr(idx*2,l,mid,x,y,val);
    updateOr(idx*2+1,mid+1,r,x,y,val);
    comb(IT[idx*2],IT[idx*2+1],IT[idx]);
}


int getMax(int idx, int l, int r, int x, int y){
    if (y < l || r < x) return -1;
    if (x <= l && r <= y){
        return IT[idx].mx;
    }

    propagate(idx);

    int mid = (l+r)/2;
    return max(getMax(idx*2,l,mid,x,y),getMax(idx*2+1,mid+1,r,x,y));

}

int a[N];

void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    init(n,a);
    while (q--){
        int id,l,r,x; cin >> id >> l >> r;
        if (id == 1) {
            cin >> x;
            updateAnd(1,1,n,l,r,x);
        }
        if (id == 2) {
            cin >> x;
            updateOr(1,1,n,l,r,x);
        }
        if (id == 3) {
            int res = getMax(1,1,n,l,r);
            cout << res << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    // cin.tie(0) -> sync_with_stdio(0);
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

