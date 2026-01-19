/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "D2"

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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

namespace Comb {
    using ll = long long;

    const int MD = 998244353;
    const int N = 200;
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
        if (n-k < 0) return 0;
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

int n;

void solve(){
    cin >> n;
    string s; cin >> s;
    s = "#" + s + ")";
    vector<vector<int>> precalc(n+10,vector<int>(n+10,0));
    vector<int> ocnt(n+10,0),ccnt(n+10,0);
    for (int i=1; i<=n; i++){
        ocnt[i] = ocnt[i-1];
        if (s[i] == '(') ++ocnt[i];
    }
    for (int i=n; i>0; i--){
        ccnt[i] = ccnt[i+1];
        if (s[i] == ')') ++ccnt[i];
    }

    precalc[0][n+1] = 1;
    int ans = 0;

    for (int i=n; i>0; i--){
        if (s[i] == '(') {
            for (int idx=n; idx>=1; idx--){
                for (int last = n+1; last>i; last--){
                    if (s[last] != ')') continue;
                    for (int lastn = last-1; lastn>i; lastn--){
                        if (s[lastn] != ')') continue;
                        int val = precalc[idx-1][last];
                        precalc[idx][lastn] = (precalc[idx][lastn] + val)%MD;
                        precalc[idx][0] = (precalc[idx][0] + val)%MD;
                    }
                }
            }
        }
        if (s[i] == ')') {
            for (int t = 3; t<=ccnt[i]; t++){
                for (int idx=1; idx<=t-2; idx++){
                    for (int last = n; last>i; last--){
                        if (s[last] != ')') continue;
                        int a1 = Comb::nCk(ocnt[i],idx);
                        int a2 = Comb::nCk(ccnt[i+1] - ccnt[last],idx-1);
                        int a3 = precalc[t-idx][last];
                        int a4 = 2*(t-1);
                        ans = (ans + a1*a2%MD*a3%MD*a4%MD)%MD;
                    }
                }
            }
        }
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

