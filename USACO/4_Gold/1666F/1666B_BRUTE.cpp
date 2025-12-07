#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;
const int MAXN = 5000;

// https://usaco.guide/gold/combo?lang=cpp
long long fac[MAXN + 1];
long long inv[MAXN + 1];

/** Computes x^y modulo p in O(log p) time. */
long long exp(long long x, long long y, long long p) {
	long long res = 1;
	x %= p;
	while (y != 0) {
		if (y % 2 == 1) {
			res *= x;
			res %= p;
		}
		x *= x;
		x %= p;
		y >>= 1;
	}
	return res;
}

/** Precomputes n! from 0 to MAXN. */
void factorial(long long p) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % p; }
}

/**
 * Precomputes all modular inverse factorials from 0 to MAXN
 * in O(n + log p) time
 */
void inverses(long long p) {
	inv[MAXN] = exp(fac[MAXN], p - 2, p);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
}

/** Computes nCr mod p */
long long choose(long long n, long long r, long long p) {
	return fac[n] * inv[r] % p * inv[n - r] % p;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &i : a) { cin >> i; }
	reverse(a.begin(), a.end());

	vector<pair<int, ll>> b;
	for (int i = 0; i < n; i++) {
		if (b.size() > 0 && b.back().first == a[i]) {
			b.back().second++;
		} else {
			b.push_back({a[i], 1ll});
		}
	}

	// i greatest are used, j are even spots, i - j are odd spots
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0ll));
	dp[0][0] = 1;
	ll size = 0;
	for (int i = 0; i < ((int)b.size()); i++) {
		for (ll j = 0; j <= size; j++) {
			ll positions = max(j - 1, 0ll) + (j == n / 2) - (size - j);
			// k in the even position and b[i].second - k in the odd
			for (ll k = 0; k <= 1; k++) {
				if (j + k > n / 2) { continue; }
				dp[size + b[i].second][j + k] +=
				    choose(positions, b[i].second - k, MOD) * dp[size][j] % MOD;
				dp[size + b[i].second][j + k] %= MOD;
			}
		}
		size += b[i].second;
	}

	cout << dp[n][n / 2] << endl;
}

int main() {
    freopen("1666B.inp","r",stdin);
    freopen("1666B.ans","w",stdout);
	factorial(MOD);
	inverses(MOD);
	int test_num=1;
	cin >> test_num;
	for (int t = 0; t < test_num; t++) { solve(); }
}
