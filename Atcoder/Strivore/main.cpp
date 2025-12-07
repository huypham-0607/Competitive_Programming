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
const int N = 2e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7;
const int LG = 30;
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
int fac[N];
string s;

int bin_pow(int a, int b){
    ll res = 1;
    for (int lg=LG-1; lg>=0; lg--){
        res = res*res%MD;
        if ((1<<lg)&b) res = res*a%MD;
    }
    return res;
}

int inv_mod(int x){
    return bin_pow(x,MD-2);
}

int Comb(int n, int k){
    return 1LL*fac[n]*inv_mod(fac[k])%MD*inv_mod(fac[n-k])%MD;
}

/*Solution*/
void solve(){
    cin >> k;
    cin >> s;
    n = s.size();
//    cout << n << endl;
    ll ans = 0;
    for (int i=0; i<=k; i++){
        ll cnt = 1LL*Comb(k-i+n-1,n-1)*bin_pow(25,k-i)%MD;
        cnt = cnt*bin_pow(26,i)%MD;
        ans = (ans+cnt)%MD;
    }
    cout << ans << endl;
//    for (int i=1; i<=10; i++){
//        cout << fac[i] << endl;
//    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0] = 1;
    for (int i=1; i<N; i++){
        fac[i] = 1LL*fac[i-1]*i%MD;
    }
    TestCases(0);

    return 0;
}
