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
const int N = 3e5+10;
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
int n;
deque<pii> dq;
int h[N],a[N];

//SEGG
int ST[4*N];

void Update(int idx, int l, int r, int x, int val){
    if (x<l || r<x) return;
    if (l==r){
        ST[idx] = val;
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,val); Update(idx*2+1,mid+1,r,x,val);
    ST[idx] = max(ST[idx*2],ST[idx*2+1]);
}

int Get(int idx, int l, int r, int x, int y){
    if (y<l || r<x) return -LLINF;
    if (x<=l && r<=y){
        return ST[idx];
    }
    int mid = (l+r)/2;
    return max(Get(idx*2,l,mid,x,y),Get(idx*2+1,mid+1,r,x,y));
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> h[i];
    }
    int lst = 0;
    for (int i=1; i<=n; i++){
        while (!dq.empty() && dq.back().fi>a[i]) dq.pop_back();
        int pos = 0;
        if (!dq.empty()) pos = dq.back().se;
        int mx = -LLINF;
        mx = max(mx,Get(1,0,n,pos,i-1));
//        cout << i << " " << pos << " " << mx+h[i] << " " << lst << endl;
        mx+=h[i];
        lst = Get(1,0,n,pos,pos);
        if (pos!=0) mx = max(mx,lst);
        Update(1,0,n,i,mx);
        dq.push_back({a[i],i});
    }
//    Update(1,0,n,1,1);
//    cout << Get(1,0,n,1,2) << endl;
    int ans = Get(1,0,n,n,n);
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
