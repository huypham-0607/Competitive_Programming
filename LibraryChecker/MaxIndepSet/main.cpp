/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 20;
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
int n,m;
vector<int> a,b,c;
vector<int> dp1,dp2,trace1,trace2;

void Solve(int n, vector<int>& adj, vector<int>& dp, vector<int>& trace){
    dp[0] = 0;
    for (int mask=1; mask<(1<<n); mask++){
        for (int idx=0; idx<n; idx++){
            if (!(mask&(1<<idx))) continue;
            if (dp[mask&adj[idx]]+1>dp[mask]){
                dp[mask] = dp[mask&adj[idx]]+1;
                trace[mask] = (trace[mask&adj[idx]]^(1<<idx));
            }
        }
    }
}

/*Solution*/
void solve(){
    a.resize(N+1);
    b.resize(N+1);
    c.resize(N+1);
    cin >> n >> m;
    int n1 = n/2;
    int n2 = n-n1;
    dp1.resize((1<<n1)+10);
    trace1.resize((1<<n1)+10);
    dp2.resize((1<<n2)+10);
    trace2.resize((1<<n2)+10);
    for (int i=0; i<n1; i++){
        a[i] = ((1<<n1)-1)^(1<<i);
    }
    for (int i=0; i<n2; i++){
        b[i] = ((1<<n2)-1)^(1<<i);
    }
    for (int i=0; i<=n1; i++){
        c[i] = ((1<<n2)-1);
    }
    while (m--){
        int u,v;
        cin >> u >> v;
        if (u>v) swap(u,v);
        if (u<n1){
            if (v<n1){
                a[u] = a[u]^(1<<v);
                a[v] = a[v]^(1<<u);
            }
            else{
                c[u] = c[u]^(1<<(v-n1));
            }
        }
        else{
            b[u-n1] = b[u-n1]^(1<<(v-n1));
            b[v-n1] = b[v-n1]^(1<<(u-n1));
        }
    }
    Solve(n1,a,dp1,trace1);
    Solve(n2,b,dp2,trace2);

    int ans = 0;
    int sm1=0,sm2=0;
    for (int mask=0; mask<(1<<n1); mask++){
        int mask2 = (1<<n2)-1;
        for (int idx=0; idx<n1; idx++){
            if (!(mask&(1<<idx))) continue;
            mask2&=c[idx];
        }
        if (dp1[mask]+dp2[mask2]>ans){
            ans = dp1[mask]+dp2[mask2];
            sm1 = trace1[mask]; sm2 = trace2[mask2];
        }
    }
    cout << ans << endl;
    for (int i=0; i<n1; i++){
        if (sm1&(1<<i)) cout << i << " ";
    }
    for (int i=0; i<n2; i++){
        if (sm2&(1<<i)) cout << i+n1 << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
