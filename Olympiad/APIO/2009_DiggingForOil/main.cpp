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
const int N = 1510;
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
int n,k;
int a[N][N];
int val[N][N];
SLeft[N][N];


/*Solution*/
void solve(){
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            a[i][j]+=a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    for (int i=k; i<=n; i++){
        for (int j=k; j<=m; j++){
            val[i-k+1][j-k+1] = val[i-k][j] + val[i][j-k] - val[i-k][j-k];
        }
    }


}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
