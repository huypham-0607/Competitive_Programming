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

const int N = 3010;
const int INF = 1e9+7;
const int MD = 1e9+7;
const long long LLINF = 1e18+3;

int n;
int a[N];
int cnt[N][N][2];
int precnt[N][N][2];
int dp[N][N][2];
int pre[N][N][2];

int bin_search(int x, int pivot, int val) {
    int ans = 0;
    int r = x;
    int l = 1;

    while (l<=r) {
        int mid = (l+r)/2;
        int dist = pivot-a[mid];
        if (dist > val) {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    a[0] = -INF;
    int ans = 0;
    for (int i=1; i<=n; i++){
        cnt[i][0][1] = 1;
        dp[i][0][1] = 1;
        for (int j=i-1; j>0; j--) {
            // cout << i << " " << j << endl;
            int mid = bin_search(j-1,a[j],a[i]-a[j]);
            // cout << mid << endl;
            dp[i][j][0] = (dp[i][j][0] + dp[j][mid][1])%MD;
            dp[i][j][0] = (dp[i][j][0] + dp[j][j-1][0] - dp[j][mid][0] + MD)%MD;
            dp[i][j][1] = (dp[i][j][1] + dp[j][mid][1])%MD;
            dp[i][j][1] = ((dp[i][j][1] + dp[j][j-1][0] - dp[j][mid][0]+MD)%MD + (cnt[j][j-1][0] - cnt[j][mid][0]+MD)%MD)%MD;

            cnt[i][j][0] = (cnt[i][j][0] + cnt[j][mid][1])%MD;
            cnt[i][j][0] = (cnt[i][j][0] + cnt[j][j-1][0] - cnt[j][mid][0]+MD)%MD;
            cnt[i][j][1] = (cnt[i][j][1] + cnt[j][mid][1])%MD;
            cnt[i][j][1] = (cnt[i][j][1] + cnt[j][j-1][0] - cnt[j][mid][0]+MD)%MD;
        }

        for (int j=0; j<i; j++){
            dp[i][j][0] = (dp[i][j][0] + dp[i][j-1][0])%MD;
            dp[i][j][1] = (dp[i][j][1] + dp[i][j-1][1])%MD;
            cnt[i][j][0] = (cnt[i][j][0] + cnt[i][j-1][0])%MD;
            cnt[i][j][1] = (cnt[i][j][1] + cnt[i][j-1][1])%MD;
        }
        ans = (ans+dp[i][i-1][0])%MD;
    }

    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=n; j++){
    //         cout << dp[i][j][0] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=n; j++){
    //         cout << dp[i][j][1] << " ";
    //     }
    //     cout << endl;
    // }
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

