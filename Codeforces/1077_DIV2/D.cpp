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
const int LG = 31;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int p,q;

int convert(int mask, int val) {
    for (int lg=0; lg<LG; lg++){
        int masklvl = ((1LL<<LG)-1)-((1LL<<lg)-1);
        if (mask&(1LL<<lg)) {
            val = val + (val&masklvl);
        }
    }
    return val;
}

int bin_search(int mask, int val){
    int lg2 = LG-__builtin_popcountll(mask);
    int conv = 0;
    int ans = 0;
    int l = 1;
    int r = (1LL<<lg2);
    while (l<=r) {
        int mid = (l+r)/2;
        // cout << "mid: " << mid << endl;
        int x = convert(mask,mid-1);
        int y = convert(mask,mid);
        // cout << x << " " << y << endl;
        int u = abs(x-val);
        int v = abs(y-val);
        if (v < u) {
            ans = mid;
            conv = y;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    return conv;
}

void solve(){
    cin >> p >> q;
    int pcomp = bin_search(q,p);
    int qcomp = bin_search(p,q);
    // cout << pcomp << " " << qcomp << endl;
    // cout << "p:" << endl;
    int pval = abs(p-pcomp);
    // cout << "q:" << endl;
    int qval = abs(q-qcomp);
    // cout << pval << endl;
    // cout << qval << endl;
    if (pval < qval) {
        cout << pcomp << " " << q << endl;
    }
    else {
        cout << p << " " << qcomp << endl;
    }    
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

