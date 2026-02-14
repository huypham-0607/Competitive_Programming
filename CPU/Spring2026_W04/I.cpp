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

const int N = 1010;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int id = 0;
int ans[N][N];

void ass(int i, int j, int tpe) {
    if (tpe == 0) {
        ans[i][j] = 0+id;
        ans[i][n-j+1] = 1+id;
        ans[n-i+1][j] = 2+id;
        ans[n-i+1][n-j+1] = 3+id;
    }
    else {
        ans[i][j] = 0+id;
        ans[i][n-j+1] = 2+id;
        ans[n-i+1][j] = 1+id;
        ans[n-i+1][n-j+1] = 3+id; 
    }
    id+=4;
}

void solve(){
    cin >> n;
    for (int delta=2; delta<=n; delta++){
        for (int i=1; i<=n/2; i++){
            int j=delta-i;
            if (j>n/2) continue;
            if (j<=0) break;
            // cout << i << " " << j << endl;
            ass(i,j,delta%2);
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
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

