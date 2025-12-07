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
const int N = 1e6;
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
int n;
ll fact[N+1],inv[N+1];

ll bin_pow(int a, int b){
    ll res = 1;
    for (int lg = LG-1; lg>=0; lg--){
        res = (res*res)%MD;
        if (((ll)1<<lg)&b) res = (res*a)%MD;
    }
    return res;
}

void Calc_fact(){
    fact[0] = 1;
    for (int i=1; i<=N; i++){
        fact[i] = (fact[i-1]*i)%MD;
    }
}

void Calc_inv() {
	inv[N] = bin_pow(fact[N], MD - 2);
	for (int i = N; i >= 1; i--) { inv[i - 1] = inv[i] * i % MD; }
}

/*Solution*/
void solve(){
    Calc_fact();
    Calc_inv();
    cin >> n;
    for (int i=1; i<=n; i++){
        int a,b; cin >> a >> b;
        ll res = ((fact[a]*inv[b])%MD*inv[a-b])%MD;
        cout << res << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
