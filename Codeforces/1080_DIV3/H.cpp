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

void output_pts(int a, int b, int c, int d, int e, int f) {
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
}

void solve(){
    cin >> n;
    if (n%2 == 0) {
        cout << 3*n*n << endl;
        for (int i=2; i<=n*3; i+=2) {
            for (int j=3; j<=n*3; j+=3){
                output_pts(i-1, j-2, i, j-2, i, j-1);
                output_pts(i-1, j-1, i-1, j, i, j);
            }
        }
    } else {
        cout << 3*n*n-1 << endl;
        for (int i=2; i<=n*3-3; i+=2) {
            for (int j=3; j<=n*3; j+=3){
                output_pts(i-1, j-2, i, j-2, i, j-1);
                output_pts(i-1, j-1, i-1, j, i, j);
            }
        }

        for (int j=2; j<=3*n; j++){
            output_pts(n*3-2,j-1,n*3-1,j-1,n*3,j);
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

