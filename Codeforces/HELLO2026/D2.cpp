/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "D1"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
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

int n,mxsz;
int mxdepth;
vector<int> adj[N];
int idxval[N];
int lb[N],rb[N];
int depth[N],cntd[N];
vector<int> lst[N];
vector<int> ans[N];

void DFSdepth(int u, int p){
    depth[u] = depth[p]+1;
    mxdepth = max(mxdepth,depth[u]);
    idxval[N] = cntd[depth[u]];
    lst[depth[u]].push_back(u);
    lb[u] = INF;
    rb[u] = -1;
    cntd[depth[u]]++;
    for (auto v:adj[u]){
        if (v==p) continue;
        DFSdepth(v,u);
        lb[u] = min(lb[u],idxval[v]);
        rb[u] = max(rb[u],idxval[v]);
    }
}

void DFSvalidate(int u, int p) {
    int cnt=0;
    for (auto v:adj[u]){
        if (v==p) continue;
        DFSvalidate(v,u);
        ++cnt;
    }
    if (cnt+1 > mxsz) mxsz = cnt+1;
}

void solve(){
    cin >> n;
    mxdepth = 0;
    for (int i=0; i<=n; i++){
        adj[i].clear();
        depth[i] = 0;
        cntd[i] = 0;
        ans[i].clear();
        lst[i].clear();
        idxval[i] = 0;
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFSdepth(1,0);
    mxsz = 0;
    for (int i=1; i<=n; i++){
        mxsz = max(mxsz,cntd[i]);
    }
    DFSvalidate(1,0);

    vector<int> order;
    for (int i=0; i<mxsz; i++){
        order.push_back(i);
    }
    for (int i=0; i<cntd[mxdepth]; i++){
        ans[i].push_back(lst[mxdepth][i]);
    }

    vector<int> neword;
    vector<int> pos;

    for (int d = mxdepth-1; d>0; d--){
        // cout << d << endl;
        neword.clear();
        pos.resize(cntd[d]);
        int space = min(mxsz,max(cntd[d],cntd[d+1])+1);
        // cout << space << endl;
        int pivot = 0;

        int intercnt = 0;
        for (int i=0; i<lst[d].size(); i++){
            int u = lst[d][i];
            // cout << u << " " << lb[u] << " " << rb[u] << endl;
            if (rb[u]!=-1) {
                if (intercnt==0) {
                    pos[i] = order[space-1];
                    ans[pos[i]].push_back(u);
                }
                else {
                    pos[i] = order[pivot];
                    ans[pos[i]].push_back(u);
                    ++pivot;
                }
                intercnt++;
            }
        }
        for (int i=0; i<lst[d].size(); i++){
            int u = lst[d][i];
            if (rb[u] == -1) {
                pos[i] = order[pivot];
                ans[pos[i]].push_back(u);
                ++pivot;
            }
        }
        
        for (int i=0; i<lst[d].size(); i++){
            int u = lst[d][i];
            neword.push_back(pos[i]);
        }
        while (pivot!=space-1) {
            neword.push_back(order[pivot]);
            ++pivot;
        }

        for (int i=0; i<space; i++){
            order[i] = neword[i];
        }        
        // for (int i=0; i<space; i++){
        //     cout << neword[i] << " ";
        // }
        // cout << endl;
        // for (int i=0; i<mxsz; i++){
        //     cout << order[i] << " ";
        // }
        // cout << endl;
    }
    cout << mxsz << endl;
    for (int i=0; i<mxsz; i++){
        cout << ans[i].size() << " ";
        for (auto x:ans[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    // cout << endl;
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
        // cout << "Test " << testCount << endl;
        solve();
    }

    return 0;
}

