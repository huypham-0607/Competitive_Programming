/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "E"

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

struct Fenwick{
    int n,anchor;
    vector<int> BIT;
    vector<int> cnt;

    Fenwick(int _n, int _anchor): n(_n){
        n = _n;
        anchor = _anchor;
        BIT.resize(n+10);
        cnt.resize(n+10);
    }

    void init (int _n, int val=0){
        n = _n;
        BIT.resize(n+1,0);
        cnt.resize(n+1,0);
    }

    void updateVal(int idx, int val){
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int getPointVal(int idx){
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    int getVal(int l, int r){
        return (getPointVal(r)-getPointVal(l-1));
    }

    void updateCnt(int idx, int val){
        while (idx<=n){
            cnt[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int getPointCnt(int idx){
        int res = 0;
        while (idx>0){
            res+=cnt[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    int getCnt(int l, int r){
        return (getPointCnt(r)-getPointCnt(l-1));
    }
};


int n,k;
int nxt[N];
vector<int> adj[N];
int depth[N], maxdepth[N];

void dfs(int u, int p) {
    depth[u] = depth[p]+1;
    maxdepth[u] = depth[u];
    for (auto v:adj[u]) {
        if (v==p) continue;
        dfs(v,u);
        maxdepth[u] = max(maxdepth[u],maxdepth[v]);
    }
}

int ans;

Fenwick* calc(int u, int p, int sz, int anchor) {
    int heavy = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        if (maxdepth[heavy] < maxdepth[v]) heavy = v;
    }

    Fenwick* cur;

    if (!heavy) {
        cur = new Fenwick(sz,anchor);
        cur->updateCnt(depth[u]-anchor+1,1);
        cur->updateVal(depth[u]-anchor+1,depth[u]);
        return cur;
    }
    else {
        cur = calc(heavy,u,sz,anchor);
        cur->updateCnt(depth[u]-anchor+1,1);
        cur->updateVal(depth[u]-anchor+1,depth[u]);
    }

    int udepth = depth[u]-anchor+1;

    for (auto v:adj[u]) {
        if (v==p || v==heavy) continue;
        Fenwick* tmp = calc(v,u,maxdepth[v]-depth[u],depth[v]);
        for (int i=1; i<=tmp->n; i++){
            int cnt = tmp->getCnt(i,i);
            int vdepth = (i+tmp->anchor-1)-cur->anchor+1;
            ans += (cur->getVal(1,vdepth-1)-depth[u]*cur->getCnt(1,vdepth-1))*cnt;
            ans += cur->getCnt(vdepth,cur->n)*(vdepth-udepth)*cnt;
            ans += cur->getCnt(vdepth,vdepth)*(vdepth-udepth)*cnt;
        }

        for (int i=1; i<=tmp->n; i++){
            int cnt = tmp->getCnt(i,i);
            int vdepth = (i+tmp->anchor-1)-cur->anchor+1;
            int vdepthtrue = (i+tmp->anchor-1);
            cur->updateCnt(vdepth,cnt);
            cur->updateVal(vdepth,vdepthtrue*cnt);
        }
    }

    return cur;
}

void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        nxt[i] = i+1;
        adj[i].clear();
    }
    for (int i=1; i<=k; i++){
        int u,v; cin >> u >> v;
        nxt[u] = max(nxt[u],v);
    }
    for (int u=1; u<n; u++){
        int v = nxt[u];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(n,0);
    ans = 0;

    // for (int i=1; i<=n; i++){
    //     cout << maxdepth[i] << " " << depth[i] << endl;
    // }

    calc(n,0,maxdepth[n],1);

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

