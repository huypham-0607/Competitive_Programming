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
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;

namespace Comb {
    using ll = long long;

    const int MD = 1e9+7;
    const int N = 1e6;
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
        if (k < 0) return 0;
        if (k > n) return 0;
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

int a[N];

void solve(){
    cin >> n;
    vector<int> nen;
    ffor (i,1,n) {
        cin >> a[i];
        nen.push_back(a[i]);
    }
    sort(all(nen)); nen.resize(unique(all(nen))-nen.begin());

    int unique_choice = n+1;
    for (auto x:nen) {
        unique_choice = min(unique_choice,x);
    }
    int unique_placed = 0;
    int prev = 0;
    a[0] = n;
    int ans = 1;
    ffor(i,1,n){
        if (a[i] != a[i-1]) {
            int unique_forced = a[i-1]-(a[i]+1);
            int unique_needed = i - prev - 1;

            // cout << i << " " << unique_forced << " " << unique_needed  << endl;
            
            if (unique_forced < 0) {
                ans = 0;
            }
            else {
                ans = ans*Comb::nCk(unique_needed+unique_placed,unique_forced)%MD*Comb::fac[unique_forced]%MD;
            }
            unique_placed += unique_needed-unique_forced;
            ans = ans * (unique_placed + n-a[i])%MD;
            prev = i;
        }
    }

    if (prev != n) {
        unique_placed += n-prev;
    }

    // cout << unique_choice << " " <<  unique_placed << endl;
    if (unique_placed >= 0) {
        ans = ans * Comb::nCk(unique_choice, unique_placed) % MD * Comb::fac[unique_placed]%MD;
    }
    else {
        ans = 0;
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

