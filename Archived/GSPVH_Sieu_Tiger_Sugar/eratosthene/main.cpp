#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const ll cap = 3162277;
const ll lowcap = 1778;
const ll maxn = 5e6 + 100;

bitset<cap + 200> sieve;
vector<ll> prime;


void eratosthene(){
    sieve[0] = true;
    sieve[1] = true;
    for (ll i=2; i<=lowcap; i++){
        if (!sieve[i]){
            for (ll j=i*i; j<=cap; j+=i){
                sieve[j] = true;
            }
        }
    }
    for (ll i=2; i<=cap; i++){
        if (!sieve[i]){
            prime.push_back(i);
        }
    }
}

ll solve(ll l, ll r){
    //ll mx = r-l;
    //ll  c=0;
    int res =0;
    sieve.set();
    for (ll i : prime){
//        ll start = max ((l-1)/x)*x+x-l;
//        while (start <= mx){
//            if (!ans[start]) c++;
//            ans[start] = true;
//            start+=x;
//        }
        for (ll j = max(i * i,(l + i - 1) / i * i); j <= r; j+=i){
            if (sieve[j-l]) res ++;
            sieve[j - l] = 0;
        }
    }
    return res;
}

int main(){
    //freopen("eratosthene.INP","r",stdin);
    //freopen("eratosthene.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    eratosthene();
    ll l,r;
    cin >> l >> r;
    cout << solve(l,r);
    return 0;
}
