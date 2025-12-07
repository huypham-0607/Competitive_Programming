#include <bits/stdc++.h>
#define limit 1000000
#define div 1000000007
using namespace std;

int x,n;
unsigned long long a[100], dp[limit+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    dp[0] = 1;

    for (int i=1; i<=limit; i++){
        for (int j=0; j<n; j++){
            if (i>=a[j]){
                dp[i] = (dp[i] + dp[i-a[j]])%div;
            }
        }
    }
    cout << dp[x];
    return 0;
}
