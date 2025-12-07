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
const int LG = 30;
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
int n,k;
int dp[5];

int bin_pow(int a, int b){
    int ans = 1;
    for (int lg=LG-1; lg>=0; lg--){
        ans = ans*ans;
        if (((int)1<<lg)&b){
            ans = ans*a;
        }
    }
    return ans;
}

int Choose(int n, int k){
    if (n-k<k) k = n-k;
    int ans = 1;
    for (int i=1; i<=k; i++){
        ans = ans*(n-i+1)/i;
    }
    return ans;
}

/*Solution*/
void solve(){
    cin >> n >> k;
    dp[0] = 1;
    for (int i=2; i<=k; i++){
        dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
    }
    int ans = 0;
    for (int i=0; i<=k; i++){
        ans+=Choose(n,i)*dp[i];
//        cout << Choose(n,i)*dp[i] << " " << Choose(n,i) << endl;
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
