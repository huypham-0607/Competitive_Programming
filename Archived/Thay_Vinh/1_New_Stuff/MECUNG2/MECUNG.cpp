#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 60;
const int INF = 2e9;

int n,m;
char a[maxn][maxn];
string ans[4] = {"NO EXIT","NO MOVE","MANY","GOOD"};
vector<ii> meow;
ii s,f;
int di[4] = {0,0,-1,1};
int dj[4] = {-1,1,0,0};
int cur[4] = {0,1,2,3};
int pre[4] = {1,0,3,2};
vector<bool> v[20];
ii parent[maxn][maxn];
bool visit[maxn][maxn];
bool res[3];


void print(int i,int j){
    cout << i << " " << j << " " << parent[i][j].fi << " " << parent[i][j].se << " " << res[2] << "\n";
}

int num(char c){
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

bool bound(int i, int j){
    return (i == 0 || j == 0 || i > n || j > m);
}

void init(){
    v[0] = {1,1,1,1};
    v[1] = {0,1,1,1};
    v[2] = {1,1,1,0};
    v[3] = {0,1,1,0};
    v[4] = {1,0,1,1};
    v[5] = {0,0,1,1};
    v[6] = {1,0,1,0};
    v[7] = {0,0,1,0};
    v[8] = {1,1,0,1};
    v[9] = {0,1,0,1};
    v[10] = {1,1,0,0};
    v[11] = {0,1,0,0};
    v[12] = {1,0,0,1};
    v[13] = {0,0,0,1};
    v[14] = {1,0,0,0};
    v[15] = {0,0,0,0};
}

bool check(char c,int k){
    return v[num(c)][k];
}

void BFS(int i,int j){
    queue<ii> q;
    q.push({i,j});
    visit[i][j] = 1;
    parent[i][j] = {-1,-1};
    while(!q.empty()){
        i = q.front().fi;
        j = q.front().se;
        q.pop();
        for (int k = 0; k < 4; k++){
            int newi = i + di[k];
            int newj = j + dj[k];
            if (bound(newi,newj)) continue;
            if (!check(a[i][j],cur[k]) || !check(a[newi][newj],pre[k])) continue;
            if (make_pair(newi,newj) == parent[i][j]) continue;
            if (visit[newi][newj]){
                res[2] = 1;
                continue;
            }
            visit[newi][newj] = 1;
            parent[newi][newj] = {i,j};
            q.push({newi,newj});
        }
    }
    res[1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) res[1] &= visit[i][j];
    }
    res[1] ^= 1;
    res[0] = 1 ^ visit[f.fi][f.se];
    for (int i = 0; i < 3; i++){
        if (res[i]){
            cout << ans[i];
            return;
        }
    }
    cout << ans[3];
}

int main(){
    freopen("MECUNG.inp","r",stdin);
    freopen("MECUNG.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        if (check(a[i][1],0)){
            meow.push_back({i,1});
        }
        if (check(a[i][m],1)){
            meow.push_back({i,m});
        }
    }
    for (int j = 1; j <= m; j++){
        if (check(a[1][j],2)){
            meow.push_back({1,j});
        }
        if (check(a[n][j],3)){
            meow.push_back({n,j});
        }
    }

    s = meow.front();
    f = meow.back();
    BFS(s.fi,s.se);

    return 0;
}
