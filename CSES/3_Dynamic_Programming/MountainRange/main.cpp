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
int a[N];
vector<pii> v;
int ST[4*N];
int lb[N],rb[N];

void Update(int idx, int l, int r, int x, int val){
    if (r < x || x < l) return;
    if (l==r){
        ST[idx] = val;
        return;
    }

    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,val);
    Update(idx*2+1,mid+1,r,x,val);
    ST[idx] = max(ST[idx*2],ST[idx*2+1]);
}

int Query(int idx, int l, int r, int x, int y){
    if (r < x || y < l) return 0;
    if (x <= l && r <= y) return ST[idx];

    int mid = (l+r)/2;
    return max(Query(idx*2,l,mid,x,y),Query(idx*2+1,mid+1,r,x,y));
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        v.push_back({a[i],i});
    }

    a[0] = a[n+1] = INF;

    sort(all(v));

    deque<pii> dq;
    for (int i=1; i<=n+1; i++){
        while (!dq.empty() && dq.back().fi<=a[i]){
            rb[dq.back().se] = i-1;
            dq.pop_back();
        }
        dq.push_back({a[i],i});
    }

    while (!dq.empty()) dq.pop_back();

    for (int i=n; i>=0; i--){
        while (!dq.empty() && dq.back().fi<=a[i]){
            lb[dq.back().se] = i+1;
            dq.pop_back();
        }
        dq.push_back({a[i],i});
    }

    int ans = 0;

//    for (int i=1; i<=n; i++){
//        cout << lb[i] << " " << rb[i] << endl;
//    }

    for (auto in:v){
        int i = in.se;

        int x = Query(1,1,n,lb[i],rb[i]);
        ans = max(ans,x+1);
        Update(1,1,n,i,x+1);
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
