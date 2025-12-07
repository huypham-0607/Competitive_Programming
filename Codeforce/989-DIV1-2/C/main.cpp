/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1000+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m;
int a[N][N];
int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};
bool vis[N][N];

/*Solution*/
void solve(){
    cin >> n >> m;
    queue<pii> q;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            char c; cin >> c;
            if (c=='U'){
                a[i][j] = 0;
                if (i==1){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
            if (c=='R'){
                a[i][j] = 1;
                if (j==m){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
            if (c=='D'){
                a[i][j] = 2;
                if (i==n){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
            if (c=='L'){
                a[i][j] = 3;
                if (j==1){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
            if (c=='?') a[i][j] = -1;
        }
    }

    while (!q.empty()){
        int i,j; tie(i,j) = q.front();
        q.pop();


        for (int idx=0; idx<4; idx++){
            int x = i+di[idx];
            int y = j+dj[idx];
            if (x<=0 || x>n || y<=0 || y>m) continue;
            if (a[x][y] == (idx+2)%4 && !vis[x][y]){
                vis[x][y] = true;
                q.push({x,y});
            }
        }
    }

//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=m; j++){
//            cout << vis[i][j] << " ";
//        }
//        cout << endl;
//    }

    int ans = 0;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            bool ver = 0;
            for (int idx=0; idx<4; idx++){
                int x = i+di[idx];
                int y = j+dj[idx];
                if (x<=0 || x>n || y<=0 || y>m) continue;
                if (!vis[x][y]){
                    ver = 1;
                }
            }
            if (ver && !vis[i][j]) ++ans;
        }
    }

    cout << ans << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            a[i][j] = 0;
            vis[i][j] = 0;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
