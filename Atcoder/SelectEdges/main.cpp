/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 3e5+10;
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
vector<pii> a[N];
int d[N];

pii DFS(int u, int p, int prev){
//    cout << u << endl;
    int res = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i=1; i<=d[u]; i++){
        pq.push(0);
    }

    for (auto in:a[u]){
        int v = in.fi;
        int w = in.se;

        if (v==p) continue;
        pii tmp = DFS(v,u,w);
        res+=tmp.fi;
        if (!pq.empty() && tmp.se>pq.top()){
            res-=pq.top();
            pq.pop();
            res+=tmp.se;
            pq.push(tmp.se);
        }
    }

    if (pq.empty()) return make_pair(res,0);
    return make_pair(res,prev-pq.top());
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> d[i];
    }
    for (int i=1; i<n; i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    pii res = DFS(1,0,0);
    cout << res.fi;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
