/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "cowmbat"

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e17+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,h;
int a[50][50];
int dp[N][30];
int pre[N][30];

string s;

/*Solution*/
void solve(){
    cin >> n >> m >> h;
    cin >> s;
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    for (int k=0; k<m; k++){
        for (int i=0; i<m; i++){
            for (int j=0; j<m; j++){
                int d = a[i][k]+a[k][j];
                if (d<a[i][j]) a[i][j] = d;
            }
        }
    }

    for (int i=1; i<h; i++){
        for (int j=0; j<m; j++){
            dp[i][j] = LLINF;
        }
    }

    for (int i=1; i<=n; i++){
        int idx = s[i-1]-'a';
        for (int j=0; j<m; j++){
            pre[i][j] = pre[i-1][j]+a[idx][j];
        }
    }

    for (int i=0; i<m; i++){
        dp[h][i] = pre[h][i];
    }

    for (int i=h+1; i<=n; i++){
        for (int j=0; j<m; j++){
            int mn = LLINF;
            for (int j2=0; j2<m; j2++){
                mn = min(mn,dp[i-h][j2]+pre[i][j]-pre[i-h][j]);
            }
            dp[i][j] = min(dp[i-1][j]+pre[i][j]-pre[i-1][j],mn);
        }
    }

    int res = LLINF;
    for (int i=0; i<m; i++){
        res = min(res,dp[n][i]);
    }
    cout << res << endl;

//    for (int i=1; i<=n; i++){
//        for (int j=0; j<m; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << endl;
//
//    for (int i=0; i<m; i++){
//        for (int j=0; j<m; j++){
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
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
