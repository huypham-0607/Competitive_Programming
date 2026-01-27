/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "2189F"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m,cost1,cost2;
int a[N];
int f[N],g[N];
int sf[N],sg[N];
int fid[N],gid[N];
vector<int> adj[N];
vector<int> nen;

struct LazySegmentTree{
    int n;
    vector<int> IT;
    vector<int> lazy;

    void applyAdd(int idx, int val) {
        IT[idx] += val;
        lazy[idx] += val;
    }

    void propagate(int idx){
        applyAdd(idx*2,lazy[idx]);
        applyAdd(idx*2+1,lazy[idx]);
        lazy[idx] = 0;
    }

    void comb(int& i, int& l, int& r){
        i = min(l,r);
    }

    void build(int idx, int l, int r, vector<int>& a){
        if (l==r){
            IT[idx] = a[l-1]*cost1;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid,a);
        build(idx*2+1,mid+1,r,a);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void init(int _n, vector<int>& a) {
        n = _n;
        IT.clear();
        lazy.clear();
        IT.resize(n*4+10, 0);
        lazy.resize(n*4+10, 0);
        build(1,1,n,a);
    }

    void update(int idx, int l, int r, int x, int y, int val){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            applyAdd(idx,val*cost2);            
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val);
        update(idx*2+1,mid+1,r,x,y,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    int getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return LLINF;
        if (x <= l && r <= y){
            return IT[idx];
        }

        propagate(idx);

        int mid = (l+r)/2;
        return min(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));
    }
} IT;

void calcf(int u, int p) {
    f[u] = a[u];
    int cnt = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        calcf(v,u);
        if (f[v]) ++cnt;
        f[u]+=f[v];
    }
    sf[u] = ((a[u]||(cnt>1))?1:0);
}

void calcg(int u, int p) {
    vector<int> pref,suf,prefs,sufs;
    for (auto v:adj[u]) {
        if (v==p) continue;
        pref.push_back(f[v]);
        suf.push_back(f[v]);
        prefs.push_back(((f[v])?1:0));
        sufs.push_back(((f[v])?1:0));
    }
    for (int i=1; i<pref.size(); i++){
        pref[i] += pref[i-1];
        prefs[i] += prefs[i-1];
    }
    for (int i=suf.size()-2; i>=0; i--){
        suf[i] += suf[i+1];
        sufs[i] += sufs[i+1];
    }

    int id = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        int val = g[u]+a[u];
        int cnt = ((g[u])?1:0);
        if (id!=0) {
            val+=pref[id-1];
            cnt+=prefs[id-1];
        }
        if (id!=suf.size()-1) {
            val+=suf[id+1];
            cnt+=sufs[id+1];
        }
        g[v] = val;
        sg[v] = ((a[u]||(cnt>1))?1:0);
        calcg(v,u);

        ++id;
    }
}

int ans,org,curvalid;

void calc(int u, int p){
    int tmp = IT.getVal(1,1,m,1,m);
    ans = min(ans,curvalid*cost2+IT.getVal(1,1,m,1,m));
    // cout << curvalid << endl;
    // cout << u << " " << ans << " " << tmp << endl;
    // for (int i=1; i<=m; i++){
    //     int tmpval = IT.getVal(1,1,m,i,i);
    //     tmpval-=nen[i-1]*cost1;
    //     cout << tmpval << " ";
    // }
    // cout << endl;
    for (auto v:adj[u]) {
        if (v==p) continue;
        if (sf[v]) {
            IT.update(1,1,m,fid[v],m,1);
            --curvalid;
        }
        if (sg[v]) {
            IT.update(1,1,m,gid[v],m,-1);
            ++curvalid;
        }
        calc(v,u);
        if (sg[v]) {
            IT.update(1,1,m,gid[v],m,1);
            --curvalid;
        }
        if (sf[v]) {
            IT.update(1,1,m,fid[v],m,-1);
            ++curvalid;
        }
    }
}

void solve(){
    cin >> n >> cost1 >> cost2;
    for (int i=1; i<=n; i++){
        a[i] = 0;
        f[i] = 0;
        g[i] = 0;
        fid[i] = 0;
        gid[i] = 0;
        adj[i].clear();
        sf[i] = 0;
        sg[i] = 0;
    }
    nen.clear();
    org = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        if (a[i]) {
            org = org+cost2;
        }
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    calcf(1,0);
    calcg(1,0);

    for (int i=1; i<=n; i++){
        nen.push_back(f[i]);
        nen.push_back(g[i]);
    }
    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());

    for (int i=1; i<=n; i++){
        fid[i] = lower_bound(all(nen),f[i]) - nen.begin()+1;
        gid[i] = lower_bound(all(nen),g[i]) - nen.begin()+1;
    }

    curvalid = 1;
    ans = org;
    IT.init(nen.size(),nen);
    m = nen.size();
    // for (auto x:nen) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // for (int i=1; i<=n; i++){
    //     cout << f[i] << " " << g[i] << endl;
    // }
    for (int i=2; i<=n; i++){
        if (sf[i]) {
            IT.update(1,1,m,fid[i],m,-1);
            ++curvalid;
        }
    }
    // for (int i=1; i<=n; i++){
    //     cout << sf[i] << " " << sg[i] << endl;
    // }
    calc(1,0);
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

