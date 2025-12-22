/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

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
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;

bool Check(int x, int l, int r){
//    cout << l << " " << r << endl;
    int lc = ((x&(1LL<<l))?1:0);
    int rc = ((x&(1LL<<r))?1:0);
    if (!(lc^rc)) return true;
    return false;
}

void solve(){
    int x; cin >> x;
    if (x == 0){
        cout << "YES" << endl;
        return;
    }

    int r = 64-__builtin_clzll(x);
    int l = 0;
    while (!(x&(1LL<<l))) ++l;

//    cout << l << " " << r << endl;
    for(int i=0; i<(r-l)/2; i++){
        if (!Check(x,i+l,r-i-1)){
            cout << "NO" << endl;
            return;
        }
    }
    if (((r-l)%2) && x&(1LL<<(r-(r-l)/2-1))){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;


}

/*Driver Code*/
signed main(){
//    cin.tie(0) -> sync_with_stdio(0);
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

