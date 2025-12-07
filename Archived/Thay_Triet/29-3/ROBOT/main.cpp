#include <bits/stdc++.h>

using namespace std;

int n;

string dp[60][60];
int a[60][60];

int main()
{
    freopen("ROBOT.INP","r",stdin);
    freopen("ROBOT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    for (int j=0; j<=n; j++){
        dp[0][j] = "";
    }
    for (int i=1; i<=n; i++){
        dp[i][0] = "";
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            string s = dp[i-1][j];
            if (s=="" && dp[i][j-1]=="") s = dp[i][j-1];
            else if ((dp[i][j-1]<s && dp[i][j-1]!="") || (s=="" && dp[i][j-1]!="")){
                s = dp[i][j-1];
            }
            if (a[i][j]) s+="1";
            else s+="0";
            dp[i][j] = s;
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
