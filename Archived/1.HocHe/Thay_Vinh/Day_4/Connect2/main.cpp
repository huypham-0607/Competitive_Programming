/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "CONNECT2"

using namespace std;

/*Constants*/
const int N = 510;
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
int ID[N][N],a[N][N];

void BFS(int si, sj, int x){
    ID[si][sj] = x;
    queue<pii> q;
    q.push({si,sj});
    while (!q.empty()){
        int i = q.front().fi;
        int j = q.front().se;
        q.pop();

        ID[i][j]
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    char c;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> c;
            a[i][j] = c-'0';
        }
    }

    int NID = 0;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i][j] && !ID[i][j]) BFS(i,j,++NID);
        }
    }

}

/*Driver Code*/
signed main(){
//    freopen(NAME".INP","r",stdin);
//    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
