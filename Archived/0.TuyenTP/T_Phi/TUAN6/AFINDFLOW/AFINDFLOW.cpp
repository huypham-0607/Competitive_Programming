/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1000;
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
int conv(char c){
    if (c == 'S') return 1;
    else if (c == 'T') return 17;
    else return c-'A' +2;
}

vector<int> parent(N,0);
int cap[N][N];
vector<int> adj[N];

int FindFlow(vector<int> &parent){
    queue<pii> q;
    for (int i=1; i<=n; i++){
        parent[i] = 0;
    }
    parent[1] = -1;
    q.push({1,LLINF});
    while (!q.empty()){
        int u = q.front().fi;
        int mx = q.front().se;
        q.pop();

        if (u == n) return mx;

        for (auto v:adj[u]){
            if (!parent[v] && cap[u][v]){
                parent[v] = u;
                q.push({v,min(mx,cap[u][v])});
            }
        }
    }
    return 0;
}

int MaxFlow(){
    int res = 0;
    int val;
    while ((val = FindFlow(parent))){
        res+=val;
//        cerr << res << endl;
        int u = n;
        while (u!=1){
            int v = parent[u];
            cap[v][u]-=val;
            cap[u][v]+=val;
            u = v;
        }
    }
    return res;
}

/*Solution*/
void solve(){
    n = 17;
    cin >> m;
    for (int i=1; i<=m; i++){
        char c;
        int u,v,w;
        cin >> c;
        u = conv(c);
        cin >> c;
        v = conv(c);
        cin >> w;
        cap[u][v] += w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
//    cin >> n >> m;
//    for (int i=1; i<=m; i++){
//        int u,v,w;
//        cin >> u >> v >> w;
//        cap[u][v] += w;
//        adj[u].push_back(v);
//        adj[v].push_back(u);
//    }
    cout << MaxFlow() << endl;
}

/*Driver Code*/
signed main(){
//    freopen("AFINDFLOW.inp","r",stdin);
//    freopen("AFINDFLOW.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
