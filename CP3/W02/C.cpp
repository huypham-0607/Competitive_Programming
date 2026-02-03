#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int N = 2e5+10;
const int LG = 15;
const int INF = 1e9+7;
const int MD = 1e9+7;
const long long LLINF = 1e18+3;

int n,l,r,x;
int a[LG+1];

void solve(){
    cin >> n >> l >> r >> x;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for (int mask=1; mask<(1<<n); mask++){
        int mn = INF, mx = 0;
        int t = 0;
        for (int lg=0; lg<LG; lg++){
            if (mask&(1<<lg)) {
                mn = min(mn,a[lg]);
                mx = max(mx,a[lg]);
                t += a[lg];
            }
        }
        if (mx-mn>=x && l <= t && t <= r){
            ++ans;
        }
    }
    cout << ans << endl;

}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
    // cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

