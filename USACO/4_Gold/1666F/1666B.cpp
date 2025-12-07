/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "1666B"

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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

namespace Comb {
    using ll = long long;

    const int MD = 998244353;
    const int N = 2e5;
    const int LG = 30;

    int fac[N+1],inv_fac[N+1];

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
        return 1LL*fac[n]*inv_fac[k]%MD*inv_fac[n-k]%MD;
    }

    int nPk(int n, int k){
        return 1LL*fac[n]*invMod(fac[n-k],MD)%MD;
    }

    struct Init {
        Init() {
            fac[0] = 1;
            inv_fac[0] = invMod(fac[0],MD);
            for (int i = 1; i <= N; i++){
                fac[i] = (int)(1LL*fac[i-1]*i%MD);
                inv_fac[i] = (int)invMod(fac[i],MD);
            }
//            for (int i=1; i<=10; i++){
//                cout << fac[i] << " " << inv_fac[i] << endl;
//            }
        }
    } _init;
}


int n;
int dp[5010];
int dpPrev[5010];

void solve(){
    int mx=0,mn=INF;
    int m;
    cin >> n;
    vector<int> nen;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++){
        cin >> a[i];
        nen.push_back(a[i]);
    }
    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());

    m = nen.size();
    vector<int> cnt(m+1,0);
    for (int i=1; i<=n; i++){
        a[i] = lower_bound(all(nen),a[i]) - nen.begin()+1;
        cnt[a[i]]++;
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
    }

    if (cnt[mx] > 1){
        cout << 0 << endl;
        return;
    }
//    cout << mx << " " << mn << endl;
    cnt[mx]--;
//    cnt[mn]--;

    for (int i=0; i<=n/2-1; i++){
        dp[i] = dpPrev[i] = 0;
    }
    dp[0] = 1;

//    for (int i=1; i<=m; i++){
//        cout << cnt[i] << endl;
//    }

    int tcnt = 0;
    for (int i=m; i>0; i--){
        if (!cnt[i]) continue;
        swap(dp,dpPrev);
        for (int j=0; j<=n/2-1; j++){
            dp[j] = 0;
        }
//        cout << i << endl;
        for (int j=0; j<=n/2-1; j++){
            int a = j + ((j==n/2-1)?1:0) - (tcnt - j);
            int b = cnt[i];
//            cout << a << " " << b << endl;
            if (a >= 0 && a >= b){
                dp[j] = (dp[j] + dpPrev[j]*Comb::nCk(a,b)%MD)%MD;
            }
            a = j-1 + (((j-1)==n/2-1)?1:0) - (tcnt - (j-1));
            b = cnt[i] - 1;
//            cout << a << " " << b << endl;
            if (!(i==mn) && a >= 0 && a >= b){
                dp[j] = (dp[j] + dpPrev[j-1]%MD*Comb::nCk(a,b)%MD)%MD;
            }
        }
        tcnt += cnt[i];
//        for (int idx=0; idx<=n/2-1; idx++){
//            cout << dpPrev[idx] << " ";
//        }
//        cout << endl;
//        for (int idx=0; idx<=n/2-1; idx++){
//            cout << dp[idx] << " ";
//        }
//        cout << endl << endl;
    }
    cout << dp[n/2-1] << endl;
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
