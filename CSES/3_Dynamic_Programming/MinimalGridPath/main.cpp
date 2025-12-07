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
const int N = 2e5+10;
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
char a[3001][3001];
bool dp[3001][3001];
string ans;

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }

//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << a[i][j];
//        }
//        cout << endl;
//    }

    dp[0][1] = dp[1][0] = 1;

    for (int sum=2; sum<=n*2; sum++){
        int pos = 26;
        for (int i=1; i<=n; i++){
            if (i>=sum) break;
            int j=sum-i;
            if (j>n) continue;
//            cout << i << " " << j << endl;
            if (dp[i-1][j] || dp[i][j-1]) pos = min(pos,a[i][j]-'A');
        }

        ans+=char(int('A')+pos);

        for (int i=1; i<=n; i++){
            int j=sum-i;
            if (j>n) continue;
            if (a[i][j]-'A'==pos && ((dp[i-1][j] || dp[i][j-1]))){
                dp[i][j] = true;
            }
        }
    }

    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
