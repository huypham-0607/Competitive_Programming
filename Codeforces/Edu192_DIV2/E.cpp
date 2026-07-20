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
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 30;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,l,r;

int get_size(int x) {
    return 32-__builtin_clz(x);
}

int get_lcm(int x, int y) {
    return x*y/__gcd(x,y);
}

struct meow{
    int x,y;

    meow(int _x, int _y): x(_x), y(_y) {}

    int get_pos (int i) const {
        int idx1 = get_size(x)-1 - (i%get_size(x));
        int idx2 = get_size(y)-1 - (i%get_size(y));
        
        return (((x&(1<<idx1))?1:0) & ((y&(1<<idx2))?1:0));
    }

    bool operator<(const meow &other) {
        int lcm = get_lcm(get_lcm(get_size(x),get_size(y)),get_lcm(get_size(other.x),get_size(other.y)));
        frep(i,0,min(lcm,n)){
            int a = get_pos(i);
            int b = other.get_pos(i);

            if (a<b) return true;
            if (a>b) return false;
        }
        return false;
    }
};

void solve(){
    cin >> l >> r >> n;
    meow ans((1<<LG)-1, (1<<LG)-1);

    int x = l;
    while (x<=r) {
        int y = x+1;
        // cerr << x << " " << y << endl;
        while (y<=r) {
            // cerr << x << " " << y << endl;
            meow tmp(x,y);

            if (tmp < ans) ans = tmp;
            // cerr << "passed" << endl;
            y += (1<<__builtin_ctz(y));
        }
        x += (1<<__builtin_ctz(x));
    }

    frep(i,0,n) {
        cout << ans.get_pos(i);
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

