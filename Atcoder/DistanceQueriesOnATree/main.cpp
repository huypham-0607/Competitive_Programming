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

//Euler Tour

struct Edge{
    int u=0,v=0,w=0;
    int s=0,e=0;
};

int timedfs = 0, timedfs2 = 0;
Edge edge[N];
int in[N];
int height[N];
vector<pii> a[N];
int dist[N*2];
int elt[N*2];
int IT[N*8],DIT[N*8];

void dfs(int u, int p, int w, int h){
    elt[++timedfs2] = u;
    height[u] = h;
    in[u] = timedfs2;
    dist[++timedfs] = w;
    for (auto in:a[u]){
        int v = in.fi;
        int idx = in.se;
        int w = edge[idx].w;
        if (v == p) continue;
        edge[idx].s = timedfs+1;
        dfs(v,u,w,h+1);
        elt[++timedfs2] = u;
        edge[idx].e = timedfs;
    }
    dist[++timedfs] = -w;
}

int comp(int i, int j){
    if (height[i] < height[j]) return i;
    else return j;
}

void buildh(int idx, int l, int r){
    if (l==r){
        IT[idx] = elt[l];
        return;
    }
    int mid = (l+r)/2;
    buildh(idx*2,l,mid);
    buildh(idx*2+1,mid+1,r);
    IT[idx] = comp(IT[idx*2],IT[idx*2+1]);
}

void buildd(int idx, int l, int r){
    if (l==r){
        DIT[idx] = dist[l];
        return;
    }
    int mid = (l+r)/2;
    buildd(idx*2,l,mid);
    buildd(idx*2+1,mid+1,r);
    DIT[idx] = DIT[idx*2]+DIT[idx*2+1];
}

int RMQ(int idx, int l, int r, int x, int y){
    if (r<x || y<l) return 0;
    if (x<=l && r<=y) return IT[idx];
    int mid = (l+r)/2;
    return comp(RMQ(idx*2,l,mid,x,y),RMQ(idx*2+1,mid+1,r,x,y));
}

int LCA(int u, int v){
    int x = in[u];
    int y = in[v];
    if (y<x) swap(x,y);
    return RMQ(1,1,timedfs2,x,y);
}

void update(int idx, int l, int r, int x, int val){
    if (r<x || x<l) return;
    if (l == r){
        DIT[idx] = val;
        return;
    }
    int mid = (l+r)/2;
    update(idx*2,l,mid,x,val);
    update(idx*2+1,mid+1,r,x,val);
    DIT[idx] = DIT[idx*2]+DIT[idx*2+1];
}

int get(int idx, int l, int r, int x, int y){
    if (r<x || y<l) return 0;
    if (x<=l && r<=y){
        return DIT[idx];
    }
    int mid = (l+r)/2;
    return get(idx*2,l,mid,x,y)+get(idx*2+1,mid+1,r,x,y);
}

/*Solution*/
void solve(){
    height[0] = INF;
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge[i].u = u;
        edge[i].v = v;
        edge[i].w = w;
        a[u].push_back({v,i});
        a[v].push_back({u,i});
    }
    dfs(1,0,0,1);
//    cout << "meow" << endl;
//    cout << timedfs << " " << timedfs2 << endl;
//    for (int i=1; i<=timedfs; i++){
//        cout << dist[i] << " ";
//    }
//    cout << endl;
//    for (int i=1; i<=timedfs2; i++){
//        cout << elt[i] << " ";
//    }
//    cout << endl;
    buildh(1,1,timedfs2);
    buildd(1,1,timedfs);
    cin >> q;
//    for (int i=1; i<=n; i++){
//        cout << get(1,1,timedfs,1,in[i]) << endl;
//    }
    while (q--){
        int meow; cin >> meow;
        if (meow == 1){
            int i,w; cin >> i >> w;
            update(1,1,timedfs,edge[i].s,w);
            update(1,1,timedfs,edge[i].e,-w);
        }
        else{
            int u,v;
            cin >> u >> v;
            int lca = LCA(u,v);
            cout << get(1,1,timedfs,1,in[u])+get(1,1,timedfs,1,in[v])-2*get(1,1,timedfs,1,in[lca]) << endl;
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
