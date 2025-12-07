/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*
4 5 7 2
1 2
2 3
3 4
4 5
2 1
3 2
4 3
1 1 2 2
3 2 4 3
*/
/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,k,q;
int pre[510][510];
int a[510][510];
int rawr[510][510];
bool vis[510][510];

int dx[4] = {0,1,0,-1},
    dy[4] = {1,0,-1,0};

bitset<(int)1e7+10> bs;
vector<int> prime;

void Sieve(){
    bs.flip();
    bs[0] = bs[1] = 0;
    for (int i=2; i*i<1e7;i++){
       if (bs[i]){
            for(int j=(int)i*i;j<=1e7;j+=i)
                bs[j]=0;
       }
    }
    prime.push_back(0);
    int cnt = 0;
    int i = 2;
    while (cnt<250001){
        if (bs[i]){
            prime.push_back(i);
            ++cnt;
        }
        ++i;
    }
}

bool check(int i, int j){
    return (i>0 && i<=m && j>0 && j<=n);
}

void DFS(int i, int j, int dir, int cnt){
    if (!check(i,j) || vis[i][j]) return;
    vis[i][j] = true;
    if (!rawr[i][j]){
        a[i][j] = prime[cnt];
        ++cnt;
    }
    int u = i+dx[dir];
    int v = j+dy[dir];
    if (!check(u,v) || vis[u][v]){
        dir = (dir+1)%4;
        u = i+dx[dir];
        v = j+dy[dir];
    }
    DFS(u,v,dir,cnt);
}

/*Solution*/
void solve(){
    Sieve();
    cin >> m >> n >> k >> q;
    for (int i=1; i<=k; i++){
        int x,y;
        cin >> x >> y;
        rawr[x][y] = 1;
    }
    DFS(1,1,0,1);
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            pre[i][j] = a[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }
    while (q--){
        int x,y,u,v;
        cin >> x >> y >> u >> v;
        cout << pre[u][v] - pre[x-1][v] - pre[u][y-1]+pre[x-1][y-1] << endl;
    }
//    for (int i=1; i<=m; i++){
//        for (int j=1; j<=n; j++){
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
//    for (int i=1; i<=50; i++){
//        cout << prime[i] << endl;
//    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
