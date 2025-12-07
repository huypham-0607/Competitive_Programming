#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define mod 1000000007
using namespace std;

int n,m;
int dp[1050][2];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int maxmask = (1<<(n))-1;

    dp[0][0] = 1;

    for (int j=1; j<=m; j++){
        for (int i=1; i<=n; i++){
            for (int mask=0; mask<=maxmask; mask++){
                dp[mask][1] = dp[mask ^ (1 << (i-1))][0];
                if ((i>1) && !(mask & (1 << (i-1))) && !(mask & (1 << (i-2)))){
                    dp[mask][1] += dp[mask ^ (1 << (i-2))][0];
                }
                dp[mask][1]%=mod;
            }
            for (int mask=0; mask<=maxmask; mask++){
                dp[mask][0]=dp[mask][1];
            }
        }
    }
    cout << dp[0][0];

    return 0;
}
