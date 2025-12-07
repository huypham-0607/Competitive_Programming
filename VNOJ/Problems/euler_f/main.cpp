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
int n,k,m,elt_size=0,elth_size=0;
int h[N],tin[N],tout[N],color[N];
pii elt[N*2], elth[N*2];
set<pii> st[N];
vector<int> a[N];

//SEGGS
pii IT[N*8];

void Build(int idx, int l, int r){
    if (l==r){
        IT[idx] = elth[l];
        return;
    }
    int mid = (l+r)/2;
    Build(idx*2,l,mid);
    Build(idx*2+1,mid+1,r);
    IT[idx] = min(IT[idx*2],IT[idx*2+1]);
}

pii Query(int idx, int l, int r, int x, int y){
    if (l>y||r<x) return {INF,INF};
    if (x<=l&&r<=y) return IT[idx];
    int mid = (l+r)/2;
    return min(Query(idx*2,l,mid,x,y),Query(idx*2+1,mid+1,r,x,y));
}

int GetLCA(int u, int v){
    if (tin[u]>tin[v]) swap(u,v);
    pii tmp = Query(1,1,elth_size,tin[u],tin[v]);
    return tmp.se;
}

void DFS(int u, int p){
    h[u] = h[p]+1;
    tin[u] = ++elt_size;
    elth[++elth_size] = {h[u],u};
    elt[elt_size] = {color[u],u};

    for (auto v:a[u]){
        if (v==p) continue;
        DFS(v,u);
        elth[++elth_size] = {h[u],u};

    }

    tout[u] = ++elt_size;
    elt[elt_size] = {color[u],u};
}

//FW
int BIT[N*2];

void UpdateBIT(int pos, int val){
    while (pos<=elt_size){
        BIT[pos]+=val;
        pos += (pos&(-pos));
    }
}

int Get(int pos){
    int res = 0;
    while (pos>0){
        res+=BIT[pos];
        pos -= (pos&(-pos));
    }
    return res;
}

int GetVal(int l, int r){
    return (Get(r)-Get(l-1));
}

void Add_Link(int l, int r){
    if (l==0) return;
    if (r==INF) return;
    int lca = GetLCA(l,r);
    UpdateBIT(tout[lca],-1);
}

void Del_Link(int l, int r){
    if (l==0) return;
    if (r==INF) return;
    int lca = GetLCA(l,r);
    UpdateBIT(tout[lca],1);
}

int cnt = 0;

void DFS2(int u, int p){
//    cout << u << endl;
    for (auto v:a[u]){
        if (v==p) continue;
        DFS2(v,u);
    }
    auto it = prev(st[color[u]].lower_bound({tout[u],u}));
    Add_Link((*it).se,u);
    st[color[u]].insert({tout[u],u});
    UpdateBIT(tout[u],1);
}

/*Solution*/
void solve(){
    cin >> n >> k >> m;
    for (int i=1; i<=n; i++){
        cin >> color[i];
    }
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1,0);
//    cout << "rawr" << endl;
    Build(1,1,elth_size);
//    cout << "rawr" << endl;
    for (int i=1; i<=k; i++){
        st[i].insert({0,0});
        st[i].insert({INF,INF});
    }
    DFS2(1,0);
//    cout << "rawr" << endl;
//    for (int i=1; i<=elt_size; i++){
//        cout << GetVal(i,i) << endl;
//    }
    while (m--){
        int x,u,v;
        cin >> x;
        if (x==2){
            cin >> u;
            cout << GetVal(tin[u],tout[u]) << endl;
        }
        else{
            cin >> u >> v;
            int clr = color[u];
            auto it = st[clr].lower_bound({tout[u],u});
            Del_Link((*prev(it)).se,u);
            Del_Link(u,(*next(it)).se);
            Add_Link((*prev(it)).se,(*next(it)).se);
            st[clr].erase({tout[u],u});

            st[v].insert({tout[u],u});
            it = st[v].lower_bound({tout[u],u});
            Del_Link((*prev(it)).se,(*next(it)).se);
            Add_Link((*prev(it)).se,u);
            Add_Link(u,(*next(it)).se);
            color[u] = v;
//            for (int i=1; i<=elt_size; i++){
//                cout << GetVal(i,i) << endl;
//            }
        }
    }
//    for (int i=1; i<=n; i++){
//        cout << tin[i] << " " << tout[i] << endl;
//    }
//    for (int i=1; i<=elt_size; i++){
//        cout << GetVal(i,i) << endl;
//    }
//    for (int i=1; i<=elth_size; i++){
//        cout << Query(1,1,elth_size,i,i).fi << " " << Query(1,1,elth_size,i,i).se << endl;
//    }
//    cout << Query(1,1,elth_size,tin[2],tin[7]).fi << endl;
//    cout << GetLCA(1,7) << endl;
//    cout << GetLCA(5,7) << endl;
//    cout << GetLCA(3,7) << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

