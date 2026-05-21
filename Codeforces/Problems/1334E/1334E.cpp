/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int NP = 31622776;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int D,q;

const int MXP = 31622776;

vector<int> primes;

void Sieve(){
    bitset<MXP+1> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i*i<=MXP; i++){
        if (!bs[i]) continue;
        for (int j=i*i; j<=MXP; j+=i){
            bs[j]=0;
        }
    }

    for (int i=1; i<=MXP; i++){
        if (bs[i]) primes.push_back(i);
    }
}

namespace Comb {
    using ll = long long;

    const int MD = 998244353;
    const int N = 2e5;
    const int LG = 30;

    int invFac[N+1];
    int fac[N+1];

    int binPow(int a, int b){
        ll res = 1;
        for (int lg = LG-1; lg>=0; lg--){
            res = res*res%MD;
            if ((1LL<<lg)&b) res = res*a%MD;
        }
        return res;
    }

    int invMod(int x, int MD){
        return binPow(x,MD-2);
    }

    int nCk(int n, int k){
        return 1LL*fac[n]*invFac[k]%MD*invFac[n-k]%MD;
    }

    struct Init {
        Init() {
            fac[0] = 1;
            invFac[0] = 1;
            for (int i = 1; i <= N; i++){
                fac[i] = (1LL*fac[i-1]*i%MD);
                invFac[i] = invMod(fac[i],MD);
            }
        }
    } _init;
}


vector<int> fact;

void solve(){
    cin >> D;
    int x = D;
    for (auto p:primes){
        if (x%p == 0) {
            fact.push_back(p);
            while (x%p == 0) x/=p;
        }
    }
    if (x!=1) fact.push_back(x);

    // for (auto p:fact) {
    //     cout << p << " ";
    // }
    // cout << endl;

    cin >> q;
    for (int i=1; i<=q; i++){
        int u,v; cin >> u >> v;
        int gcd = __gcd<ll>(u,v);
        int delta1 = (u/gcd);
        int delta2 = (v/gcd);
        // cout << gcd << " " << delta1 << " " << delta2 << endl;

        int res = 1;

        int x = delta1;
        int sum = 0;
        for (auto p:fact) {
            if (x%p == 0) {
                int t = 0;
                while (x%p == 0) {
                    x/=p;
                    ++t;
                }
                sum += t;
            }
        }
        x = delta1;
        for (auto p:fact) {
            if (x%p == 0) {
                int t = 0;
                while (x%p == 0) {
                    x/=p;
                    ++t;
                }
                res = (res*Comb::nCk(sum,t))%MD;
                sum-=t;
            }
        }


        x = delta2;
        sum = 0;
        for (auto p:fact) {
            if (x%p == 0) {
                int t = 0;
                while (x%p == 0) {
                    x/=p;
                    ++t;
                }
                sum += t;
            }
        }
        x = delta2;
        for (auto p:fact) {
            if (x%p == 0) {
                int t = 0;
                while (x%p == 0) {
                    x/=p;
                    ++t;
                }
                res = (res*Comb::nCk(sum,t))%MD;
                sum-=t;
            }
        }
        cout << res << endl;
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    Sieve();

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

