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
const int N = 2e6;
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
int n,k;
int fac[N+10];

int bin_pow(int a, int b){
    int ans = 1;
    for (int lg=LG-1; lg>=0; lg--){
        ans = ans*ans%MD;
        if (((int)1<<lg)&b) ans = ans*a%MD;
    }
    return ans;
}

int inv_mod(int x){
    return bin_pow(x,MD-2);
}

/*Solution*/
void solve(){
    cin >> k >> n;
    fac[0] = 1;
    for (int i=1; i<=N; i++){
        fac[i] = fac[i-1]*i%MD;
    }
    cout << fac[n+k-1]*inv_mod(fac[k-1])%MD*inv_mod(fac[n])%MD;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
