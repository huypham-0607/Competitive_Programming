/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "team"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+9;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,q;
int a[1010],b[1010];
int dp[1010][1010][11];

/*Solution*/
void solve(){
    cin >> n >> m >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=m; i++){
        cin >> b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    for (int i=1; i<=n; i++){
        dp[i][0][0] = 1;
    }
    for (int j=1; j<=m; j++){
        dp[0][j][0] = 1;
    }
//    for (int i=1; i<=n; i++){
//        cout << a[i] << " ";
//    }
//    cout << endl;
//    for (int j=1; j<=m; j++){
//        cout << b[j] << " ";
//    }
//    cout << endl;
    for (int i=0; i<=n; i++){
        for (int j=0; j<=m; j++){
            dp[i][j][0] = 1;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            for (int k=1; k<=q; k++){
                dp[i][j][k] = ((dp[i][j-1][k]+dp[i-1][j][k])%INF-dp[i-1][j-1][k]+INF)%INF;
                if (a[i]>b[j]) dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-1][k-1])%INF;
            }
        }
    }
//    for (int i=0; i<=n; i++){
//        for (int j=0; j<=m; j++){
//            for (int k=0; k<=q; k++){
//                cout << dp[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
    cout << dp[n][m][q] << endl;
//    cout << n << " " << m;
}

/*Driver Code*/
signed main(){
    freopen(NAME".in","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
