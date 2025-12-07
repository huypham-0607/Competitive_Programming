/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,s;
int dp[2020];
priority_queue<piii,vector<piii>,greater<piii>> pq;

/*Solution*/
void solve(){
    cin >> s >> n;

    for (int i=1; i<=n; i++){
        int v,w,k;
        cin >> v >> w >> k;
        pq.push({{w,-v},k});
    }

    for (int i=1; i<=s; i++){
        int cnt = 0;
        for (int j=1; j<=s/i; j++){
            while (!pq.empty() && pq.top().fi.fi<i) pq.pop();
            if (pq.empty() || pq.top().fi.fi>i) break;
            int val = -pq.top().fi.se;
//            cout << i << " " << j << " " << pq.top().fi.fi << " " << pq.top().fi.se << " " << pq.top().se << " " << cnt << endl;

            for (int idx=s; idx>=i; idx--){
                dp[idx] = max(dp[idx],dp[idx-i]+val);
            }


//            for (int i=0; i<=s; i++){
//                cout << dp[i] << " ";
//            }
//            cout << endl;

            ++cnt;
            if (cnt == pq.top().se){
                pq.pop();
                cnt = 0;
            }
        }
    }
    cout << dp[s];
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
