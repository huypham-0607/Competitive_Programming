/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
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

const int N = 2001;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
int di[8] = {1,1,0,-1,-1,-1,0,1};
int dj[8] = {0,1,1,1,0,-1,-1,-1};
bool a[N][N];
int b[N][N];
int c[N][N];
int d[N][N];
int rays[N];

bool vis[N][N];
bool vis2[N][N];

bool valid(int i, int j) {
    return (i > 0 && i <= n && j>0 && j<=m);
}

void BFS(int si, int sj, int id) {
    queue<pii> q;
    q.push({si,sj});
    vis[si][sj] = 1;
    while (!q.empty()) {
        auto [i,j] = q.front();
        q.pop();

        b[i][j] = id;

        for (int idx = 0; idx < 8; idx++){
            int x = i + di[idx];
            int y = j + dj[idx];

            if (valid(x,y) && a[x][y] && !vis[x][y]) {
                vis[x][y] = 1;
                q.push({x,y});
            }
        }
    }
}

void BFSrays(int si, int sj) {
    queue<pii> q;
    q.push({si,sj});
    vis2[si][sj] = 1;
    while (!q.empty()) {
        auto [i,j] = q.front();
        q.pop();

        for (int idx = 0; idx < 8; idx++){
            int x = i + di[idx];
            int y = j + dj[idx];

            if (valid(x,y) && d[x][y] && !vis2[x][y]) {
                vis2[x][y] = 1;
                q.push({x,y});
            }
        }
    }
}

void erode() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            d[i][j] = c[i][j];
            int cnt = 0;
            for (int idx =0; idx < 8; idx++){
                int x = i + di[idx];
                int y = j + dj[idx];
                if (c[x][y] == 1) ++ cnt;
            }
            if (cnt != 8) d[i][j] = 0;
        }
    }
    swap(c,d);
}

void enlarge() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            d[i][j] = c[i][j];
            int cnt = 0;
            for (int idx =0; idx < 8; idx++){
                int x = i + di[idx];
                int y = j + dj[idx];
                if (c[x][y] == 1) ++ cnt;
            }
            if (cnt != 0) d[i][j] = 1;
        }
    }
    swap(c,d);
}

void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
            c[i][j] = a[i][j];
        }
    }

    int cmp = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[i][j] && !vis[i][j]) {
                BFS(i,j,++cmp);
            }
        }
    }

    for (int i=0; i<2; i++) {
        erode();
//        cout << endl;
//        for (int i=1; i<=n; i++){
//            for (int j=1; j<=m; j++) {
//                cout << c[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }

    for (int i=0; i<5; i++) {
        enlarge();
//        cout << endl;
//        for (int i=1; i<=n; i++){
//            for (int j=1; j<=m; j++) {
//                cout << c[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            d[i][j] = a[i][j];
            if (c[i][j]) d[i][j] = 0;
        }
    }

//    cout << endl;
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=m; j++) {
//            cout << d[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (d[i][j] && !vis2[i][j]) {
                int id = b[i][j];
                rays[id]++;
                BFSrays(i,j);
            }
        }
    }

    cout << cmp << endl;
    sort(rays+1,rays+1+cmp);
    for (int i=1; i<=cmp; i++) {
        cout << rays[i] << " ";
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
