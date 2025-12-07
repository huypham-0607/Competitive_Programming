/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
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
int n,k,m;

bool Check(int x, int n, int k, int m){
    int g = 0;
    while (k>0 && g<n){
        int y = (n-g)/x;
        if (y<m){
            int cnt = (n-g-1)/m + 1;
            return (cnt<=k);
        }

        int cnt = (((n-g)%x))/y+1;
        cnt = min(cnt,k);
        g+=cnt*y;
        k-=cnt;

//        cout << y << " " << g << " " << cnt << " " << k << " " << x << endl;
    }
    return (g>=n);
}

/*Solution*/
void solve(){
    cin >> n >> k >> m;
    int ans = 0;
    int l = 1, r = (int)(1e12);
    while (l<=r){
        int mid = (l+r)/2;
//        cout << "mid = " << mid << endl;
        if (Check(mid,n,k,m)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("loan.in","r",stdin);
    freopen("loan.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
