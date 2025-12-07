#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const ll inf = 1e15;
const int maxn = 5e6 + 5;

ll dp[maxn][3][2];
ll a[maxn];

void maximize(ll& a,ll b){
    if (a < b) a = b;
}

int main(){
    //freopen("Minimum.INP","r",stdin);
    //freopen("Minimum.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,x,y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 2; k++){
                dp[i][j][k] = -inf;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++){
        dp[i][0][0] = 0;
        if (a[i] > x){
            dp[i][1][0] = max(dp[i-1][0][0],dp[i-1][1][0]) + a[i];
            if (a[i] <= y){
                dp[i][1][1] = max({dp[i-1][1][0],dp[i-1][0][0],dp[i-1][1][1]}) + a[i];
            }
        }
        dp[i][2][1] = max(dp[i-1][1][1],dp[i-1][2][1]);
    }
    int l,r;
    for (int i = 1; i <= n; i++){
        if (dp[i][1][0] |= -inf || dp[i][1][1] != inf){
            l = i;
            break;
        }
    }
    for (int i = n; i >= 1; i--){
        if (dp[i][1][0] |= -inf || dp[i][1][1] != inf){
            r = i;
            break;
        }
    }
    cout << max(dp[n][1][1],dp[n][2][1]) << "\n";
    cout << l << " " << r;
    return 0;
}
