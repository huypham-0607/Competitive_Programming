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
    int s1,s2,e1,e2;
    Node(): s1{0}, s2{0}, e1{0}, e2{0} {};
    void Init(pii val){
        s1 = e1 = val.fi;
        s2 = e2 = val.se;
    }
};

/*Global Variables*/
int n,q;
pii a[N];
Node IT[N*4];

void Comb(Node& x, Node& l, Node& r){
    x.s1 = l.s1;
    x.s2 = l.s2;
    if (l.e1<=r.s1) x.e1 = r.e1;
    else if (l.e1<=r.s2) x.e1 = r.e2;
    else x.e1 = +INF;
    if (l.e2<=r.s1) x.e2 = r.e1;
    else if (l.e2<=r.s2) x.e2 = r.e2;
    else x.e2 = +INF;
}

void Build(int idx, int l, int r){
    if (l == r){
        IT[idx].Init(a[l]);
//        cout << idx << " " << l << " " << r << endl;
//        cout << IT[idx].s1 << " " << IT[idx].s2 << " " << IT[idx].e1 << " " << IT[idx].e2 << endl;
        return;
    }
    int mid = (l+r)/2;
    Build(idx*2,l,mid); Build(idx*2+1,mid+1,r);
    Comb(IT[idx], IT[idx*2], IT[idx*2+1]);
//    cout << idx << " " << l << " " << r << endl;
//    cout << IT[idx].s1 << " " << IT[idx].s2 << " " << IT[idx].e1 << " " << IT[idx].e2 << endl;
}

void Update(int idx, int l, int r, int x, pii val){
    if (x < l || r < x) return;
    if (l == r){
        IT[idx].Init(val);
//        cout << idx << " " << l << " " << r << endl;
//        cout << IT[idx].s1 << " " << IT[idx].s2 << " " << IT[idx].e1 << " " << IT[idx].e2 << endl;
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,val); Update(idx*2+1,mid+1,r,x,val);
    Comb(IT[idx], IT[idx*2], IT[idx*2+1]);
//    cout << idx << " " << l << " " << r << endl;
//    cout << IT[idx].s1 << " " << IT[idx].s2 << " " << IT[idx].e1 << " " << IT[idx].e2 << endl;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i].fi >> a[i].se;
        if (a[i].fi > a[i].se) swap(a[i].fi,a[i].se);
    }
    Build(1,1,n);
    cin >> q;
    while (q--){
        int pos1, pos2;
        cin >> pos1 >> pos2;
        swap(a[pos1],a[pos2]);
        Update(1,1,n,pos1,a[pos1]);
        Update(1,1,n,pos2,a[pos2]);
        if (IT[1].e1 == INF && IT[1].e2 == INF) cout << "NIE" << endl;
        else cout << "TAK" << endl;
//        swap(a[pos1],a[pos2]);
//        Update(1,1,n,pos1,a[pos1]);
//        Update(1,1,n,pos2,a[pos2]);
    }
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
