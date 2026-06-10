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
const int LLG = 18;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

/*
    | Combinatorics |
    Desc: Library for BinPow, InvMod, and Binomial Coefficient
    Source: KawakiMeido
    State: Tested yay!
*/

namespace Comb {
    using ll = long long;

    const int MD = 1e18+3;
    const int N = 6e5;
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


int n,LG;
vector<string> s;
int cnt[N];
int lol[N];
int b1cnt[N];

void solve(){
    cin >> n;
    LG = 64-__builtin_clzll(n);

    s.clear();
    for (int lg=0; lg<=n; lg++){
        cnt[lg] = 0;
        b1cnt[lg] = 0;
        lol[lg] = 0;
    }

    for (int lg=0; lg<LG; lg++){
        string st; cin >> st;
        int b1 = 0;
        for (int i=0; i<n; i++){
            if (st[i] == '1') ++b1;
        }
        b1cnt[b1]++;
        lol[lg] = b1;
        s.push_back(st);
    }
    vector<int> p; frep(i,0,LG) p.push_back(i);
    sort(all(p),[&](int x, int y) {return lol[x] > lol[y];});
    // for (auto x:p) cout << x << " ";
    // cout << endl;
    for (int i=0; i<n; i++){
        int val = 0;
        for (int lg=0; lg<LG; lg++){
            int tmp = s[p[lg]][i]-'0';
            val += (tmp << lg);
        }
        // cout << val << " ";
        ++cnt[val];
    }
    // cout << endl;
    // ffor(i,1,n) {
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;
    for (int i=1; i<=n; i++){
        if (cnt[i] != 1) {
            cout << 0 << endl;
            return;
        }
    }
    int ans = 1;
    // ffor(i,1,n) {
    //     cout << b1cnt[i] << " ";
    // }
    // cout << endl;
    for (int i=0; i<=n; i++){
        ans *= Comb::fac[b1cnt[i]];
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

