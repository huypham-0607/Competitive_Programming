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
int n,q;
vector<int> a[N];
int val[N];

//HLD
int TimeHLD=0,CCur=1;
int depth[N],parent[N],sz[N];
int Tin[N],Order[N],CHead[N],CID[N];

void DFS(int u, int p=0){
    depth[u] = depth[p]+1;
    parent[u] = p;
    sz[u] = 1;

    for (auto v:a[u]){
        if (v==p) continue;
        DFS(v,u);
        sz[u]+=sz[v];
    }
}

void GetHLD(int u, int p=0){
    Tin[u] = ++TimeHLD;
    Order[TimeHLD] = u;
    if (!CHead[CCur]){
        CHead[CCur] = u;
    }
    CID[u] = CCur;

    int nxt = 0;
    for (auto v:a[u]){
        if (v==p) continue;
        if (sz[v]>sz[nxt]) nxt = v;
    }

    if (nxt) GetHLD(nxt,u);
    for (auto v:a[u]){
        if (v==p || v==nxt) continue;
        ++CCur;
        GetHLD(v,u);
    }
}

//SEGGS
int IT[N*2];

void BuildIT() {
  for (int i = n; --i > 0; ) IT[i] = max(IT[i << 1], IT[i << 1 | 1]);
}

void UpdateIT(int i, int x) {
  for (IT[i += n] = x; i > 1; i >>= 1) IT[i >> 1] = max(IT[i], IT[i ^ 1]);
}

int GetIT(int l, int r) {
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, IT[l++]);
    if (r & 1) res = max(res, IT[--r]);
  }
  return res;
}


int LCA(int u, int v){
    int ans = 0;
    while (CID[u]!=CID[v]){
        if (CID[u]>CID[v]){
            ans = max(ans,GetIT(Tin[CHead[CID[u]]],Tin[u]+1));
            u = parent[CHead[CID[u]]];
        }
        else{
            ans = max(ans,GetIT(Tin[CHead[CID[v]]],Tin[v]+1));
            v = parent[CHead[CID[v]]];
        }
    }
    if (Tin[u]<Tin[v]){
        ans = max(ans,GetIT(Tin[u],Tin[v]+1));
        return ans;
    }
    else{
        ans = max(ans,GetIT(Tin[v],Tin[u]+1));
        return ans;
    }
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> val[i];
    }
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1);
    GetHLD(1);
    for (int i=1; i<=n; i++){
        IT[Tin[i]+n] = val[i];
    }
    BuildIT();
    while (q--){
        int x,u,v;
        cin >> x >> u >> v;
        if (x==1){
            UpdateIT(Tin[u],v);
        }
        else{
            cout << LCA(u,v) << " ";
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
