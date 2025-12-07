#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int n,a[1010];
bool dp[110][100100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cout << "cool" << endl;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }   
    dp[0][0] = true;
    for (int i=0; i<n; i++){
        for (int j=0; j<=100000; j++){
            if (dp[i][j]){
                dp[i+1][j] = true;
                dp[i+1][j+a[i+1]] = true;
            }
        }
    }
    int c=0;
    for (int i=1; i<=100000; i++){
        if (dp[n][i]) c++;
    }
    cout << c << endl;
    for (int i=1; i<=100000;i++){
        if (dp[n][i]) cout << i << " "; 
    }
    return 0;
}