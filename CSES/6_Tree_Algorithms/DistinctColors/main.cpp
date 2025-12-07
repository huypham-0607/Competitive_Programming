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
int timedfs=0;
map<int,int> mp;
int occur[N];
int color[N],ans[N],in[N];
vector<int> adj[N];
int n,cnt;
priority_queue<pii> pq;

//ELT
void DFS(int u, int& prev, int p){
    int res = 0;
    in[u] = ++timedfs;
    int clr = color[u];
    pq.push({occur[clr],clr});
    occur[clr] = in[u];
    ++res;
    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,res,u);
        while (!pq.empty() && pq.top().fi >= in[u]){
            --res;
            pq.pop();
        }
    }
    ans[u] = res;
    prev+=res;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> color[i];
        mp[color[i]] = 0;
    }
    cnt = 0;
    for (auto it=mp.begin(); it!=mp.end(); it++){
        it->se = ++cnt;
    }
    for (int i=1; i<=n; i++){
        color[i] = mp[color[i]];
    }
    for (int i=1; i<=cnt; i++){
        occur[i] = 0;
    }
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int tmp=0;
    DFS(1,tmp,0);
    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << color[i] << " ";
//    }
//    cout << endl;
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
