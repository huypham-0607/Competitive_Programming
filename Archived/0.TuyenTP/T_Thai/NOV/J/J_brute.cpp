/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1510;
const int INF = 1e9+7;
const long long LLINF = 1e15+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;

int a[N][N],dp[N][N];

int Calc_DP(){
    int res = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            int val = -LLINF;
            if (i!=1) val = max(val,dp[i-1][j]);
            if (j!=1) val = max(val,dp[i][j-1]);
            if (i==1 && j==1) val = 0;
            dp[i][j] = val+a[i][j];
            res+=dp[i][j];
        }
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
             cin >> a[i][j];
        }
    }
    cout << Calc_DP() << endl;
    for (int id=1; id<=n; id++){
        char c;
        int i,j;
        cin >> c >> i >> j;
        if (c=='U') a[i][j]++;
        else a[i][j]--;
        cout << Calc_DP() << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

