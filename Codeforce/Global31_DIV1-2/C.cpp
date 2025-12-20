/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "C"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
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

const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k;
int ans[N];

void solve(){
    cin >> k >> n;
    for (int i=1; i<=n; i++){
        if (i==n) {
            if (n%2) ans[i] = k;
            else {
                if (__builtin_popcountll(k) > 1) {
                    int lg = 63-__builtin_clzll(k);
                    int a=(1LL<<lg),b=0;
                    int lg2;
                    for (int i=0; i<lg; i++){
                        if (((1LL<<i)&k)) lg2 = i;
                    }
                    // cout << lg << " " << lg2 << endl;
                    b = (1LL<<lg2);
                    for (int i=0; i<lg2; i++){
                        if ((1LL<<i)&k) {
                            a^=(1LL<<i);
                        }
                        else {
                            a^=(1LL<<i);
                            b^=(1LL<<i);
                        }
                    }
                    ans[i-1] = a;
                    ans[i] = b;
                }
                else {
                    ans[i] = 0;
                }
            }
        }
        else {
            ans[i] = k;
        }
    }

    if (n%2==0 && min((int)__builtin_popcountll(k),n) > 1) {
        int x = k;
        x^=(1<<(63-__builtin_clzll(k)));
        int lim = min((int)__builtin_popcountll(k),n);
        for (int i=1; i<lim; i++){
            int lg = 63-__builtin_clzll(x);
            ans[i] = k^(1LL<<lg);
        }
        if (lim%2) {

        }
        else {
            
        }
    }

    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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

