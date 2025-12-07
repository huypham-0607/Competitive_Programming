/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
//#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

using ll = long long;
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
//int n,k;

ll power(ll x, ll y, ll M)
{
        if (y == 0)
                return ll(1);

        ll p = power(x, y / ll(2), M) % M;
        p = (p * p) % M;

        return (y % ll(2) == 0) ? p : (x * p) % M;
}

void solve()
{
        ll N, K; cin >> N >> K;

        double ans = 0;
        for (int i = 1; i <= K; i++) {
                ans += (double)i*(pow(i, N)-pow(i-1, N))/pow(K, N);
        }
        cout << fixed << ans << '\n';
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
