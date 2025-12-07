#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int main(){
    freopen("eratosthene.INP","r",stdin);
    freopen("eratosthene.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long L,R;
    cin >> L >> R;

    vector<bool> isPrime(R - L + 1, true);

    for (long long i = 2; i * i <= R; ++i) {
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
            isPrime[j - L] = false;
        }
    }

    if (1 >= L) {
        isPrime[1 - L] = false;
    }
    int res=0;
    for (long long x = L; x <= R; ++x) {
        if (isPrime[x - L]) {
            ++res;
        }
    }
    cout << res;
    return 0;
}
