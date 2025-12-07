/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 102;
const int M = 1004;
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
int n,m = 0;
int a[N];

int Calc(int x){
    int h[N];
    for (int i=1; i<=n; i++){
        h[i] = a[i]-x;
    }
    int maxh = m-x;
//    h[0] = maxh;
    int dp[M];
    int pref[M];
    pref[0] = 1;
    for (int i=1; i<=maxh; i++){
        pref[i] = 1;
    }
    for (int idx=1; idx<=n; idx++){
        for (int i=0; i<=maxh; i++){
            if (i<=h[idx]) dp[i] = pref[h[idx] - i];
            else dp[i] = 0;
        }
        pref[0] = dp[0];
        for (int i=1; i<=maxh; i++){
            pref[i] = (pref[i-1] + dp[i])%INF;
        }
//        for (int i=0; i<=maxh; i++){
//            cout << dp[i] << " ";
//        }
//        cout << endl;
//        for (int i=0; i<=maxh; i++){
//            cout << pref[i] << " ";
//        }
//        cout << endl << endl;
    }
    return dp[0];
}

/*Solution*/
void solve(){
    cin >> n;
    int rawr = INF;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        m = max(m,a[i]);
        rawr = min(rawr,a[i]);
    }
    if (n%2){
        int ans = 0;
        for (int i=0; i<=rawr; i++){
            ans = (ans+Calc(i))%INF;
        }
        cout << ans << endl;
    }
    else {
        cout << Calc(0) << endl;
    }
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
