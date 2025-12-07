#include <bits/stdc++.h>
#define limit 1000000
using namespace std;

int x,n;
int a[100], dp[limit+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    for (int i=1; i<=limit; i++){
        dp[i] = limit+1;
    }

    dp[0] = 0;

    for (int i=1; i<=limit; i++){
        for (int j=0; j<n; j++){
            if (i>=a[j]){
                dp[i] = min(dp[i], dp[i-a[j]]+1);
            }
        }
    }
    if (dp[x] == limit+1) cout << -1;
    else cout << dp[x];
    return 0;
}
