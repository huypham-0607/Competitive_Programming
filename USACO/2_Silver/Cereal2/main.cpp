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
int n,m;
vector<piii> adj[N];
int num[N];
int eid[N];
int etype[N];
bool viscow[N];
int cur = 0;
vector<

void DFS(int u, int preid){
    num[u] = ++cur;
    for (auto in:adj[u]){
        int v = in.fi;
        int tpe = in.se.fi;
        int id = in.se.se;

        if (id == preid) continue;

        if (!num[v]){
            eid[v] = id;
            etype[v] = tpe;
            viscow[id] = true;
            DFS(v,id);
        }
        else{
            if (num[v] < num[u]){
                eid[v] = id;
                etype[v] = tpe;
            }
        }
    }
}

/*Solution*/
void solve(){
    cin >> m >> n;
    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back({v,{1,i}});
        adj[v].push_back({u,{2,i}});
    }
    for (int i=1; i<=n; i++){
        if (!vis[i]) DFS(i,0);
//        for (int i=1; i<=n; i++){
//            cout << eid[i] << " ";
//        }
//        cout << endl;
    }

    deque<int> dq;

    int ans = m;

    for (int i=1; i<=n; i++){
        if (eid[i]!=0){
            if (etype[i] == 1){
                dq.push_front(eid[i]);
            }
            else{
                dq.push_back(eid[i]);
            }
//            viscow[eid[i]] = true;
            --ans;
        }
    }

    cout << ans << endl;
    while (!dq.empty()){
        cout << dq.front() << endl;
        dq.pop_front();
    }
    for (int i=1; i<=m; i++){
        if (!viscow[i]){
            cout << i << endl;
        }
    }
}

/*Driver Code*/
signed main(){
//    freopen("cereal2.inp","r",stdin);
//    freopen("cereal2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
