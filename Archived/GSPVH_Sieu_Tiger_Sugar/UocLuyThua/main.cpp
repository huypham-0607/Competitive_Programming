#include <bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

const int N = 3000069;
const int NNN = 100069;
const ull inf = 1e19 + 69;

bitset<NNN> bs;
vector<ll> prime;
int cntdiv[N + 5];
map<ull,int> mp;

ull power(ll a,ll n){
    ull res = 1;
    for (int i = 1; i <= n; i++){
        if (inf / res < a) return inf;
        res *= a;
    }
    return res;
}

void sieve(int n){
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i * i <= n; i++){
        if (!bs[i]) continue;
        for (ll j = i * i; j <= n; j += i){
            bs[j] = 0;
        }
    }
    for (int i = 2; i <= n; i++){
        if (bs[i]){
            prime.push_back(i);
        }
    }
}

bool isprime(ull n){
    for (ll i : prime){
        if (i * i > n) break;
        if (n % i == 0) return 0;
    }
    return 1;
}

ull findsqrt(ull n){
    ll x = sqrt(n);
    for (int i = -2; i <= 2; i++){
        if (x + i >= 0 && 1ULL * (x + i) * (x + i) == n) return x + i;
    }
    return inf;
}

void run(int n){
    for (int i = 1; i * i <= n; i++){
        cntdiv[i * i]--;
        for (int j = i * i; j <= n; j += i) cntdiv[j] += 2;
    }
    for (int i = 1; i <= n; i++){
        ull res = power(i,cntdiv[i]);
        if (res < inf) mp[res] = i;
    }
}

void solve(){
    ull n;
    cin >> n;
    ll res = (mp.find(n) != mp.end() ? mp[n] : -1);
    if (res == -1){
        ull x = findsqrt(n);
        if (x == inf) res = -1;
        else res = (isprime(x) ? x : -1);
    }
    cout << res << " ";
}

int main(){
    //time_t a,b; a = clock();
    //freopen("divpow.INP","r",stdin);
    //freopen("divpow.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    sieve(NNN - 1);
    run(N - 1);
    while(t--) solve();
    //b = clock();
    //double T = (b - a) * 1.0 / CLOCKS_PER_SEC;
    //cout << setprecision(2) << fixed << " " << T << "\n";
    return 0;
}
