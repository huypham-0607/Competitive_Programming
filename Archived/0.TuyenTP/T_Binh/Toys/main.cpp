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
const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int LG;
int n,sus;
int a[N];
int dp[(1<<20)+10];

int binpow(int a, int b){
    int res = 1;
    for (int lg=20-1; lg>=0; lg--){
        res = (res*res)%MD;
        if ((b>>lg)&1) res = (res*a)%MD;
    }
    return res;
}

int GetCom(int x){
    return (binpow(2,x)-1+MD)%MD;
}

/*Solution*/
void solve(){
    cin >> n;
    cin >> LG;
    for (int i=1; i<=n; i++){
        int k; cin >> k;
        for (int idx=1; idx<=k; idx++){
            int x; cin >> x;
            a[i]+=(1<<(x-1));
        }
        a[i] = ((1<<LG)-1)^a[i];
//        cout << a[i] << endl;
        dp[a[i]]++;
    }
    int ans = 0;

    for (int lg=0; lg<LG; lg++){
        for (int mask=0; mask<(1<<LG); mask++){
            if (!((mask>>lg)&1)) dp[mask] = (dp[mask] + dp[mask^(1<<lg)])%MD;
        }
    }
    for (int mask=0; mask<(1<<LG); mask++){
        int cnt = __builtin_popcount(mask);
        if (cnt%2==1){
            ans = (ans-GetCom(dp[mask])+MD)%MD;
        }
        else{
            ans = (ans+GetCom(dp[mask]))%MD;
        }
//        cout << mask << " " << ans << " " << cnt << endl;
    }
//    cout << GetCom(4) << endl;
//    for (int mask=0; mask<(1<<2); mask++){
//        cout << dp[mask] << " ";
//    }
//    cout << endl;
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
