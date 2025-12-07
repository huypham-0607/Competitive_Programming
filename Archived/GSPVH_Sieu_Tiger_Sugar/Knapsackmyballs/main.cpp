#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

ll dp[2225][5610];
ll v[2225];
ll w[2225];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("knapsack.inp","r",stdin);
    freopen("knapsack.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (j - w[i] >= 0){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j - w[i]] + v[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][m];
    return 0;
}
