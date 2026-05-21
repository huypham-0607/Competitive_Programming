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

const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
int a[N], b[N];
int aex, bex, both;
int divcnt[2*N];
int org[2*N];
int bcnt[2*N];

void Sieve(int _n){
    aex = bex = both = 0;
    for (int i=1; i<=_n; i++){
        divcnt[i] = 0;
        org[i] = 0;
        bcnt[i] = 0;
    }
    for (int i=1; i<=n; i++) {
        org[a[i]]++;
    }
    for (int i=1; i<=m; i++){
        bcnt[b[i]]++;
    }
    for (int i=1; i<=_n; i++){
        if (org[i]) {
            for (int j=i; j<=_n; j+=i){
                divcnt[j] += org[i];
            }
        }

        // cout << bcnt[i] << " " << divcnt[i] << endl;

        if (bcnt[i]) {
            if (divcnt[i] == 0) {
                bex+=bcnt[i];
            }
            else if (divcnt[i] == n) {
                aex+=bcnt[i];
            }
            else {
                both+=bcnt[i];
            }
        }
    }
}


void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=m; i++){
        cin >> b[i];
    }

    Sieve(n+m);

    // cout << aex << " " << bex << " " << both << endl;

    if (both%2 == 0) {
        if (aex <= bex) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
    else {
        if (aex < bex) cout << "Bob" << endl;
        else cout << "Alice" << endl;
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

