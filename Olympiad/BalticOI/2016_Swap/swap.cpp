/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
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
int n;
int a[N], ans[N];
vector<piii> dp[N*2];

void DFS(int u){
//    cerr << u << endl;
    int val0 = INF, val1 = INF;

    if (u*2 <= n){
        DFS(u*2);
        val0 = a[u*2];
    }
    if (u*2+1<=n){
        DFS(u*2+1);
        val1 = a[u*2+1];
    }

    if (val0 == INF && val1 == INF){
        dp[u].push_back({INF,{u,-1}});
//        cerr << u << endl;
        return;
    }
    if (val0 < val1){
        vector<piii>& dp0 = dp[u*2];
        int initval = val0;
        int idx0 = 0;
        while (idx0!=(int)dp0.size() && dp0[idx0].fi < initval) ++ idx0;

        dp[u].push_back({initval,{u,-1}});

        while (idx0!=(int)dp0.size()){
            dp[u].push_back({dp0[idx0].fi,{dp0[idx0].se.fi,0}});
            ++idx0;
        }
//        cerr << u << endl;
    }

    else{
        vector<piii>& dp0 = dp[u*2];
        vector<piii>& dp1 = dp[u*2+1];
        int midval = max(val0,val1);
//        cerr << "midval: " << midval << endl;
        piii tmp = {midval,{INF,INF}};
        int id0 = (upper_bound(all(dp0),tmp)-dp0.begin());
        int id1 = (upper_bound(all(dp1),tmp)-dp1.begin());
        pii mid0 = dp0[id0].se;
        pii mid1 = dp1[id1].se;
        mid0.se = 0;
        mid1.se = 1;
        pii midtmp = max(mid0,mid1);
//        cerr << mid0.fi << " " << mid0.se << " " << mid1.fi << " " << mid1.se << " fuck" << endl;
//        pii mid0 = dp0[0].se;
//        pii mid1 = dp1[0].se;
//        pii midtmp = {0,0};
        int initval = min(val0,val1);

        int idx0 = 0, idx1 = 0;
        int changed = -1;
        while (idx0!=(int)dp0.size() && dp0[idx0].fi < initval) ++ idx0;
        while (idx1!=(int)dp1.size() && dp1[idx1].fi < initval) ++ idx1;

        dp[u].push_back({initval,{u,-1}});

        while (!(idx0==(int)dp0.size() || idx1==(int)dp1.size())){
            if (changed==-1){
                int mnpos = min({dp0[idx0].fi,dp1[idx1].fi,midval});
                pii tmpval0 = {dp0[idx0].se.fi,0}, tmpval1 = {dp1[idx1].se.fi,1};
                pii mnval = min(tmpval0,tmpval1);

                dp[u].push_back({mnpos,mnval});

                if (mnpos == midval){
                    changed = midtmp.se;
                }
                else if (mnpos == dp0[idx0].fi){
                    ++idx0;
                }
                else{
                    ++idx1;
                }
            }
            else{
                piii mnval;
                if (changed){
                    mnval = {dp1[idx1].fi,{dp1[idx1].se.fi,1}};
                }
                else {
                    mnval = {dp0[idx0].fi,{dp0[idx0].se.fi,0}};
                }
                dp[u].push_back(mnval);
                if (changed){
                    ++idx1;
                }
                else ++idx0;
            }
        }
//        cerr << u << endl;
    }
}

void Trace(int u, int val){
    int val0 = INF;
    int val1 = INF;
    if (u*2<=n) val0 = a[u*2];
    if (u*2+1<=n) val1 = a[u*2+1];
    piii tmp = {val,{INF,INF}};
    int pos = upper_bound(all(dp[u]),tmp) - dp[u].begin();

//    cout << u << " " << val << endl;
//    cout << dp[u][pos].fi << " " << dp[u][pos].se.fi << " " << dp[u][pos].se.se << endl;

    if (dp[u][pos].se.se == -1){
        ans[u] = val;
        if (u*2 <= n) Trace(u*2,val0);
        if (u*2+1 <= n) Trace(u*2+1,val1);
    }
    else if (dp[u][pos].se.se == 0){
        ans[u] = min(val0,val1);
        if (u*2 <= n) Trace(u*2,val);
        if (u*2+1 <= n) Trace(u*2+1,max(val0,val1));
    }
    else{
        ans[u] = min(val0,val1);
        if (u*2 <= n) Trace(u*2,max(val0,val1));
        if (u*2+1 <= n) Trace(u*2+1,val);
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    DFS(1);
    Trace(1,a[1]);

//    for (int i=1; i<=n; i++){
//        for (auto in:dp[i]){
//            cout << "{" << in.fi << "," << in.se.fi << "," << in.se.se << "} " << " ";
//        }
//        cout << endl;
//    }
    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }

}

/*Driver Code*/
signed main(){
//    freopen("swap.inp","r",stdin);
//    freopen("swap.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
