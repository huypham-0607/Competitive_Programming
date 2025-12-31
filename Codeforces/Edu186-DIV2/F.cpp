/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
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

const int N = 3e5+10;
const int INF = 1e9+7;
const int LG = 61;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

namespace Comb {
    using ll = long long;

    const int MD = 998244353;
    const int N = 6e5;
    const int LG = 30;

    int invFac[N+1];
    int fac[N+1];
    int pow2[N+1];

    int binPow(int a, int b){
        ll res = 1;
        for (int lg = LG-1; lg>=0; lg--){
            res = res*res%MD;
            if ((1LL<<lg)&b) res = res*a%MD;
        }
        return res;
    }

    int binPow2(int b) {
        return pow2[b];
    }

    int invMod(int x, int MD){
        return binPow(x,MD-2);
    }

    int nCk(int n, int k){
        if (k > n) return 0;
        return 1LL*fac[n]*invFac[k]%MD*invFac[n-k]%MD;
    }

    int nCkBrute(int n, int k) {
        // if (n == 3e5) return 0;
        ll res = 0;
        for (int i=0; i<=k; i++){
            res = (1LL*res+nCk(n,i))%MD; 
        }
        res = (1LL*binPow2(n)-res+MD)%MD;
        return res;
    }

    struct Init {
        Init() {
            fac[0] = 1;
            invFac[0] = 1;
            pow2[0] = 1;
            for (int i = 1; i <= N; i++){
                fac[i] = (1LL*fac[i-1]*i%MD);
                invFac[i] = invMod(fac[i],MD);
                pow2[i] = 1LL*pow2[i-1]*2%MD;
            }
        }
    } _init;
}


int n,m;
int val[N];
int pre[N];

int Calc(ll x) {
    // cout << x << endl;
    ll ans = 0;
    ll cur = 1;
    int cnt = 0;
    int lg = LG-1;
    for (int tmp = LG-1; tmp>=0; tmp--){
        if (x&(1LL<<tmp)) {
            ++cnt;
            continue;
        }
        else {
            int rem = (lg==0)? 0 : pre[lg-1];
            ans = (ans+cur*Comb::nCkBrute(val[lg],cnt)%MD*Comb::binPow2(rem)%MD)%MD;
            cur = cur*Comb::nCk(val[lg],cnt)%MD;
            // cout << tmp << " " << lg << " " << ans << " " << cur << " " << rem <<  endl;            
            --lg;
            cnt = 0;
        }
    }

    if (cnt) {
        int rem = (lg==0)? 0 : pre[lg-1];
        ans = (ans+cur*Comb::nCkBrute(val[lg],cnt)%MD*Comb::binPow2(rem)%MD)%MD;
        cur = cur*Comb::nCk(val[lg],cnt)%MD;
        // cout << -1 << " " << lg << " " << ans << " " << cur << " " << rem << endl;        
        --lg;
    }

    ans = (ans+cur*Comb::binPow2(pre[lg])%MD)%MD;
    return ans;
}

void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        val[x]++;
    }

    pre[0] = val[0];
    for (int i=1; i<LG; i++){
        pre[i] = pre[i-1]+val[i];
    }

    while (m--) {
        int id; ll x; cin >> id >> x;
        if (id == 1) {
            val[x]++;
            pre[0] = val[0];
            for (int i=1; i<LG; i++){
                pre[i] = pre[i-1]+val[i];
            }
        }
        if (id == 2){
            val[x]--;
            pre[0] = val[0];
            for (int i=1; i<LG; i++){
                pre[i] = pre[i-1]+val[i];
            }
        }
        if (id == 3) {
            ll res = Calc(x);
            cout << res << endl;
            // cout << endl;
        }
    }
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

