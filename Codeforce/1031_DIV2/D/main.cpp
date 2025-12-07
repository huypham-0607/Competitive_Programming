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
int b[N];
pii lo[N];
int hi[N];

bool check(int x){
    int val = lo[x].fi;
    if (lo[x].fi < hi[x+1]){
        val = min(hi[x+1],lo[x].se);
    }

    for (int i=1; i<=n-x+1; i++){
        if (b[i]<val) return true;
    }
    return false;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=0; i<=n+1; i++){
        lo[i] = {INF,INF};
        hi[i] = 0;
    }
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }

    for (int i=1; i<=n; i++){
        lo[i] = lo[i-1];
        if (a[i] < lo[i].fi){
            lo[i].se = lo[i].fi;
            lo[i].fi = a[i];
        }
        else if (a[i] < lo[i].se){
            lo[i].se = a[i];
        }
    }

    for (int i=n; i>0; i--){
        hi[i] = hi[i+1];
        if (a[i] > hi[i]){
            hi[i] = a[i];
        }
    }

//    for (int i=1; i<=n; i++){
//        cout << lo[i].fi << " " << lo[i].se << " " << hi[i] << endl;
//    }

    int ans = 0;
    int l = 1, r = n;
    while (l<=r){
        int mid = (l+r)/2;
        if (check(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
