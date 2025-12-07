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

/*Global Variables*/
int n;
int a[N],b[N];

bool check(int x){
    int tang=0,giam=0;
    int tmp = n/2+1;
    for (int i=-n/2; i<=n/2; i++){
        int idx = tmp+i;
        if (a[idx]>x+abs(i)) giam++;
        else tang++;
    }
    for (int i=-n/2; i<=n/2; i++){
        int idx = tmp+i;
        if (b[idx]>x+abs(i)) giam++;
        else tang++;
    }
//    if (giam>tang) cout << x << " " << 1 << " " << giam << " " << tang << endl;
//    else cout << x << " " << 0 << " " << giam << " " << tang << endl;
    if (giam>tang) return true;
    return false;
}

/*Solution*/
void solve(){
    int l=0,r=0;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        r = max(r,a[i]);
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
        r = max(r,b[i]);
    }
//    cout << l << " " << r << endl;
    int ans = 0;
    while (l<=r){
        int mid = (l+r)/2;
        if (check(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    int tmp = n/2+1;
    int res = 0;
    ++ans;
//    cout << ans << endl;
    for (int i=-n/2; i<=n/2; i++){
        int idx = tmp+i;
        res+=abs(a[idx]-(ans+abs(i)));
        res+=abs(b[idx]-(ans+abs(i)));
    }
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    freopen("XEPGACH.inp","r",stdin);
    freopen("XEPGACH.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
