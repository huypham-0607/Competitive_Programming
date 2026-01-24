/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "EmptyString"

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

const int N = 510;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

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
        if (n-k<0) return 0;
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
int ch[N];
int dp[N][N];

int getLength(int i, int j) {
    return (j-i+1)/2;
}

void solve(){
    string s; cin >> s;
    n = s.size();
    for (int i=1; i<=n; i++){
        ch[i] = s[i-1];
    }
    for (int i=1; i<=n; i++){
        dp[i][i-1] = 1;
    }
    for (int delta=1; delta<n; delta++){
        for (int i=1, j=i+delta; j<=n; i++,j++){
            for (int mid=1; mid<j; mid++){
                if (ch[i]!=ch[mid]) continue;
                int tmp = dp[i+1][mid-1]*dp[mid+1][j]%MD;
                tmp = tmp*Comb::nCk(getLength(i,mid)+getLength(mid+1,j),getLength(mid+1,j))%MD;
                dp[i][j] = (dp[i][j] + tmp)%MD;
            }
            // for (int mid=j; mid>i; mid--){
            //     if (ch[mid]!=ch[j]) continue;
            //     int tmp = dp[mid+1][j-1]*dp[i][mid-1]%MD;
            //     tmp = tmp*Comb::nCk(getLength(i,mid-1)+getLength(mid,j),getLength(mid,j))%MD;
            //     dp[i][j] = (dp[i][j] + tmp)%MD;
            // }
            if (ch[i] == ch[j]) dp[i][j] = (dp[i][j] + dp[i+1][j-1])%MD;
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[1][n] << endl;
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

