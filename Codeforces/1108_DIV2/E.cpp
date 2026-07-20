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

mt19937_64 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

ll rd(ll l, ll r){
    return uniform_int_distribution<ll> (l,r) (mt);
}

const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 30;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;

int ask1(int x){
    cout << x << endl;
    cout.flush();
    int val; cin >> val;
    if (val == -1) exit(0);
    return val;
}

int ask2(int a, int b){
    cout << a << " " << b << endl;
    cout.flush();
    int val; cin >> val;
    if (val == -1) exit(0);
    return val;
}

void answer(int x){
    cout << x << endl;
    cout.flush();
}

void solve(){
    int val = 1;
    int res = ask1(val);
    if (res == val){
        int a = rd(0,(1<<29)-1);
        int b = rd(0,(1<<29)-1);
        while (b==a) {
            b = rd(0,(1<<29)-1);
        }
        a*=2; a++;
        b*=2;
        int res2 = ask2(a,b);

        if (res2/2 == a/2){
            answer(0);
            return;
        }

        if (res2/2 == b/2){
            answer(1);
            return;
        }

        answer(res2%2);
        return;
    } else {
        frep(i,0,LG){
            if (((1<<i)&val) != ((1<<i)&res)) {
                int a = (1<<LG)-1, b = 0;
                if (i > 0) swap(a,b);
                int res2 = ask2(a,b);
                if (res2&(1<<i)){
                    answer(0);
                    return;
                }
                else {
                    answer(1);
                    return;
                }
            }
        }
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

