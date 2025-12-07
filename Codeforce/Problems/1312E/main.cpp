/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[502];
int distl[502][1502];
int distr[502][1502];
int mnval[502][502];
int dp[502][502];

void solve(){
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    for (int i=0; i<=n+1; i++) {
        for (int j=0; j<=1501; j++) {
            distl[i][j] = INF;
            distr[i][j] = -INF;
        }
    }

    for (int i = n; i > 0; i--) {
        distl[i][a[i]] = i;
        int val = a[i];
        int pos = i;
        while (pos+1 <= n) {
            distl[i][val+1] = distl[pos+1][val];
            pos = distl[i][val+1];
            ++val;
        }
    }

    for (int i = 1; i <= n; i++) {
        distr[i][a[i]] = i;
        int val = a[i];
        int pos = i;
        while (pos-1 > 0) {
            distr[i][val+1] = distr[pos-1][val];
            pos = distr[i][val+1];
            ++val;
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dp[i][j] = INF;
        }
    }

//    for (int i=0; i<=n; i++) {
//        dp[i+1][i] = 0;
//    }

    for (int delta = 0; delta < n; delta++) {
        for (int i = 1; i<=n; i++){
            int j = i+delta;
            if (j > n) break;

            dp[i][j] = min(dp[i][j], delta+1);

            if (i == j){
//                cout << i << " " << j << " " << dp[i][j] << endl;
                continue;
            }

            for (int di = 0; di <= 500; di++) {
                int vali = a[i] + di;

                int l = distl[i][vali]+1;

                if (l == j+1) {
                    dp[i][j] = min(dp[i][j],1LL);
                }
            }


            for (int mid = i; mid < j; mid++) {
                dp[i][j] = min(dp[i][j],dp[i][mid]+dp[mid+1][j]);
            }
//            cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    cout << dp[1][n] << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
