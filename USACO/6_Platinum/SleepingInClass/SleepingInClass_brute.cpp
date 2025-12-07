#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define a first
#define b second
#define pb push_back
#define hset unordered_set
#define hmap unordered_map
#define vm vector<mi>
#define vmm vector<vector<mi>>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using ld = long double;
int uMin(int& a, int b){return a = min(a,b);}
int uMax(int& a, int b){return a = max(a,b);}
typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}
bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}
ull pollard(ull n) {
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	auto f = [&](ull x) { return modmul(x, x, n) + i; };
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(),r.begin(),r.end());
	return l;
}
int main() {
    freopen("SleepingInClass.inp","r",stdin);
    freopen("SleepingInClass.ans","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vl a(n);
    for(ll& i: a) cin >> i;
    partial_sum(a.begin(),a.end(),a.begin());
    ll sum = *a.rbegin();
    map<ll,int> cnt;
    for(ll i: a) cnt[__gcd(i,sum)]++;
    vector<ull> fac = factor(sum);
    map<ll,int> bet;
    for(ull i: fac) bet[i]++;
    vector<pair<ll,int>> f;
    for(auto& a: bet) f.push_back({ll(a.a),a.b});
    map<pair<ll,int>,int> dp;
    function<void(int,ll,vi&)> dfs;
    dfs = [&](int s, ll prod, vi& a){
        if(s == f.size()){
            dp[{prod,0}] = cnt[prod];
            int ind = 0;
            for(int i = 0; i<s; i++){
                ll x = 1;
                for(int j = 0; j<f[i].b; j++){
                    dp[{prod,ind+1}] = dp[{prod,ind}];
                    if(j>=a[i]){
                        x*=f[i].a;
                        dp[{prod,ind+1}]+=dp[{prod*x,ind}];
                    }
                    ind++;
                }
            }
            return;
        }
        for(int i = 0; i<f[s].b; i++) prod*=f[s].a;
        for(int i = f[s].b; i>=0; i--){
            a[s] = i;
            dfs(s+1,prod,a);
            prod/=f[s].a;
        }
    };
    vi curr(f.size());
    dfs(0,1LL,curr);
    int last = 0;
    for(auto& a: f) last+=a.b;
    int q; cin >> q; while(q--){
        ll t; cin >> t;
        if(sum%t) cout << "-1\n"; else
        cout << n-(dp[{t,last}]<<1)+sum/t << "\n";
    }
}
