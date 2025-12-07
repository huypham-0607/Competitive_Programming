#include <bits/stdc++.h>

using namespace std;

int dp[1000001];
int n,x;

int ext(int& x){
    int tam = x%10;
    x/=10;
    return tam;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++){
        dp[i] = 999999999;
    }
    dp[n] = 1;
    for (int i=n; i>0; i--){
        if (dp[i]!=999999999){
            //cout << i << ":" << endl << "Value: " << dp[i] << endl;
            x = i;
            while (x){
                int num = ext(x);
                //cout << i-num << " ";
                if (i-num>=0){
                    dp[i-num] = min(dp[i-num],dp[i]+1);
                }
            }
            //cout << endl << endl;
        }
    }
    //cout << endl;
    cout << dp[0]-1;
    return 0;
}
