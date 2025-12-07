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
const int N = 5e5+10;
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
int ans[N];
vector<int> adj1[N],adj2[N];

int tin[N],tout[N];

struct Fenwick{
    int n;
    vector<int> BIT;
    Fenwick(int _n): n(_n){
        BIT.resize(n+10);
    }

    void Update(int idx, int val){
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int Get(int idx){
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }
} BIT(N);

int timedfs = 0;

void DFS(int u, int p){
    tin[u] = ++timedfs;
    for (auto v:adj1[u]){
        if (v==p) continue;
        DFS(v,u);
    }
    tout[u] = timedfs;
}

void DFS2(int u, int p){
    BIT.Update(tin[u],1);
    BIT.Update(tout[u]+1,-1);
    ans[u] = BIT.Get(tin[u]);
    for (auto v:adj2[u]){
        if (v==p) continue;
        DFS2(v,u);
    }
    BIT.Update(tin[u],-1);
    BIT.Update(tout[u]+1,1);
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    DFS(1,0);
    DFS2(1,0);
    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
