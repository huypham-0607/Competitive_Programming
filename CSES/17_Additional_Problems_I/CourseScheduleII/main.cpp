/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
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
int n,m;
int deg[N];
vector<int> adj[N];
priority_queue<int> pq;

/*Solution*/
void solve(){
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
//        if (u==6 || v==6) cout << u << " " << v << endl;
        adj[v].push_back(u);
        ++deg[u];
    }
    for (int i=1; i<=n; i++){
        if (!deg[i]) pq.push(i);
    }
    vector<int> ans;
    while (!pq.empty()){
        int u = pq.top();
        pq.pop();

        ans.push_back(u);
        for (auto v:adj[u]){
            --deg[v];
            if (!deg[v]) pq.push(v);
        }
    }
    int cnt = 0;
    while (ans.size()){
        cout << ans.back() << " ";
        ans.pop_back();
//        ++cnt;
//        if (cnt == 12) return;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
