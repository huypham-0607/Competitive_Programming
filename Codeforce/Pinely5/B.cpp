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

const int N = 1000;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N][N];

bool valid(int i, int j){
    return (i>0 && i<=n && j>0 && j<=n);
}

void solve(){
    cin >> n;
    int t = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            char c; cin >> c;
            if (c=='#') a[i][j] = 1;
            else a[i][j] = 0;
            t += a[i][j];
        }
    }
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }

    for (int i=1; i<n; i++){
        for (int j=1; j<n; j++){
            int cnt = 0;
            cnt = a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1];
            if (cnt == t){
                cout << "YES" << endl;
                return;
            }
        }
    }

    bool ans = false;
    for (int x=2; x<=2*n; x++){
        int cnt = 0;
        for (int i=1; i<=n; i++){
            int j = x-i;
            if (valid(i,j)) cnt += a[i][j];
        }
        for (int i=1; i<=n; i++){
            int j = x+1-i;
            if (valid(i,j)) cnt += a[i][j];
        }
        if (cnt == t) ans = true;
    }

    for (int x=-n; x<n; x++) {
        int cnt = 0;
        for (int i=1; i<=n; i++){
            int j = i-x;
            if (valid(i,j)) cnt += a[i][j];
        }
        for (int i=1; i<=n; i++){
            int j = i-(x+1);
            if (valid(i,j)) cnt += a[i][j];
        }
        if (cnt == t) ans = true;
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
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

