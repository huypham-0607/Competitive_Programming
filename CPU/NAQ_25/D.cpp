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

const int N = 52;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

vector<int> di = {1,0,-1,0},
            dj = {0,1,0,-1};

bool vis[N][N][4];
int a[N][N];
int n,m,ei,ej,si,sj;

bool IsBound(int i, int j){
    return (i>0 && i<=n && j>0 && j<=m);
}

void DFS(int i, int j, int didx){
//    cout << i << " " << j << " " << didx << endl;
    for (int lmao = 1; lmao>=-1; lmao--){
        int idx = (didx+lmao+4)%4;
        int x = i;
        int y = j;
        if (lmao!=-1){
            x+=di[idx];
            y+=dj[idx];
        }
        if (!IsBound(x,y) || a[x][y] == 1) continue;
        if (!vis[x][y][idx]){
            vis[x][y][idx] = true;
            DFS(x,y,idx);

        }
        break;
    }
}

void solve(){
    cin >> n >> m;
    cin >> si >> sj >> ei >> ej;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            char c; cin >> c;
            int x = c-'0';
            a[i][j] = x;
        }
    }
    DFS(si,sj,1);
    int ans = 0;
    for (int idx=0; idx<4; idx++){
        if (vis[ei][ej][idx]) ans = 1;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
//    cin.tie(0) -> sync_with_stdio(0);
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

