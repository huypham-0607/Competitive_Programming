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

int n,k;
int mex[N];
int marked[N];

void solve(){
    cin >> n >> k;
    int max_bit = 64-__builtin_clzll(n);
    int l = (__builtin_popcount(n)==1)?(1<<(max_bit-1)):0;
    int r = (1<<max_bit)-1;

    // cout << l << " " << r << " " << max_bit << endl;
    if (k<l || r<k){
        cout << "NO" << endl;
        return;
    }

    ffor(i,0,n){
        mex[i] = -1;
        marked[i] = 0;
    }

    int pos = n+1;
    for (int lg=max_bit-1; lg>=0; lg--){
        if ((1<<lg)&(k^n)){
            --pos;
            mex[pos] = (1<<lg);
            marked[(1<<lg)] = 1;
        }
    }
    --pos; mex[pos] = 0; marked[0] = 1;
    int idx = 0;
    ffor(i,1,n){
        if (mex[i] != -1) continue;
        while (marked[idx])++idx;
        mex[i] = idx;
        marked[idx] = 1;
    }
    cout << "YES" << endl;
    ffor(i,1,n) {
        cout << mex[i] << " ";
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

