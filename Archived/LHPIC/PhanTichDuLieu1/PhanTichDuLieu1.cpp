#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9+7;

int n,m;
long long dp[100001][101];
int c[100001];

int main()
{
    cin >> n >> m;

    string s;
    for (int i=1; i<=n; i++){
        cin >> s;
        if (s=="?"){
            c[i] = 0;
        }
        else{
            int tmp = 1;
            for (int idx=(int)s.size()-1; idx>=0; idx--){
                c[i]+=((int)s[idx]-48)*tmp;
                tmp*=10;
            }
        }
    }

    if (c[1] == 0){
        for (int i=1; i<=m; i++){
            dp[1][i] = 1;
        }
    }
    else dp[1][c[1]] = 1;

    for (int i=2; i<=n; i++){
        if (c[i]!=0){
            int j=c[i];
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%INF;
        }
        else{
            for (int j=1; j<=m; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%INF;
            }
        }
    }

    int ans=0;
    for(int i=1; i<=m; i++){
        ans=(ans+dp[n][i])%INF;
    }
    cout << ans;

    return 0;
}
