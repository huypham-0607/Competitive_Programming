/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "G2"

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

const int N = 3e5+10;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

namespace Comb {
    using ll = long long;

    const int N = 3e5;
    const int MD = 998244353;
    const int LG = 30;

    int invFac[N+1];
    int fac[N+1];

    int binPow(int a, int b){
        ll res = 1;
        for (int lg = LG-1; lg>=0; lg--){
            res = res*res%MD;
            if ((1LL<<lg)&b) res = res*a%MD;
        }
        return res;
    }

    int invMod(int x, int MD){
        return binPow(x,MD-2);
    }

    int nCk(int n, int k){
        return 1LL*fac[n]*invFac[k]%MD*invFac[n-k]%MD;
    }

    struct Init {
        Init() {
            fac[0] = 1;
            invFac[0] = 1;
            for (int i = 1; i <= N; i++){
                fac[i] = (1LL*fac[i-1]*i%MD);
                invFac[i] = invMod(fac[i],MD);
            }
        }
    } _init;
}

int divi(int a, int b) {
    return a*Comb::invMod(b,MD)%MD;
}

struct Data {
    int sz,pre,total,mul,anchor;
    vector<int> used;
    vector<int> val;

    Data (int _sz, int _anchor) {
        sz = _sz;
        anchor = _anchor;
        used.resize(sz,1);
        val.resize(sz,0);
        total = 0;
        pre = 0;
        mul = 1;
    }

    void pop(int i) {
        int multiplier = divi(mul,used[i]);
        val[i] = val[i]*multiplier%MD;
        used[i] = mul;
    }

    void updatePre(int d, int k) {
        int pos = d - anchor;
        if (pos+k < sz){
            pop(pos+k);
            pre = (pre-val[pos+k]+MD)%MD;
        }
    }

    void scale(int multi) {
        total = total*multi%MD;
        pre = pre*multi%MD;
        mul = mul*multi%MD;
    }

    void merge(Data* other, int multi) {
        int pos = other->anchor - anchor;
        // cerr << pos << " " << sz << endl;
        for (int i=0; i<other->sz; i++) {
            other->pop(i);
            pop(pos+i);
            
            val[pos+i] = (val[pos+i]+other->val[i]*multi%MD)%MD;
        }
        total = (total+other->total*multi%MD)%MD;
        pre = (pre+other->pre*multi%MD)%MD;
    }
};

int n,k;
int depth[N], mxdepth[N];
vector<int> adj[N];

void dfs(int u, int p){
    // cout << u << endl;
    mxdepth[u] = depth[u] = depth[p]+1;
    for (auto v:adj[u]){
        if (v==p) continue;
        dfs(v,u);
        mxdepth[u] = max(mxdepth[u],mxdepth[v]);
    }
}

Data* dfsCalc(int u, int p, int sz, int anchor){
    // cout  << u << endl;
    int heavy = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        if (mxdepth[heavy] < mxdepth[v]) heavy = v;
    }

    Data* cur;

    if (!heavy) {
        cur = new Data(sz,anchor);
        cur->val[sz-1] = 1;
        cur->total = 1;
        cur->pre = 1;
        // cout << "Done: " << u << endl;
        // cout << cur->total << " " << cur->pre << endl;
        return cur; 
    }
    else {
        cur = dfsCalc(heavy,u,sz,anchor);
        cur->updatePre(depth[u],k);
    }

    vector<Data*> child;
    vector<int> pref;
    vector<int> suf;

    for (auto v:adj[u]) {
        if (v==p || v==heavy) continue;
        Data* tmp = dfsCalc(v,u,mxdepth[v]-depth[u],depth[v]);
        tmp->updatePre(depth[u],k);
        child.push_back(tmp);
        pref.push_back(tmp->pre);
        suf.push_back(tmp->pre);
    }

    for (int i=1; i<pref.size(); i++){
        pref[i] = pref[i]*pref[i-1]%MD;
    }
    for (int i=suf.size()-2; i>=0; i--){
        suf[i] = suf[i]*suf[i+1]%MD;
    }

    int ccnt = pref.size();

    // cout << "About to Merge: " << u << endl;

    int spre = cur->pre;

    if (ccnt!=0) cur->scale(pref[ccnt-1]*Comb::fac[ccnt]%MD);
    
    for (int i=0; i<child.size(); i++){
        int multi = spre*Comb::fac[ccnt]%MD;
        if (i!=0) multi = multi*pref[i-1]%MD;
        if (i!=ccnt-1) multi = multi*suf[i+1]%MD;
        cur->merge(child[i],multi);
        // cout << multi << " " << cur->total << endl;
    }

    // cout << "Done: " << u << endl;
    // cout << cur->total  << " " << cur->pre << endl;
    return cur;
}

void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    for (int u=2; u<=n; u++){
        int v; cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for (int i=1; i<=n; i++){
    //     for (auto x: adj[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    dfs(1,0);
    Data* cur = dfsCalc(1,0,mxdepth[1],depth[1]);
    cout << cur->total << endl;
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

