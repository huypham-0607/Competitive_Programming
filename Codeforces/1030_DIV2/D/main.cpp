/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
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
int n,k,query;
vector<pii> a;
vector<int> v;
vector<vector<pii>> adj;
vector<vector<vector<pii>>> adjrev;
vector<vector<int>> deg;
vector<vector<bool>> cycle,vis;

int FindNext(int pos, int dir){
    int i = lower_bound(all(v),pos)-v.begin();
    int t = 0;
    if (dir == 1){
        for (; i<n; i++){
            t = (abs(pos-v[i]))%k;
            if (t == a[i].se){
                return i;
            }
        }
    }
    else{
        for (; i>=0; i--){
            t = (abs(pos-v[i]))%k;
            if (t == a[i].se) return i;
        }
    }
    return -1;
}

int FindNextLmao(int i, int dir){
    int pos = v[i];
    int t = 0;
    if (dir == 1){
        for (++i; i<n; i++){
            t = (abs(pos-v[i]))%k;
            if (t == a[i].se) return i;
        }
    }
    else{
        for (--i; i>=0; i--){
            t = (abs(pos-v[i]))%k;
            if (t == a[i].se){
                return i;
            }
        }
    }
    return -1;
}

void DFS(int u, int udir){
    cycle[u][udir] = true;

    for (auto in:adjrev[u][udir]){
        int v = in.fi;
        int vdir = in.se;
        if (!vis[v][vdir]){
            DFS(v,vdir);
        }
    }
}

/*Solution*/
void solve(){
    a.clear();
    v.clear();
    adj.clear();
    cin >> n >> k;
    adj.resize(n+10,vector<pii>(2,{-1,0}));
    adjrev.resize(n+10,vector<vector<pii>>(2,vector<pii>()));
    deg.resize(n+10,vector<int>(2,0));
    cycle.resize(n+10,vector<bool>(2,false));
    vis.resize(n+10,vector<bool>(2,false));
    for (int i=0; i<n; i++){
        int x; cin >> x;
        a.push_back({x,0});
    }
    for (int i=0; i<n; i++){
        cin >> a[i].se;
    }

    sort(all(a));
    for (int i=0; i<n; i++){
        v.push_back(a[i].fi);
    }

    for (int i=0; i<n; i++){
        int xpos = FindNextLmao(i,1);
        int xneg = FindNextLmao(i,0);
        adj[i][0] = {xneg,1};
        if (xneg!=-1){
            deg[xneg][1]++;
            adjrev[xneg][1].push_back({i,0});
        }
        adj[i][1] = {xpos,0};
        if (xpos!=-1){
            deg[xpos][0]++;
            adjrev[xpos][0].push_back({i,1});
        }
    }

    queue<pii> q;
    for (int i=0; i<n; i++){
        if (deg[i][0] == 0) q.push({i,0});
        if (deg[i][1] == 0) q.push({i,1});
    }

    while (!q.empty()){
        int i = q.front().fi;
        int dir = q.front().se;
        q.pop();
//        check[i][dir] = 0;
        deg[adj[i][dir].fi][adj[i][dir].se]--;
        if (deg[adj[i][dir].fi][adj[i][dir].se] == 0) q.push({adj[i][dir].fi,adj[i][dir].se});
    }

    for (int i=0; i<n; i++){
        vis[i][0] = 0;
        vis[i][1] = 0;
    }

    for (int i=0; i<n; i++){
        if (!vis[i][0] && deg[i][0]) DFS(i,0);
        if (!vis[i][1] && deg[i][1]) DFS(i,1);
    }

    cin >> query;
    for (int i=1; i<=query; i++){
        int x; cin >> x;
        int y = FindNext(x,1);
        if (cycle[y][0]) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}

