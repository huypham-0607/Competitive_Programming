/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 3e5+10;
const int INF = 1e9+7;
const int LG = 20;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,k,q;
vector<piii> edge;
int parent[2*N];
vector<int> adj[2*N];
//int up[LG][2*N];
int depth[2*N];
int weight[2*N];
int tin[2*N], trace[4*N];
vector<int> euler;
int timedfs = 0;

void Init(int n){
    for (int i=1; i<=n; i++){
        parent[i] = i;
        weight[i] = -1;
    }
}

int Find(int x){
    return (x==parent[x])? x : parent[x] = Find(parent[x]);
}

void Union(int u, int v, int w){
    u = Find(u);
    v = Find(v);

    if (u!=v){
        ++n;
        parent[n] = n;
        adj[n].push_back(u);
        adj[n].push_back(v);
        weight[n] = w;
        parent[u] = parent[v] = parent[n];
    }
}


void DFS(int u, int p){
    tin[u] = ++timedfs;
    euler.push_back(u);
    trace[tin[u]] = u;
//    up[0][u] = p;
    depth[u] = depth[p]+1;

//    for (int lg=1; lg<LG; lg++){
//        int v = up[lg-1][u];
//        up[lg][u] = up[lg-1][v];
//    }

    for (auto v: adj[u]){
        DFS(v,u);
        ++timedfs;
        euler.push_back(u);
    }
}

int Seg[8*N];

int Saigonriver(int u, int v){
//    cout << u << " " << v <<endl;
    if (u == 0) return v;
    if (v == 0) return u;
    if (depth[u] < depth[v]) return u;
    else return v;
}

void BuildSeg(){
    for (int i=0; i<(int)euler.size(); i++){
        Seg[(int)euler.size()+i] = euler[i];
    }
    for (int i=(int)euler.size()-1; i>0; i--){
        Seg[i] = Saigonriver(Seg[i<<1],Seg[i<<1|1]);
    }
}

int QuerySeg(int l, int r){
    int res = 0;
    for (l+=(int)euler.size(), r+=(int)euler.size(); l<r; l>>=1, r>>=1){
        if (l&1) res = Saigonriver(res,Seg[l++]);
        if (r&1) res = Saigonriver(res,Seg[--r]);
    }
    return res;
}

//int bin_lift(int u, int x){
//    for (int lg=LG-1; lg>=0; lg--){
//        if ((1<<lg)&x){
//            u = up[lg][u];
//        }
//    }
//    return u;
//}
//
//int find_lca(int u, int v){
//    if (depth[u]>depth[v]) swap(u,v);
//    v = bin_lift(v,depth[v] - depth[u]);
//    if (u==v) return u;
//
//    for (int lg=LG-1; lg>=0; lg--){
//        if (up[lg][u] != up[lg][v]){
//            u = up[lg][u];
//            v = up[lg][v];
//        }
//    }
//
//    return up[0][u];
//}

pii ST[4*N];
int lazy[4*N];
pii precalc[4*N];

pii Comb(pii u, pii v){
    return make_pair(min(u.fi,v.fi),max(u.se,v.se));
}

void Build(int idx, int l, int r){
    if (l==r){
        precalc[idx].fi = precalc[idx].se = tin[l];
        ST[idx].fi = INF;
        ST[idx].se = 0;
//        cout << l << " " << r << " " << pre_lca[idx] << endl;
        return;
    }

    int mid = (l+r)/2;
    Build(idx*2,l,mid); Build(idx*2+1,mid+1,r);
    precalc[idx] = Comb(precalc[idx*2],precalc[idx*2+1]);
    ST[idx].fi = INF;
    ST[idx].se = 0;
    //    cout << l << " " << r << " " << pre_lca[idx] << endl;
}

void down(int idx){
    if (lazy[idx] != 0){
        if (lazy[idx] == 1){
            ST[idx*2] = precalc[idx*2];
            ST[idx*2+1] = precalc[idx*2+1];
        }
        if (lazy[idx] == 2){
            ST[idx*2].fi = ST[idx*2+1].fi = INF;
            ST[idx*2].se = ST[idx*2+1].se = 0;
        }

        lazy[idx*2] = lazy[idx*2+1] = lazy[idx];
        lazy[idx] = 0;
    }
}

void Update(int idx, int l, int r, int x, int y, int val){
    if (r < x || y < l) return;
    if (x <= l && r <= y){
        if (val == 1){
            ST[idx] = precalc[idx];
        }
        else{
            ST[idx].fi = INF;
            ST[idx].se = 0;
        }
        lazy[idx] = val;
        return;
    }

    down(idx);

    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,y,val); Update(idx*2+1,mid+1,r,x,y,val);
    ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
}

pii Get(){
    return ST[1];
}

/*Solution*/
void solve(){
    cin >> k >> q;
    n = k;

    Init(n);

    for (int i=1; i<k; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge.push_back({w,{u,v}});
    }

    sort(all(edge));

    for (auto in:edge){
        int w = in.fi;
        int u = in.se.fi;
        int v = in.se.se;

        if (Find(u)!=Find(v)){
            Union(u,v,w);
        }
    }

    DFS(n,0);

//    for (int i=1; i<=n; i++){
//        cout << i << ": ";
//        for (auto x: adj[i]){
//            cout << x << " ";
//        }
//        cout << endl;
//    }
//
//    for (int i=1; i<=n; i++){
//        cout << i << ": ";
//        for (int lg=0; lg<LG; lg++){
//            cout << up[lg][i] << " ";
//        }
//        cout << endl;
//    }

    Build(1,1,k);
//    if (k<=100000){
        BuildSeg();
//    }
//    for (int i=0; i<(int)euler.size(); i++){
//        cout << euler[i] << endl;
//    }
//    cout << euler.size() << endl;

//    if (k>100000){
//        cout << (int)euler.size() << endl;
//        cout << timedfs << endl;
//    }

    for (int i=1; i<=q; i++){
        int id; cin >> id;
        if (id == 3){
            int x; cin >> x;
//            if (k > 100000){
//                continue;
//            }
            pii in = Get();
            if (in.fi == INF){
//                cout << "Lmao" << endl;
                cout << -1 << endl;
                continue;
            }
////            cout << "Trace: " << trace[in.fi] << " " << trace[in.se] << endl;
//            int ans = max(weight[find_lca(x,trace[in.fi])], weight[find_lca(x,trace[in.se])]);
//            cout << ans << endl;
//            pii in = Get();
            in.fi = trace[in.fi];
            in.se = trace[in.se];
            if (tin[in.fi] > tin[in.se]) swap(in.fi,in.se);
            int u = QuerySeg(tin[in.fi]-1,tin[in.se]);
//            cout << in.fi << " " << in.se << " " << u << endl;
//            int ans = max(weight[QuerySeg(tin[x]-1,tin[in.fi])], weight[find_lca(tin[x]-1,tin[in.se])]);
            if (tin[u] < tin[x]){
                cout << weight[QuerySeg(tin[u]-1,tin[x])] << endl;
            }
            else{
                cout << weight[QuerySeg(tin[x]-1,tin[u])] << endl;
            }
//            cout << ans << endl;
        }
        else{
            int l,r; cin >> l >> r;
//            if (k>100000){
//                continue;
//            }
            Update(1,1,k,l,r,id);
        }
    }
//    cout << find_lca(6,4);
}

/*Driver Code*/
signed main(){
//    freopen("1628E.inp","r",stdin);
//    freopen("1628E.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
