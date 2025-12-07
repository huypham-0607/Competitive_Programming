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
const int N = 101;
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
int n;
int adj[N][N];
int vis[N];
int reach_from[N];

void DFS(int u){
    reach_from[u]++;
    vis[u] = true;
    for (int v=1; v<=n; v++){
        if (!vis[v] && adj[u][v] == 1){
            DFS(v);
        }
    }
}

/*Solution*/
void solve(){
    cin >> n;
    string s;
    for (int i=1; i<=n; i++){
        cin >> s;
        for (int j=1; j<=n; j++){
            if (s[j-1] == '1'){
                adj[i][j] = 1;
            }
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            vis[j] = 0;
        }
        DFS(i);
    }

    long double ans = 0;
    for (int i=1; i<=n; i++){
        ans += (long double)1/(long double) reach_from[i];
    }

//    for (int i=1; i<=n; i++){
//        cout << reach_from[i] << " ";
//    }
//    cout << endl;
    cout << fixed << setprecision(15) << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
