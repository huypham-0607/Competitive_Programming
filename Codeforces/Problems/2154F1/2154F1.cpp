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
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];

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
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
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


void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for (int mid=1; mid<n; mid++){
        int aux = 1;
        int l = 0;
        int r = mid;
        int space = 0;
        for (int i=1; i<=n; i++){
            // cerr << "i: " << i << endl;
            // cerr << a[i] << " " << l << " " << r << " " << space << endl;
            if (a[i] == -1) {
                ++space;
                continue;
            }
            if (a[i] <= mid) {
                if (a[i] < l) {
                    aux = 0;
                    break;
                }
                int delta = a[i]-l-1;
                if (delta < 0){
                    aux = 0;
                    break;
                }
                aux = (aux*Comb::nCk(space,delta))%MD;
                if (aux == 0) break;
                r += space-delta;
                space = 0;
                l = a[i];
            }
            else {
                if (a[i] < r) {
                    aux = 0;
                    break;
                }
                int delta = a[i]-r-1;
                if (delta < 0) {
                    aux = 0;
                    break;
                }
                aux = (aux*Comb::nCk(space,delta))%MD;
                if (aux == 0) break;
                l+=space-delta;
                space = 0;
                r = a[i];
            }
        }
        
        if (aux!=0) {
        // Add all remaining l
            int delta = mid-l;
            // cerr << delta << " " << space << endl;
            if (delta < 0) aux = 0;
            aux = (aux*Comb::nCk(space,delta))%MD;
            r += space-delta;
            space = 0;
        // Add all remaining r
            delta = n-r;
            // cerr << delta << " " << space << endl;
            if (delta < 0) aux = 0;
            aux = (aux*Comb::nCk(space,delta))%MD;
            l+=space-delta;
        }

        // cout << aux << " ";

        ans = (ans + aux)%MD;
    }
    // cout << endl;

    int flag = 1;
    for (int i=1; i<=n; i++){
        if (a[i] != -1 && a[i] != i) flag = 0;
    }
    if (flag) {
        ans = (ans-n+2+MD)%MD;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

