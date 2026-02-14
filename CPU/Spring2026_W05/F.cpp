/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

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
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;

int lcnt = 0;
int rcnt = 0;

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
        if (k>n) return 0;
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


void BinarySearch (int x) {
    lcnt = 0;
    rcnt = 0;
    int l =0, r=n;
    while (l<r) {
        int mid = (l+r)/2;
        // cout << mid << endl;

        if (mid <= x) {
            if (mid!=x) ++lcnt;
            l = mid+1;
        }
        else {
            if (mid!=x) ++rcnt;
            r = mid;
        }
    }
}

void solve(){
    int x,pos;
    cin >> n >> x >> pos;
    BinarySearch(pos);

    // cout << lcnt << " " << rcnt << endl;
    int ans = Comb::nCk(x-1,lcnt)*Comb::fac[lcnt]%MD*Comb::nCk(n-x,rcnt)%MD*Comb::fac[rcnt]%MD*Comb::fac[n-lcnt-rcnt-1]%MD;
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

