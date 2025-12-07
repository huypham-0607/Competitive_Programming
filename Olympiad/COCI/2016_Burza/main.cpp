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
const int N = 400;
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
int n,k,leafcnt=0,timedfs=-1;
int in[N],out[N];
int depth[N];
int t[N];
vector<int> a[N];
int dp[(1<<20)+10];

bool DFSbuild(int u, int p, int d){
    if (d==0){
        ++timedfs;
        t[u] = timedfs;
        in[timedfs] = out[timedfs] = ++leafcnt;
        depth[timedfs] = d;
        return true;
    }

    int ver = false;

    int tmpin = INF, tmpout=0;
    for (auto v:a[u]){
        if (v==p) continue;
        bool tmp = DFSbuild(v,u,d-1);
        ver = (ver||tmp);
        if (tmp){
            tmpin = min(tmpin,in[t[v]]);
            tmpout = max(tmpout,out[t[v]]);
        }
    }
    if (ver){
        ++timedfs;
        t[u] = timedfs;
        if (tmpin == INF) in[timedfs] = 0;
        else in[timedfs] = tmpin;
        out[timedfs] = tmpout;
        depth[timedfs] = d;
    }
    return ver;
}

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if (k*k>=n){
        cout << "DA" << endl;
        return;
    }
    DFSbuild(1,0,k);
//    cout << leafcnt << endl;
    if (leafcnt == 0){
        cout << "DA" << endl;
        return;
    }

    for (int mask=1; mask<(1<<k); mask++){
        dp[mask] = -1;
    }

//    for (int i=1; i<=n; i++){
//        cout << t[i] << endl;
//    }

//    for (int i=0; i<=timedfs; i++){
//        cout << in[i] << " " << out[i] << endl;
//    }

    for (int i=0; i<timedfs; i++){
        int idx = depth[i];
        for (int mask=0; mask<(1<<k); mask++){
            if (mask&(1<<idx)){
                int pre = mask^(1<<idx);
                if (dp[pre]>=in[i]-1){
                    dp[mask] = max(dp[pre],out[i]);
                }
            }
            if (dp[mask] == leafcnt){
                cout << "DA" << endl;
                return;
            }
        }
    }
    cout << "NE" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
