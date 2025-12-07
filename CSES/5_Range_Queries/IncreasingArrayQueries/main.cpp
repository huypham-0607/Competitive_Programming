/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<pii,int>
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
int ans[N];
priority_queue<piii> query;
int pre[N];
stack<pii> s;

//SEGGS
int IT[4*N];
int lazy[4*N];


void Update(int idx, int l, int r, int x, int y, int val){
//    cout << idx << endl;
    if (lazy[idx]){
        IT[idx] = lazy[idx]*(r-l+1);
        if (l!=r){
            lazy[idx*2] = lazy[idx];
            lazy[idx*2+1] = lazy[idx];
        }
    }
    if (y < l || r < x) return;
    if (x <= l && r <= y){
        IT[idx] = val*(r-l+1);
        if (l!=r){
            lazy[idx*2] = val;
            lazy[idx*2+1] = val;
        }
        return;
    }

    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,y,val); Update(idx*2+1,mid+1,r,x,y,val);
    IT[idx] = IT[idx*2] + IT[idx*2+1];
}

int Get(int idx, int l, int r, int x, int y){
    if (lazy[idx]){
        IT[idx] = lazy[idx]*(r-l+1);
        if (l!=r){
            lazy[idx*2] = lazy[idx];
            lazy[idx*2+1] = lazy[idx];
        }
    }
    if (y < l || r < x) return 0;
    if (x <= l && r <= y){
        return IT[idx];
    }

    int mid = (l+r)/2;
    return Get(idx*2,l,mid,x,y) + Get(idx*2+1,mid+1,r,x,y);
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    for (int i=1; i<=q; i++){
        int l,r;
        cin >> l >> r;
        query.push({{l,r},i});
    }
    s.push({n+1,LLINF});
    for (int i=n; i>0; i--){
        int l = i, r = i;
        int val = a[i];
        while (s.top().se < val){
            s.pop();
            r = s.top().fi-1;
        }
        s.push({i,val});
        Update(1,1,n,l,r,val);
//        cout << endl;
        while (!query.empty() && query.top().fi.fi == i){
            int l = query.top().fi.fi;
            int r = query.top().fi.se;
            int idx = query.top().se;

            query.pop();

            ans[idx] = Get(1,1,n,l,r) - pre[r] + pre[l-1];
        }
    }
    for (int i=1; i<=q; i++){
        cout << ans[i] << endl;
    }
//    for (int i=1; i<=n; i++){
//        cout << Get(1,1,n,i,i) << " ";
//    }
//    cout << endl;
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
