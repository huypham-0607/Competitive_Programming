/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];
int dp[N];

namespace Comb {
    using ll = long long;

    const int MD = 1e9+7;
    const int N = 1e6;
    const int LG = 30;

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
        return 1LL*fac[n]*invMod(fac[k],MD)%MD*invMod(fac[n-k],MD)%MD;
    }

    struct Init {
        Init() {
            fac[0] = 1;
            for (int i = 1; i <= N; i++){
                fac[i] = (int)(1LL*fac[i-1]*i%MD);
            }
        }
    } _init;
}


void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        a[i] = a[i]/2;
    }
    dp[1] = 1;
    for (int i=2; i<=n; i++){
        if (a[i]>a[i-1]){
            dp[i] = dp[i-1]*Comb::nCk(a[i]-1,a[i-1]-1)%MD;
        }
        else{
            dp[i] = dp[i-1]*Comb::nCk(a[i-1],a[i])%MD;
        }
    }
    cout << dp[n] << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
