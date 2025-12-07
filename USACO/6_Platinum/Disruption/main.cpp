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
const int N = 5e4+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;
const int LG = 16;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int Ans[N];
int n,q,timedfs = 0;
int up[N][LG+1];
int tin[N],tout[N];
vector<pii> a[N];

//Binary Lifitng

void PreCalc(int u, int p){
    tin[u] = ++timedfs;

    up[u][0] = p;
    for (int lg=1; lg<=LG; lg++){
        up[u][lg] = up[up[u][lg-1]][lg-1];
    }

    for (auto in:a[u]){
        int v = in.fi;
        if (v == p) continue;
        PreCalc(v,u);
    }

    tout[u] = ++timedfs;
}

bool IsAnc(int u, int v){
    return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

int FindLCA(int u, int v){
    if (IsAnc(u,v)) return u;
    if (IsAnc(v,u)) return v;
    for (int lg = LG; lg>=0; lg--){
        int x = up[u][lg];
        if (!IsAnc(x,v)) u = x;
    }
    return up[u][0];
}

//DFS
int Index[N];
bool Active[N];
int Val[N];
vector<int> Add[N],Del[N];

priority_queue<pii,vector<pii>,greater<pii>>* DFS(int u, int p){
    priority_queue<pii,vector<pii>,greater<pii>> *pq = new priority_queue<pii,vector<pii>,greater<pii>>;
    for (auto in:a[u]){
        int v = in.fi;
        if (v == p) continue;
        Index[v] = in.se;
        priority_queue<pii,vector<pii>,greater<pii>>* pq2 = DFS(v,u);
        if (pq2->size() > pq->size()) swap(*pq,*pq2);
        while (!pq2->empty()){
            pq->push(pq2->top());
            pq2->pop();
        }
        delete pq2;
    }
    for (auto idx:Add[u]){
        Active[idx] = true;
        pq->push({Val[idx],idx});
    }
    for (auto idx:Del[u]){
        Active[idx] = false;
    }
    while (!pq->empty() && !Active[pq->top().se]) pq->pop();
    if (pq->empty()){
        Ans[Index[u]] = -1;
    }
    else{
        Ans[Index[u]] = pq->top().fi;
    }
    return pq;
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back({v,i});
        a[v].push_back({u,i});
    }
    tin[0] = 0;
    tout[0] = INF;
    PreCalc(1,0);

    for (int i=1; i<=q; i++){
        int u,v,val;
        cin >> u >> v >> val;
        int lca = FindLCA(u,v);
//        cout << u << " " << v << " " << lca << endl;
        Add[u].push_back(i);
        Add[v].push_back(i);
        Del[lca].push_back(i);
        Val[i] = val;
    }

    DFS(1,0);
    for (int i=1; i<n; i++){
        cout << Ans[i] << endl;
    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << "{" << i << "}" << endl;
//        for (auto idx:Add[i]) cout << idx << " ";
//        cout << endl;
//        for (auto idx:Del[i]) cout << idx << " ";
//        cout << endl << endl;
//    }
}

/*Driver Code*/
signed main(){
//    freopen("disrupt.in","r",stdin);
//    freopen("disrupt.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
