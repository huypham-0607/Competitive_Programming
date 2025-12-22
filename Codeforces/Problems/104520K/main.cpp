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
const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 998244353;
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
int n;
ll fac[N];

int bin_pow(int a, int b){
    ll res = 1;
    for (int lg = LG-1; lg>=0; lg--){
        res = (res*res)%MD;
        if ((1<<lg)&b) res = (res*a)%MD;
    }
    return res;
}

int inv_mod(int x){
    return bin_pow(x,MD-2);
}

int Choose(int n, int k){
    return (ll)fac[n]*inv_mod(fac[k])%MD*inv_mod(fac[n-k])%MD;
}

/*Solution*/
void solve(){
    cin >> n;
    cout << 0 << " ";
    for (int i=2; i<=n; i++){
        if (i*2-1>n) cout << 0 << " ";
        else{
            ll cnt = 1;
            cnt = cnt*(Choose(n-i-1,i-2))%MD;
            cnt = cnt*fac[(i-1)*2]%MD*fac[n-(i-1)*2]%MD;
            cnt = cnt*(n-(i-1)*2+1)%MD;
            cout << cnt << " ";
        }

    }
    cout << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0] = 1;
    for (int i=1; i<N; i++){
        fac[i] = fac[i-1]*i%MD;
    }

    TestCases(1);

    return 0;
}
