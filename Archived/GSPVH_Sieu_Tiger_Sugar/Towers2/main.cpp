#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 9090;

int dp[maxn][maxn];
ll pre[maxn];

#define sum(l,r) (pre[r] - pre[l-1])

int main(){
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> pre[i];
        pre[i] += pre[i-1];
        dp[1][i] = 1;
    }
    for (int l = 2; l <= n; l++){
        int k = l;
        int tmp = -1;
        for (int r = l; r <= n; r++){
//            if (sum(l,r) <= sum(k,l-1)){
//                continue;
//            }
            while (k > 1 && sum(l,r) > sum(k-1,l-1)){
                --k;
                tmp = max(tmp,dp[k][l-1]);
            }
            dp[l][r] = tmp < 0 ? -1 : tmp + 1;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        res = max(res,dp[i][n]);
    }
    cout << n - res;
    return 0;
}
