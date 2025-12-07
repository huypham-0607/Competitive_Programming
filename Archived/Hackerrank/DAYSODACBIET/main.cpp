#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e3+10;
const int INF = 1e9;

int test;
int n;
int a[maxn],b[maxn];
int dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        b[n-i+1] = a[i];
    }

//    for (int i=1; i<=n; i++){
//        cout << a[i] << " " << b[i] << endl;
//    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            if (a[i] == b[j]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }
//            cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    int ans = INF;
    for (int i=1; i<n; i++){
        int meow = dp[i][n-i];
        ans = min(ans,n-meow*2);
    }
    for (int i=1; i<n-1; i++){
        int meow = dp[i][n-i-1];
        ans = min(ans,n-1-meow*2);
    }
    cout << ans;
    return 0;
}
