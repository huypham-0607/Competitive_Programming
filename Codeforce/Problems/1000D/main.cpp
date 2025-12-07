#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e3+10;
const int INF = 2e9;
const int md = 998244353;

int n;
int dp[maxn];
int a[maxn];
int com[maxn][maxn];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        com[i-1][i] = 0;
        com[1][i] = i;
    }
    for (int i=2; i<=n; i++){
        for (int j=i; j<=n; j++){
            com[i][j] = (com[i-1][j-1]+com[i][j-1])%md;
        }
    }
//    int ans = 0;
    dp[0] = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        if (a[i]>0 && a[i]+i<=n){
            for (int j=a[i]; i+j<=n; j++){
                dp[i+j] = (dp[i+j]+(com[a[i]][j]*dp[i-1])%md)%md;
                dp[i+j] = (dp[i+j]+com[a[i]][j])%md;
            }
        }
    }
    cout << dp[n];
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << dp[i] << " ";
//    }
//    cout << endl << endl;
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << com[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
