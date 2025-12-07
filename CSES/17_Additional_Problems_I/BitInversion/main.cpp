/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
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

struct Node{
    int l0, r0, b0, l1, r1, b1, sz;
    Node(): l0(0),r0(0),b0(0),l1(0),r1(0),b1(0),sz(0){};
};

/*Global Variables*/
int n;
int a[N];
Node IT[N*4];

void UPT(Node& x, Node& l, Node& r){
    x.sz = l.sz+r.sz;
    x.l0 = l.l0 + ((l.l0 == l.sz)? r.l0 : 0);
    x.l1 = l.l1 + ((l.l1 == l.sz)? r.l1 : 0);
    x.r0 = r.r0 + ((r.r0 == r.sz)? l.r0 : 0);
    x.r1 = r.r1 + ((r.r1 == r.sz)? l.r1 : 0);
    x.b0 = max({l.b0,r.b0,l.r0+r.l0});
    x.b1 = max({l.b1,r.b1,l.r1+r.l1});
}

void build(int idx, int l, int r){
    if (l == r){
        IT[idx].sz = 1;
        if (a[l]){
            IT[idx].l1 = 1;
            IT[idx].r1 = 1;
            IT[idx].b1 = 1;
        }
        else {
            IT[idx].l0 = 1;
            IT[idx].r0 = 1;
            IT[idx].b0 = 1;
        }
        return;
    }
    int mid = (l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    UPT(IT[idx], IT[idx*2], IT[idx*2+1]);
}

void update(int idx, int l, int r, int x){
//    cout << idx << endl;
    if (x < l || r < x) return;
    if (l == r){
        swap(IT[idx].l0,IT[idx].l1);
        swap(IT[idx].r0,IT[idx].r1);
        swap(IT[idx].b0,IT[idx].b1);
        return;
    }
    int mid = (l+r)/2;
    update(idx*2,l,mid,x);
    update(idx*2+1,mid+1,r,x);
    UPT(IT[idx],IT[idx*2],IT[idx*2+1]);
}

/*Solution*/
void solve(){
    string s;
    cin >> s;
    for (int i=0; i<(int)s.size(); i++){
        if (s[i] == '0') a[i+1] = 0;
        else a[i+1] = 1;
    }
    n = (int) s.size();
    build(1,1,n);
    int q;
    cin >> q;
    while (q--){
        int x;
        cin >> x;
//        cout << x << endl;
        update(1,1,n,x);
        cout << max(IT[1].b0,IT[1].b1) << endl;
    }
}

/*Driver Code*/
int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
