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

const int N = 11;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int val[N][N];
int c[4][N][N];
char ans[N][N];
string s;

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            char ch; cin >> ch;
            if (ch == '.'){
                c[0][i][j] = 1;
                val[i][j] += 1;
                val[j][n-i+1] += 1;
                val[n-i+1][n-j+1] += 1;
                val[n-j+1][i] += 1;
            }
        }
    }

    cin >> s;
//    cout << s;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (val[i][j]!=1){
                cout << "invalid grille" << endl;
                return;
            }
        }
    }

    for (int idx=1; idx<4; idx++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                c[idx][i][j] = c[idx-1][n-j+1][i];
            }
        }
    }

//    for (int idx=0; idx<4; idx++){
//        for (int i=1; i<=n; i++){
//            for (int j=1; j<=n; j++){
//                cout << c[idx][i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }

    int cnt = 0;
    for (int idx = 0; idx<4; idx++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (c[idx][i][j]){
                    ans[i][j] = s[cnt];
                    ++cnt;
                }
            }
        }
    }
//    cout << idx  << endl;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << ans[i][j];
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

