#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 21;
const int INF = 2e17;

int test;
int n;

int total[maxn+5],dp[(1 << 21)+2];
int a[maxn+5][maxn+5];
vector<int> sense[maxn+5];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=1; i<=n; i++){
        for (int j=0; j<n; j++){
            int x;
            cin >> x;
            total[j]+=x;
            a[i][j] = x;
        }
    }
    for (int mask=0; mask<(1<<n); mask++){
        int cnt = 0;
        for (int i=0; i<n; i++){
            if ((mask & (1<<i))) ++cnt;
        }
        sense[cnt].push_back(mask);
    }
    dp[0] = 0;
    for (int i=1; i<=n; i++){
        for (auto mask:sense[i]){
            dp[mask] = INF;
            for (int idx=0; idx<n; idx++){
                if ((mask & (1 << idx))){
                    dp[mask] = min(dp[mask],dp[(mask^(1<<idx))] + total[idx] - a[i][idx]);
                }
            }
        }
    }
    cout << dp[(1<<n)-1];
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        for (int j=0; j<(1<<n); j++){
//            cout << dp[j][i] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
