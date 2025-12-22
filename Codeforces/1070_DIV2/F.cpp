/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define TEXT "F"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
//#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int MXK = 6;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,lmeo;
int a[N];
int cnt[MXK+1][N];
int omega[N];
ll dp[2*MXK+2][N];

const int MXP = 448;

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

int calcOmega(int val) {
    int res = 0;
    for (auto x:primes) {
        if (val%x!=0) continue;
        ++res;
        while (val%x == 0) val = val/x;
    }
    if (val!=1) ++res;
    return res;
}

void solve(){
    cin >> n >> lmeo;
    for (int i=1; i<=n; i++){
        omega[i] = calcOmega(i); 
    }
 
    for (int k=0; k<=MXK; k++){
        for (int i=1; i<=n; i++) {
            cnt[k][i] = 0;
        }
    }
 
    for (int i=1; i<=n; i++){
        cin >> a[i];
        int k = calcOmega(a[i]);
        cnt[k][a[i]]++;
    }
    
    for (int k=0; k<=MXK; k++){
        for (int i=1; i<=n; i++) {
            for (int j=i*2; j<=n; j+=i) {
                cnt[k][i] += cnt[k][j];
            }
            // cout << cnt[k][i] << " ";
        }
        // cout << endl;
    }
    // cout << endl;
 
    ll ans = 0;
 
    for (int k=0; k<=2*MXK; k++){
        for (int gcd = n; gcd>0; gcd--) {
            dp[k][gcd] = 0;
            for (int i=0; i<=min(k,MXK); i++) {
                int j=k-i;
                if (j > MXK) continue;
                if (j < i) break;
                // cout << k << " " << gcd << " " << i << " " << j << endl;
                if (i == j) {
                    dp[k][gcd] = (1LL*dp[k][gcd]+Comb::nCk(cnt[i][gcd],2))%MD;
                    // cout << cnt[i][gcd] << " " << Comb::nCk(cnt[i][gcd],2) << endl;
                }
                else {
                    dp[k][gcd] = (1LL*dp[k][gcd] + 1LL*cnt[i][gcd]*cnt[j][gcd]%MD)%MD;
                }
            }
            for (int x=2*gcd; x<=n; x+=gcd) {
                dp[k][gcd] = (1LL*dp[k][gcd]-dp[k][x]+MD)%MD;
            }
            ans = (1LL*ans+1LL*dp[k][gcd]*Comb::binPow(k-omega[gcd],lmeo)%MD)%MD;
            // cout << ans << endl;
        }
    }
 
    // cout << endl;
 
    // for (int k=0; k<=2*MXK; k++){
    //     for (int gcd = 1; gcd<=n; gcd++){
    //         cout << dp[k][gcd] << " ";
    //     }
    //     cout << endl;
    // }
 
    cout << ans << endl;
}
 
/*Driver Code*/
signed main(){
    // cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }
 
    Sieve();
    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }
 
    return 0;
}