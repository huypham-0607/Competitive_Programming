/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
    int dp00, dp01, dp10, dp11;
    Node(): dp00{0}, dp01{0}, dp10{0}, dp11{0}{};
};

/*Global Variables*/
int n,q;
int a[N];
Node IT[N*4];

//Segment Tree
void Comb(Node& x, Node& l, Node& r){
    x.dp00 = max(l.dp00+r.dp10, l.dp01+r.dp00);
    x.dp01 = max(l.dp00+r.dp11, l.dp01+r.dp01);
    x.dp10 = max(l.dp10+r.dp10, l.dp11+r.dp00);
    x.dp11 = max(l.dp10+r.dp11, l.dp11+r.dp01);
}

void Build(int idx, int l, int r){
    if (l == r){
        IT[idx].dp11 = a[l];
        return;
    }
    int mid = (l+r)/2;
    Build(idx*2,l,mid); Build(idx*2+1,mid+1,r);
    Comb(IT[idx],IT[idx*2],IT[idx*2+1]);
}

void Update(int idx, int l ,int r, int x, int val){
    if (x < l || r < x) return;
    if (l == r){
        IT[idx].dp11 = val;
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,val); Update(idx*2+1,mid+1,r,x,val);
    Comb(IT[idx],IT[idx*2],IT[idx*2+1]);
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    int ans = 0;
    Build(1,1,n);
    while (q--){
        int x,val;
        cin >> x >> val;
        Update(1,1,n,x,val);
        ans+=max({IT[1].dp00, IT[1].dp01, IT[1].dp10, IT[1].dp11});
    }
    cout << ans;
}

/*Driver Code*/
signed main(){
    freopen("optmilk.in","r",stdin);
    freopen("optmilk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
