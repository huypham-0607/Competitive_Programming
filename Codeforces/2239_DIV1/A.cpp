/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = (a); i <= (b); ++i)
#define rfor(i, a, b) for(int i = (a); i >= (b); --i)
#define frep(i, a, b) for(int i = (a); i < (b); ++i)
#define rrep(i, a, b) for(int i = (a); i > (b); --i)
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

const int N = 1e6+10;
const int INF = 1e9+7;
const int LG = 30;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];
int cnt[LG+1];
int ans[LG+1][N];

void solve(){
    cin >> n;
    for (int lg=0; lg<LG;lg++) cnt[lg] = 0;

    ffor(i,1,n) {
        cin >> a[i];
        for(int lg=0; lg<LG;lg++) {
            if (a[i]&(1<<lg)) ++cnt[lg];
        }
    }

    if (n==1) {
        cout << 0 << endl;
        return;
    }

    int val0 = 0;

    int ans = 0;
    ffor (i,1,n) {
        int val = a[i];
        for (int lg=LG-1; lg>=0; lg--){
            if ((cnt[lg]-((a[i]&(1<<lg)?1:0)))%2) {
                // cout << "lg: " <<  i << " " << lg << endl;
                val -= (1<<lg);
            }
        }
        // cout << i << " " << val << endl;
        if (val < 0) continue;
        if (val==0) ++val0;
        else ++ ans;
    }
    cout << ans+((val0)?1:0) << endl;
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

