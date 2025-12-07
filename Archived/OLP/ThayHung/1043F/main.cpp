#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 3e5+10;
const int INF = 1e9+7;
const int MOD = 1e9+7;

int test;
int n;

int dp[maxn][10];
int fact[maxn];
int divisible[maxn];
set<int> st;

int pow(int base, int exp) {
	base %= MOD;
	int res = 1;
	while (exp > 0) {
		if (exp % 2 == 1){
            res = res * base % MOD;
        }
		base = base * base % MOD;
		exp /= 2;
	}
	return res;
}

int mod_inv(int n){
    return pow(n, MOD - 2);
}

int Comb(int n, int k){
    if (n<k) return 0LL;
    return fact[n]*mod_inv(fact[k]*fact[n-k]%MOD)%MOD;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fact[0] = 1;
    for (int i=1; i<=n; i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }

    int x;
    for (int i=1; i<=n; i++){
        cin >> x;
        st.insert(x);
    }

    int mx = *max_element(st.begin(),st.end());
    for (int i=1; i<=mx; i++){
        for (int j=i; j<=mx; j+=i){
            divisible[i] += st.count(j);
        }
    }

    for (int idx=1; idx<=7; idx++){
        for (int i=mx; i>=1; i--){
            int val = Comb(divisible[i],idx);
            for (int j=i*2; j<=mx; j+=i){
                val = (val-dp[j][idx]+MOD)%MOD;
            }
            dp[i][idx] = val;
//            if (idx == 2) cout << dp[i][idx] << " " << divisible[i] << endl;
        }
//        cout << endl;
        if (dp[1][idx] > 0){
            cout << idx << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
