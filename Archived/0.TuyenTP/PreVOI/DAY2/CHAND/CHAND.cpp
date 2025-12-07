#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "CHAND"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,q;
int a[N],val[N],depth[N];
vector<int> adj[N];
vector<pii> edge;
vector<pii> query;
int deg[N];

/*Inititalization*/

void Init(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        edge.push_back({min(u,v),max(u,v)});
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    sort(all(edge));
    for (int i=1; i<=q; i++){
        int x,y; cin >> x >> y;
        query.push_back({x,y});
    }
}

/*Subtask1*/
bool CheckSub3(){
    int cnt1deg = 0;
    for (int i=1; i<=n; i++){
        if (deg[i]==1) ++cnt1deg;
    }
    if (cnt1deg>2) return false;
    else return true;
//    return false;
}

void DFSSub3(int u, int p){
    for (auto v:adj[u]){
        if (v==p) continue;
        depth[v] = depth[u]+1;
        DFSSub3(v,u);
    }
}

//DSU

struct DisSetUnion{
    int n;
    vector<int> parent;
    vector<vector<int>> lst;

    DisSetUnion(int _n): n(_n){
        parent.resize(n+1);
        lst.resize(n+1,vector<int>());
        for (int i=1; i<=n; i++){
            parent[i] = i;
            lst[i].push_back(i);
        }
    }

    int Find(int x){
        return (x == parent[x])? x : parent[x] = Find(parent[x]);
    }

    void Union(int x, int y){
        int u = Find(x);
        int v = Find(y);
        if (lst[v].size() > lst[u].size()) swap(u,v);
        if (u!=v){
            while ((int)lst[v].size()){
                lst[u].push_back(lst[v].back());
                lst[v].pop_back();
            }
            parent[v] = u;
        }
    }

    bool Check(int x, int id){
        int cnt = 0;
        for (auto idx:lst[id]){
            if (val[idx]>x) ++cnt;
        }
        if (cnt<=(int)lst[id].size()/2) return false;
        else return true;
    }

    int Bsearch(int id){
        int ans = 0;
        int l = 1, r = 1000000;
        while (l<=r){
            int mid = (l+r)/2;
            if (Check(mid,id)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }

        long long res = 0;
        int epic = ans+1;
        for (auto idx:lst[id]){
            res += abs(val[idx] - epic);
        }
        return res;
    }
};

bool vis[N];

void SolveSub3(){
    for (int i=1; i<=n; i++){
        if (deg[i] == 1){
            depth[i] = 1;
            DFSSub3(i,0);
            break;
        }
    }
    for (int i=1; i<=n; i++){
        val[depth[i]] = a[i];
    }

    DisSetUnion DSU(n);

    for (auto in:query){
        int u,v; tie(u,v) = in;
        u = depth[u];
        v = depth[v];
        if (u>v) swap(u,v);
        while (u<v){
            DSU.Union(u,v);
            ++u;
            --v;
        }
        long long res = 0;
        memset(vis,0,sizeof(vis));
        for (int i=1; i<=n; i++){
            int u = DSU.Find(i);
            if (!vis[u]) res+=DSU.Bsearch(u);
            vis[u] = true;
        }
        cout << res << endl;
    }

}

/*Subtask2*/
bool CheckSub4(){
    return true;
}

int up[N];

void DFSSub4(int u, int p){
    up[u] = p;
    for (auto v:adj[u]){
        if (v==p) continue;
        depth[v] = depth[u]+1;
        DFSSub4(v,u);
    }
}

int GetLCA(int u, int v){
    if (depth[u] > depth[v]) swap(u,v);
    while (depth[v] > depth[u]){
        v = up[v];
    }
    if (u==v) return u;
    while (u!=v){
        u = up[u];
        v = up[v];
    }
    return u;
}

void SolveSub4(){
    for (int i=1; i<=n; i++){
        val[i] = a[i];
    }

    deque<int> dq;
    depth[1] = 1;
    DFSSub4(1,0);
    DisSetUnion DSU(n);

//    for (int i=1; i<=n; i++){
//        cout << depth[i] << " ";
//    }
//    cout << endl;

    for (auto in:query){
        int x,y; tie(x,y) = in;
        if (depth[x] > depth[y]) swap(x,y);
        int lca = GetLCA(x,y);
//        cout << lca << endl;
        int dist = depth[x] + depth[y] - 2*depth[lca]+1;

        int cnt = 0;
        while (depth[y]>=depth[lca]){
            ++cnt;
            if (cnt<=dist/2){
                dq.push_back(y);
            }
            if ((dist-cnt+1)<=dist/2){
                DSU.Union(y,dq.back());
                dq.pop_back();
            }
            y = up[y];
        }
        while (depth[x]>depth[lca]){
            DSU.Union(x,dq.front());
            dq.pop_front();
            x = up[x];
        }

        long long res = 0;
        memset(vis,0,sizeof(vis));
        for (int i=1; i<=n; i++){
            int u = DSU.Find(i);
            if (!vis[u]) res+=DSU.Bsearch(u);
            vis[u] = true;
        }
        cout << res << endl;
    }
}

/*Subtask3*/
bool CheckSub5(){
    return false;
}

void SolveSub5(){

}

/*Subtask4*/
bool CheckSub6(){
    return false;
}

void SolveSub6(){

}

/*Driver Code*/
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();

    if (CheckSub3()) return SolveSub3(),0;
    if (CheckSub4()) return SolveSub4(),0;
    if (CheckSub5()) return SolveSub5(),0;
    if (CheckSub6()) return SolveSub6(),0;

    return 0;
}
