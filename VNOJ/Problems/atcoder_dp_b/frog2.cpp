#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+7;

int n,k;
int h[100001], dp[100001];

void Solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> h[i];
    }

    dp[1] = 0;

    for (int i=2; i<=n; i++){
        dp[i] = INF;
        for (int j=1; j<=k; j++){
            if (i-j<=0) break;
            dp[i] = min(dp[i],dp[i-j]+abs(h[i] - h[i-j]));
        }
    }

    cout << dp[n];
}

int main(){

    Solve();

    return 0;
}
