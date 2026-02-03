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

const int N = 302;
const int INF = 1e9+7;
const int MD = 1e9+7;
const long long LLINF = 1e18+3;

int n;
int a[N];
int c[N];

const int MXP = 31622;

vector<int> primes;

void Sieve(){
    bitset<MXP+1> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i*i<=MXP; i++){
        if (!bs[i]) continue;
        for (int j=i*i; j<=MXP; j+=i){
            bs[j]=0;
        }
    }

    for (int i=1; i<=MXP; i++){
        if (bs[i]) primes.push_back(i);
    }
}

void decomp(int x, vector<int>& v) {
    v.clear();
    for (auto p:primes) {
        if (x%p==0) {
            v.push_back(p);
            while (x%p==0) x/=p;
        }
    }
    if (x!=1) v.push_back(x);
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n ;i++){
        cin >> c[i];
    }
    vector<int> p;
    vector<int> dp;
    int ans = INF;
    for (int i=1; i<=n; i++){
        decomp(a[i],p);
        int m = p.size();
        if (m==0) {
            ans = min(ans,c[i]);
            continue;
        }
        // cout << i << endl;
        // for (auto x:p) cout << x << " ";
        // cout << endl;
        dp.clear();
        dp.resize((1<<m),INF);
        for (int j=1; j<=n; j++) {
            if (j==i) continue;
            int maskval = 0;
            for (int lg=0; lg<m; lg++) {
                if (a[j]%p[lg]==0) maskval^=(1<<lg);
            }
            // cout << j << " " << maskval << endl;
            for (int mask=0; mask<(1<<m);mask++) {
                int nmask = (mask&maskval);
                int val = c[j]+dp[mask];
                dp[nmask] = min(dp[nmask],val);
            }
            dp[maskval] = min(dp[maskval],c[j]);
        }
        // for (int mask=0; mask<(1<<m); mask++){
        //     cout << dp[mask] << " ";
        // }
        // cout << endl;
        // cout << dp[0] << endl;
        ans = min(ans,dp[0]+c[i]);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    Sieve();
    int testCount = 1;
    // cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

