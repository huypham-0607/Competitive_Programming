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
    int l,r;
    Node(): l{0}, r{0} {};
};

/*Global Variables*/
int n;
Node IT[N*4];
int a[N];

Node Combres(Node l, Node r){
    Node res;
    int mn = min(l.r,r.l);
    res.l=l.l+r.l-mn;
    res.r=r.r+l.r-mn;
    return res;
}

void Comb(Node& x, Node& l, Node& r){
    int mn = min(l.r,r.l);
    x.l=l.l+r.l-mn;
    x.r=r.r+l.r-mn;
}

void Update(int idx, int l, int r, int x, int val){
    if (x < l || r < x) return;
    if (l == r){
        IT[idx].l = 1;
        IT[idx].r = 0;
        if (!val) swap(IT[idx].l,IT[idx].r);
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,val);
    Update(idx*2+1,mid+1,r,x,val);
    Comb(IT[idx],IT[idx*2],IT[idx*2+1]);
}

Node Query(int idx, int l, int r, int x, int y){
    if (y < l || r < x) return Node();
    if (x <= l && r <= y) return IT[idx];
    int mid = (l+r)/2;
    return Combres(Query(idx*2,l,mid,x,y),Query(idx*2+1,mid+1,r,x,y));
}

/*Solution*/
void solve(){
    string s;
    cin >> s;
    n = s.size();
    for (int i=0; i<(int)s.size(); i++){
        if (s[i] == '1') a[i+1] = 1;
        else a[i+1] = 0;
        Update(1,1,n,i+1,a[i+1]);
    }
    int q;
    cin >> q;
    while (q--){
        int id;
        cin >> id;
        if (id == 1){
            int x;
            cin >> x;
            a[x] = (a[x]+1)%2;
            Update(1,1,n,x,a[x]);
        }
        else{
            int l,r;
            cin >> l >> r;
            Node bruh = Query(1,1,n,l,r);
//            cout << bruh.l << " " << bruh.r << endl;
            cout << bruh.l+bruh.r << endl;
        }
    }
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
