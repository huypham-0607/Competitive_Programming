/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int LG = 30;
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
int n,m,k;
int a[N];
int fac[N];

int bin_pow(int a, int b){
    ll ans = 1;
    for (int lg=LG-1; lg>=0; lg--){
        ans = ans*ans%MD;
        if ((1<<lg)&b) ans = ans*a%MD;
    }
    return ans;
}

int inv_mod(int x){
    return bin_pow(x,MD-2);
}

int Choose(int n, int k){
    if (k>n) return 0;
    return (ll)fac[n]*inv_mod(fac[k])%MD*inv_mod(fac[n-k])%MD;
}

/*Solution*/
void solve(){
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int l = 1;
    ll ans = 0;
    for (int r=1; r<=n; r++){
        while (a[r] - a[l]>k) ++l;
        ans = (ans+Choose(r-l,m-1))%MD;
    }

    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0] = 1;
    for (int i=1; i<N; i++){
        fac[i] = (ll)fac[i-1]*i%MD;
    }
    TestCases(1);

    return 0;
}
