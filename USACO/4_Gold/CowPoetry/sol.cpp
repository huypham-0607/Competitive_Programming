#include "bits/stdc++.h"
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define endl '\n'
#define int long long
#define f first
#define mp make_pair
#define s second
using namespace std;

const int M = 1e9 + 7;
int n, m, k, ans = 1;
vector <pair<int,int> > a;
int dp1[5001];//#of syllables
int e[5001];//rhyme class
int dp[27];
int mat[27];
//how many ways are there to build a line such that it ends in rhyme class i and contains exactly K syllables

int P(int x, int y){//x^y
    int r = 1;
    for(y <<= 1; y >>= 1; x = x * x % M) if (y & 1) r = r * x % M;
    return r;
}

signed main()
{
    freopen("poetry.in", "r", stdin); freopen("poetry.ans", "w", stdout);
    fast;
    cin >> n >> m >> k;
    dp1[0] = 1;
    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        a.push_back(mp(x, y));
    }
    for(int i = 1; i <= m; i++){
        char c; cin >> c;
        mat[c - 'A' + 1]++;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            int x = a[j].f, c = a[j].s;
            if(x + i > k) break;
            if(x + i == k){
                e[c] += dp1[i];
                e[c] %= M;
            }
            else{
                dp1[i + x] += dp1[i];
                dp1[i + x] %= M;
            }
        }
    }
    for(int i = 1; i <= 26; i++){
        if(mat[i] == 0) continue;
        for(int j = 1; j <= n; j++){
            dp[i] += P(e[j], mat[i]);
            dp[i] %= M;
        }
        // cout << i << ' ' << dp[i] << endl;
        ans *= dp[i];
        ans %= M;
    }
    cout << ans << endl;
}
