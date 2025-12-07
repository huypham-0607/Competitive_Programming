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
int n,q,w;

//HLD

int curpos = 0;
int parent[N], sz[N], depth[N];
int root[N], pos[N];
int state[N];

priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;

void DFS(int u, int p = 0){
    sz[u] = 1;
    for (auto in:adj[u]){
        int v = in.fi;
        int w = in.se;
        if (v==p) continue;
        parent[v] = u;
        depth[v] = depth[u]+1;
        DFS(v,u);
    }
}

void BuildHLD(int u, int r=u){
    root[u] = r;
    int nxt = 0;
    for (auto in:adj[u]){
        int v = in.fi;
        int w = in.se;
        if (v==p) continue;
        if (!nxt || sz[nxt]<sz[v]) nxt = v;
    }

    if (nxt) BuildHLD(nxt,r);

    for (auto in:adj[u]){
        int v = in.fi;
        int w = in.se;
        if (v==p || v==nxt) continue;
        BuildHLD(v,v);
    }
}

/*Solution*/
void solve(){
    cin >> n >> q >> w;

}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
