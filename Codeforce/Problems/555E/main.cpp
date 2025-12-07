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
int n,m,q,timedfs=0,dfstreecnt=0;
int cid[N],low[N],num[N],tin[N];
vector<pii> adj[N];
vector<pii> elt;
bool IsBridge[N];
bool vis[N];
int pre1[N],pre2[N];

//ST
pii ST[4*2*N];

void Build(int idx, int l, int r){
    if (l==r){
        ST[idx] = elt[l];
        return;
    }
    int mid = (l+r)/2;
    Build(idx*2,l,mid); Build(idx*2+1,mid+1,r);
    ST[idx] = min(ST[idx*2],ST[idx*2+1]);
}

pii Get(int idx, int l, int r, int x, int y){
    if (y<l || r<x) return make_pair(INF,INF);
    if (x<=l && r<=y) return ST[idx];
    int mid = (l+r)/2;
    return min(Get(idx*2,l,mid,x,y),Get(idx*2+1,mid+1,r,x,y));
}

void DFS(int u, int prev, int s, int h){
    num[u] = low[u] = ++dfstreecnt;
    cid[u] = s;
    tin[u] = ++timedfs;
    elt.push_back({h,u});
    for (auto in:adj[u]){
        int v = in.fi;
        int id = in.se;

        if (id == prev) continue;
//        cout << u << " " << v << " " << id << endl;
        if (!num[v]){
            DFS(v,id,s,h+1);
            ++timedfs;
            elt.push_back({h,u});
            low[u] = min(low[u],low[v]);
            if (num[v] == low[v]){
                IsBridge[id] = true;
            }
        }
        else low[u] = min(low[u],num[v]);
    }
}

pii DFS2(int u){
    pii tu = {0,0};
    vis[u] = true;
    for (auto in:adj[u]){
        int v = in.fi;
        int id = in.se;

        if (!vis[v]){
            pii tv = DFS2(v);
            if (IsBridge[id]){
                if (tv.fi && tv.se){
                    cout << "No" << endl;
                    exit(0);
                }
            }
            tu.fi+=tv.fi;
            tu.se+=tv.se;
        }
    }
    tu.fi+=pre1[u];
    tu.se+=pre2[u];
    return tu;
}

/*Solution*/
void solve(){
    cin >> n >> m >> q;
    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    elt.push_back({0,0});
    int cnt = 0;
    for (int i=1; i<=n; i++){
        if (!num[i]){
            DFS(i,0,++cnt,1);
        }
//        for (int i=1; i<=n; i++){
//            cout << num[i] << " ";
//        }
//        cout << endl;
    }
//    for (int i=1; i<=m; i++){
//        cout << IsBridge[i] << " ";
//    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << cid[i] << " ";
//    }
//    cout << endl;
    Build(1,1,timedfs);
    for (int i=1; i<=q; i++){
        int u,v;
        cin >> u >> v;
        if (cid[u]!=cid[v]){
            cout << "No" << endl;
            return;
        }
        pii tmp;
        if (tin[u]>tin[v]) tmp = Get(1,1,timedfs,tin[v],tin[u]);
        else tmp = Get(1,1,timedfs,tin[u],tin[v]);
        int lca = tmp.se;
        ++pre1[u];
        --pre1[lca];
        ++pre2[v];
        --pre2[lca];
    }
//    dfstreecnt=0;
//    cout << "meow" << endl;
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            DFS2(i);
        }
    }
    cout << "Yes" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
