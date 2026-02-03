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
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;

struct state{
    int i,j,last;
    state (int _i, int _j, int _last): i(_i), j(_j), last(_last) {};
    state () {
        i = j = last = 0;
    }
};

vector<state> adj[N][N][2];
int deg[N][N][2];
int dp[N][N][2];

void solve(){
    string x,y; cin >> x >> y;
    n = x.size();
    m = y.size();
    x = "@"+x;
    y = "#"+y;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (i==0 && j==0) continue;
            if (i-1>0 && x[i] != x[i-1]) {
                deg[i][j][0]++;
                adj[i-1][j][0].push_back(state(i,j,0)); 
            }
            if (i-1>0 && x[i] != y[j]) {
                deg[i][j][0]++;
                adj[i-1][j][1].push_back(state(i,j,0));
            }
            if (i!=0 && x[i] != y[j]) {
                deg[i][j][0]++;
                adj[0][j][1].push_back(state(i,j,0));
            }
            if (j-1>0 && y[j] != x[i]) {
                deg[i][j][1]++;
                adj[i][j-1][0].push_back(state(i,j,1));
            }
            if (j-1>0 && y[j] != y[j-1]) {
                deg[i][j][1]++;
                adj[i][j-1][1].push_back(state(i,j,1));
            }
            if (j!=0 && x[i] != y[j]) {
                deg[i][j][1]++;
                adj[i][0][0].push_back(state(i,j,1));
            }
        }
    }

    deque<state> dq;
    for (int i=1; i<=n; i++){
        dp[i][0][0] = 1;
        if (x[i] != x[i-1]) dp[i][0][0] = (dp[i][0][0] + dp[i-1][0][0])%MD;
    }
    for (int j=1; j<=m; j++){
        dp[0][j][1] = 1;
        if (y[j] != y[j-1]) dp[0][j][1] = (dp[0][j][1] + dp[0][j-1][1])%MD;
    }

    for (int i=0; i<=n; i++){
        for (int j=0; j<=m; j++){
            for (int last=0; last<2; last++){
                if (deg[i][j][last] == 0) dq.push_back(state(i,j,last));
            }
        }
    }

    int ans = 0;

    while (!dq.empty()){
        auto [i,j,last] = dq.front();
        dq.pop_front();
        
        if (i!=0 && j!=0) {
            ans = (ans+dp[i][j][last])%MD;
        }
        // cout << i << " " << j << " " << last << " " << dp[i][j][last] << endl;

        for (auto [u,v,last2]:adj[i][j][last]) {
            dp[u][v][last2] = (dp[u][v][last2] + dp[i][j][last])%MD;
            deg[u][v][last2]--;
            if (!deg[u][v][last2]) dq.push_back(state(u,v,last2));
        }
    }

    cout << ans << endl;
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

