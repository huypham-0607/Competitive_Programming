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
vector<int> key;
vector<int> val;

/*
    | Combinatorics |
    Desc: Library for BinPow, InvMod, and Binomial Coefficient
    Source: KawakiMeido
    State: Tested yay!
*/

namespace Comb {
    using ll = long long;

    const int MD = 1e9+7;
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


void solve(){
    key.clear();
    val.clear();
    cin >> n;
    int negative_cnt = 0;
    int prev = -1;
    ffor(i,1,n){
        int x; cin >> x;
        if (x == -1){
            ++negative_cnt;
        }
        else {
            if (x!=prev){
                key.push_back(x);
                val.push_back(0);
                prev = x;
            }
            ++val.back();
        }
    }

    int ans = (negative_cnt!=0)?Comb::binPow(2,negative_cnt-1):1;
    int ans2 = (negative_cnt!=0)?Comb::binPow(2,negative_cnt-1):1;
    // cout << negative_cnt << " " << ans << endl;
    frep(i,0,key.size()){
        int tmp = (ans*Comb::binPow(2,val[i]-1))%MD;
        if (negative_cnt!=0 && i!=0 && key[i-1]+1 == key[i]){
            tmp = (tmp + ans2*Comb::binPow(2,val[i-1]-1)%MD*Comb::binPow(2,val[i]-1)%MD)%MD;
        }
        if (negative_cnt!=0 && i!=0){
            ans2 = ans2*Comb::binPow(2,val[i-1]-1)%MD;
        }
        ans = tmp;
        // cout << i << " " << key[i] << " " << val[i] << " " << ans << endl;
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

