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
int n,m,MD;
int dp1[N][N];
int predp1[N][N];
int dp2[N][N];

/*Solution*/
void solve(){
    cin >> n >> m >> MD;
    for (int j=0; j<=m; j++){
        dp1[1][j] = 1;
        predp1[1][j] = dp1[1][j];
        if (j!=0) predp1[1][j] = (predp1[1][j]+predp1[1][j-1])%MD;
        dp2[1][j] = 1;
    }

    for (int i=2; i<=n; i++){
        for (int j=0; j<=m; j++){
            dp1[i][j] = 0;
            predp1[i][j] = 0;
            dp2[i][j] = 0;
            for (int k=j; k>=0; k--){
                dp1[i][j] = (dp1[i][j] + dp1[i-1][k]*predp1[i-1][j-k])%MD;
                if (j!=0 && k!=0) dp2[i][j] = (dp2[i][j] + dp2[i-1][k]*predp1[i-1][min(k-1,j-k)])%MD;
            }
            predp1[i][j] = dp1[i][j];
            if (j!=0) predp1[i][j] = (predp1[i][j]+predp1[i][j-1])%MD;
        }
    }
    int mul = 1;
    for (int i=1; i<n; i++){
        mul = (mul*2)%MD;
    }
    cout << (dp2[n][m]*mul)%MD << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
