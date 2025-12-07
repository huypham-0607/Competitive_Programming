///dp[i][k][r] : so cách chia đoạn [1..i] thành k đoạn sao cho đoạn đoạn cuối chia p dư r
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int MOD = 1e9 + 19972207;
const int N = 5e4 + 5;
const int K = 205;
const int P = 32;

void add(int& x,int y){
    x += y;
    if (x >= MOD) x -= MOD;
}

int f[2][K][P];

int main(){
    freopen("digits.INP","r",stdin);
    freopen("digits.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,p;
    string s;
    cin >> n >> k >> p >> s;
    s = ' ' + s;
    f[0][1][(s[1] - '0') % p] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= k; j++){
            for (int r = 0; r < p; r++){
                add(f[1][j][(10 * r + s[i] -'0') % p],f[0][j][r]);
                if (r == 0 && j < k){
                    add(f[1][j + 1][(s[i] - '0') % p],f[0][j][0]);
                }
            }
        }
        for (int j = 1; j <= k; j++){
            for (int r = 0; r < p; r++){
                f[0][j][r] = f[1][j][r];
                f[1][j][r] = 0;
            }
        }
    }
    cout << f[0][k][0];

    return 0;
}
