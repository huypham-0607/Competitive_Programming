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
const int N = 4e5+10;
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
int cur;
int val[N];
vector<int> nen;
vector<int> adj[N];
vector<int> lst[N];
int tin[N],tout[N];

//BIT
struct Fenwick{
    vector<int> BIT;
    int n;

    void Init(int _n){
        n = _n;
        BIT.clear();
        BIT.resize(n+10,0);
    }

    void Update(int idx, int val){
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int Get_Point(int idx){
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    int Get(int l,int r){
        return Get_Point(r) - Get_Point(l-1);
    }
} BIT;

void Reset(int res){
    cout << res << endl;

    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    for (int i=0; i<(int)nen.size(); i++){
        lst[i].clear();
    }
    nen.clear();
}

void DFS(int u, int p){
    tin[u] = ++cur;

    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u);
    }

    tout[u] = cur;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> val[i];
        nen.push_back(val[i]);
    }

    sort(all(nen));
    nen.resize(unique(all(nen)) - nen.begin());

    for (int i=1; i<=n; i++){
        val[i] = lower_bound(all(nen),val[i]) - nen.begin();
        lst[val[i]].push_back(i);
    }

    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BIT.Init(n);
    cur = 0;
    DFS(1,0);

    for (int lvl=(int)nen.size()-2; lvl>=0; lvl--){
        for (auto x:lst[lvl+1]){
            BIT.Update(tin[x],1);
        }
        for (auto x:lst[lvl]){
            int cnt = BIT.Get(tin[x],tout[x]);
            if (cnt<(int)lst[lvl+1].size()){
                Reset(x);
                return;
            }
        }
        for (auto x:lst[lvl+1]){
            BIT.Update(tin[x],-1);
        }
    }

    Reset(0);
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
