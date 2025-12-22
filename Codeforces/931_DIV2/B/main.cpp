#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int dp[100];
int test;
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    for (int i=1; i<=90; i++){
        dp[i] = INF;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[3] = 1;
    dp[6] = 1;
    dp[10] = 1;
    dp[15] = 1;
    for (int i=1; i<=30; i++){
        dp[i+1] = min(dp[i+1],dp[i]+1);
        dp[i+3] = min(dp[i+3],dp[i]+1);
        dp[i+6] = min(dp[i+6],dp[i]+1);
        dp[i+10] = min(dp[i+10],dp[i]+1);
        dp[i+15] = min(dp[i+15],dp[i]+1);
    }
    while (test--){
        cin >> n;
        if (n <=30){
            cout << dp[n] << endl;
            continue;
        }
        int meow = n%30;
        int woof = n/30*2;
        if (meow+15<=30){
            woof--;
            meow+=15;
        }
        woof+=dp[meow];
        cout << woof << endl;
    }
    return 0;
}
