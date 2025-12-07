#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e3+10;
const int INF = 1e17;

int test;
int n,m;
vector<pii> a[maxn][maxn];
bool vis[maxn][maxn];
int height[maxn][maxn];
bool edge[maxn][maxn];
vector<piii> v;

int BFS(){
    vis[1][n] = true;
//    vis[n][1] = true;
    height[n][1] = 0;
//    height[1][n] = 0;
    queue<piii> q;
    q.push({{1,n},0});
//    q.push({{n,1},0});
    while (!q.empty()){
        int x = q.front().fi.fi;
        int y = q.front().fi.se;
        int d = q.front().se;
        q.pop();

//        cout << x << " " << y << ": ";
        for (auto in:a[x][y]){
            int i = in.fi;
            int j = in.se;
//            cout << i << " " << j << "   ";
            if (!vis[i][j]){
                vis[i][j] = true;
                height[i][j] = d+1;
                q.push({{i,j},d+1});
            }
        }
//        cout << endl;
    }
    int res = INF;
    for (int i=1; i<=n; i++){
        if (vis[i][i]) res = min(res,height[i][i]*2);
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (vis[i][j] && vis[j][i] && abs(height[i][j] - height[j][i]) <= 1 && edge[i][j]){
                res = min(res,height[i][j] + height[j][i]);
            }
//            cout << height[i][j] << " ";
        }
//        cout << endl;
    }
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << height[i][j] << " ";
//        }
//        cout << endl;
//    }
    if (res == INF) return -1;
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--){
        int x,y;
        char z;
        cin >> x >> y >> z;
        int bruh = z-'a';
        a[x][y].push_back({y,x});
        a[y][x].push_back({x,y});
        edge[x][y] = true;
        edge[y][x] = true;
        for (auto in:v){
            if (in.se == bruh){
                a[x][in.fi.fi].push_back({y,in.fi.se});
                a[x][in.fi.se].push_back({y,in.fi.fi});
                a[y][in.fi.fi].push_back({x,in.fi.se});
                a[y][in.fi.se].push_back({x,in.fi.fi});
                a[in.fi.fi][x].push_back({in.fi.se,y});
                a[in.fi.se][x].push_back({in.fi.fi,y});
                a[in.fi.fi][y].push_back({in.fi.se,x});
                a[in.fi.se][y].push_back({in.fi.fi,x});

            }
        }
        v.push_back({{x,y},bruh});
    }

//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << i << "-" << j << ": ";
//            for (auto in:a[i][j]){
//                cout << "{" << in.fi << "," << in.se << "}   ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }

    cout << BFS();

    return 0;
}
