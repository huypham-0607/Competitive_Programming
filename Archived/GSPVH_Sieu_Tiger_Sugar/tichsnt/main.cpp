#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 1e7 + 35;

bitset<N> bs;
vector<ll> prime;

void sieve(int n){
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i * i <= n; i++){
        if (!bs[i]) continue;
        for (int j = i * i; j <= n; j += i) bs[j] = 0;
    }
    for (int i = 2; i <= n; i++){
        if (bs[i]) prime.push_back(i);
    }
}

bool isprime(ll& n){
    for (int i = 0; i < prime.size(); i++){
        ll f = prime[i];
        if (f * f > n) break;
        if (n % f == 0) return 0;
    }
    return n > 1;
}

bool solve(){
    ll n,k;
    cin >> n >> k;
    if (k > 12) return 0;
    if (k == 1) return isprime(n);
    ll cur = 1;
    for (int i = 0; i < k - 1; i++){
        cur *= prime[i];
    }
    if (cur > n) return 0;
    for (int i = k - 1; i < prime.size(); i++){
        cur *= prime[i];
        if (cur > n) return 0;
        if (cur == n) return 1;
        cur /= prime[i - k + 1];
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("tichsnt.inp","r",stdin);
    freopen("tichsnt.out","w",stdout);
    sieve(N - 5);
    int t;
    cin >> t;
    while(t--){
        if (solve()) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
    return 0;
}
