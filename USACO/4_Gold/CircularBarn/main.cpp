#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 110;
const int INF = 2e9;

int test;
int n,bruh;
int pre[maxn][maxn][maxn];
int dp[maxn][10][maxn];
int a[maxn];

signed main(){
    freopen("cbarn2.in","r",stdin);
    freopen("cbarn2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> bruh;

    for (int i=1; i<=n; i++){
        cin >> a[i];
        a[n+i] = a[i];
    }
    for (int idx=1; idx<=n; idx++){
        for (int i=1; i<=n; i++){
            for (int j=i; j<n+idx; j++){
                pre[idx][i][j] = pre[idx][i][j-1] + a[j+idx-1]*(j-i);
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=0; j<=bruh; j++){
            for (int k=1; k<=n; k++){
                dp[i][j][k] = INF;
            }
        }
    }
    int res = INF;
    for (int idx=1; idx<=n; idx++){
        for (int k=1; k<=bruh; k++){
            for (int i=1; i<=n; i++){
                dp[idx][k][i] = pre[idx][1][i];
//                cout << dp[idx][k][1] << endl;
//                cout << idx << " " << i << " " << pre[idx][1][i] << endl;
//                if (k == 1) continue;
                for (int j=2; j<=i; j++){
//                    cout << idx << " " << i << " " << j << " " << k << " " << dp[idx][k-1][j-1] << " " << pre[idx][j][i] << endl;
                    dp[idx][k][i] = min(dp[idx][k][i], dp[idx][k-1][j-1] + pre[idx][j][i]);
                }
            }
        }
        res = min(res,dp[idx][bruh][n]);
    }
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=bruh; j++){
//            for (int k=1; k<=n; k++){
//                cout << dp[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
    cout << res;
    return 0;
}
