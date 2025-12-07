#include <bits/stdc++.h>
#define ll long long
#define lim -100000000000000000
using namespace std;

ll dp[6000][6000];
ll a[6000],pre[6000];
int n;

bool inbound(int l, int r){
    return (l>=0 && r<n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> a[0];
    pre[0] = a[0];
    for (int i=1; i<n; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    for (int i=0; i<n; i++){
        dp[i][i] = a[i];
    }
    int range = n;
    for(int i=1; i<range; i++){
        int l = 0;
        int r = l+i;
        while (inbound(l,r)){
            dp[l][r] = max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            l++;
            r++;
        }
    }
    cout << (pre[n-1] + dp[0][n-1])/2;
    /*cout << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    return 0;
}
