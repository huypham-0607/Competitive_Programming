/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
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
int a[N];
int pre[N];

//BIT
int BIT[N];

void UpdateBIT(int x, int val){
    while (x<=n){
        BIT[x]+=val;
        x+=(x&(-x));
    }
}

int QueryBIT(int x){
    int res = 0;
    while (x>0){
        res+=BIT[x];
        x-=(x&(-x));
    }
    return res;
}

//ST
int ST[4*N];
int lazy[4*N];

void Propagate(int idx, int l, int r, int mid){
    int t = lazy[idx];

    ST[idx*2]+=t;
    lazy[idx*2]+=t;

    ST[idx*2+1]+=t;
    lazy[idx*2+1]+=t;

    lazy[idx] = 0;
}

void BuildST(int idx, int l, int r){
    if (l==r){
        ST[idx] = pre[l];
        return;
    }
    int mid = (l+r)/2;
    BuildST(idx*2,l,mid);
    BuildST(idx*2+1,mid+1,r);
    ST[idx] = max(ST[idx*2],ST[idx*2+1]);
}

void UpdateST(int idx, int l, int r, int x, int y, int val){
    if (r<x || y<l) return;
    if (x<=l && r<=y){
        ST[idx]+=val;
        lazy[idx]+=val;
        return;
    }

//    cout << idx << " " << l << " " << r << endl;
    int mid = (l+r)/2;
    Propagate(idx,l,r,mid);

    UpdateST(idx*2,l,mid,x,y,val);
    UpdateST(idx*2+1,mid+1,r,x,y,val);
    ST[idx] = max(ST[idx*2],ST[idx*2+1]);
}

int QueryST(int idx, int l, int r, int x, int y){
    if (r<x || y<l) return -LLINF;
    if (x<=l && r<=y) return ST[idx];

    int mid = (l+r)/2;
    Propagate(idx,l,r,mid);

    return max(QueryST(idx*2,l,mid,x,y),QueryST(idx*2+1,mid+1,r,x,y));
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        pre[i] = pre[i-1]+a[i];
        UpdateBIT(i,a[i]);
    }
    BuildST(1,1,n);
    while (q--){
        int id,x,y;
        cin >> id >> x >> y;
        if (id == 1){
            int delta = y-a[x];
            UpdateST(1,1,n,x,n,delta);
//            cout << "meow" << endl;
            UpdateBIT(x,delta);
            a[x] = y;
        }
        else{
            int rawr = QueryBIT(x-1);
            int res = max(rawr,QueryST(1,1,n,x,y));
            cout << res-rawr << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
