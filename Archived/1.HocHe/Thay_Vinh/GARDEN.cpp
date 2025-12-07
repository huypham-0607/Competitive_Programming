/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1600;
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
int pre[N][N],suf[N][N];
int dp[N][N];

/*Solution*/
void solve(){
    cin >> n >> m;
    string s;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> s;
            if (s[0] == 'X'){
                if ((int)s.size() == 2) pre[i][j] = s[1] - '0';
                else pre[i][j] = (s[1]-'0')*10+s[2]-'0';
            }
            else{
                if ((int)s.size() == 2) suf[i][j] = s[1] - '0';
                else suf[i][j] = (s[1]-'0')*10+s[2]-'0';
            }
        }
    }
    for (int j=1; j<=m; j++){
        for (int i=1; i<=n; i++){
            pre[i][j]+=pre[i-1][j];
        }
        for (int i=n; i>0; i--){
            suf[i][j]+=suf[i+1][j];
        }
    }
    dp[1][1] = suf[2][1];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (i>1) dp[i][j] = max(dp[i][j],dp[i-1][j]-suf[i][j]+suf[i+1][j]);
            if (j>1) dp[i][j] = max(dp[i][j],dp[i][j-1]+pre[i-1][j]+suf[i+1][j]);
            if (j>1 && i>1) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+pre[i-1][j]+suf[i+1][j]);
        }
    }
    cout << dp[n][m] << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << suf[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*Driver Code*/
signed main(){
//    freopen("GARDEN.INP","r",stdin);
//    freopen("GARDEN.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
