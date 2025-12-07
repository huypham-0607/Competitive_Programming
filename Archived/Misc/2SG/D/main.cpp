#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e4+50;
const int maxm = 1e4+50;
const int INF = 1e18;

int test;
int n,m;
int dp[maxn],s[maxm],w[maxm],p[maxm];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=1; i<=m; i++){
        cin >> s[i] >> p[i] >> w[i];
    }
    for (int i=1; i<=n; i++){
        dp[i] = INF;
    }
    queue<pii> q;
    int ans = INF;
    for (int i=1; i<=m; i++){
        for (int j=i; j<=m; j++){
            if (dp[j] == INF) continue;
//            if (s[i]+j >= n){
//                ans = min(dp[j] + (n-j)*p[i]+w[i]);
//            }
            if (dp[j+s[i]] > dp[j] + s[i]*p[i]+w[i]) q.push({dp[j] + s[i]*p[i]+w[i],j+s[i]});
        }
        while (!q.empty()){
            int val = q.front().fi;
            int pos = q.front().se;
            q.pop();

            dp[pos] = val;
        }
        for (int j=1; j<=s[i]; j++){
            dp[j] = min(dp[j],j*p[i]+w[i]);
        }
//        for (int i=0; i<=n; i++){
//            if (dp[i] == INF) cout << -1 << " ";
//            else cout << dp[i] << " ";
//        }
//        cout << endl;
    }
//    for (int i=0; i<=n; i++){
//        cout << dp[i] << " ";
//    }
//    cout << endl;
    cout << dp[n];

    return 0;
}
