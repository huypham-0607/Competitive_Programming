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

const int N = 105;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
int a[N][N];
int ans[N][N];
int di[4] = {1,0,-1,0},
    dj[4] = {0,1,0,-1};

bool isValid(int i, int j){
    return (a[i][j] && (!a[i-1][j] || !a[i][j-1] || !a[i+1][j] || !a[i][j+1]));
}

void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            char c; cin >> c;
            if (c=='T')  a[i][j] = 1;
        }
    }

    queue<pii> q;

    int mx = 0;

    for (int idx=1; idx<=100; idx++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (isValid(i,j)){
                    ans[i][j] = idx;
                    mx = max(mx,idx);
                    q.push({i,j});
                }
            }
        }
        while (!q.empty()) {
            auto [i,j] = q.front();
            q.pop();
            a[i][j] = 0;
        }
    }

    if (mx < 10){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (ans[i][j] == 0){
                    cout << "..";
                }
                else if (ans[i][j]/10 == 0){
                    cout << "." << ans[i][j];
                }
                else cout << ans[i][j];
            }
            cout << endl;
        }
    }
    else {
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (ans[i][j]/100){
                    cout << ans[i][j];
                }
                else if (ans[i][j]/10){
                    cout << "." << ans[i][j];
                }
                else if (ans[i][j]/1){
                    cout << ".." << ans[i][j];
                }
                else cout << "...";
            }
            cout << endl;
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

