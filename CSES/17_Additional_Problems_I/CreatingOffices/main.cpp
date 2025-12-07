/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e8+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,d,lim;
vector<int> adj[N];
bool marked[N];

piiii DFS(int u, int p){
    int low = 0, high = INF, id = u;
    int res = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        piiii in = DFS(v,u);
        res+=in.fi.fi;
        if (low<in.se.fi){
            low = in.se.fi;
            id = in.se.se;
        }
        high = min(high,in.fi.se);
    }
    if (low+high<d){
        low = -INF;
        id = 0;
    }
    ++high;
    if (high == d){
        high = INF;
    }
    ++low;
    if (low==lim){
        marked[id] = 1;
        high = min(low,high);
        low = -INF;
        id = 0;
        ++res;
    }
    return make_pair(make_pair(res,high),make_pair(low,id));
}

/*Solution*/
void solve(){
    cin >> n >> d;
    lim = (d+1)/2;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    piiii res = DFS(1,0);
    int ans = res.fi.fi;
    if (res.se.fi>=0){
        ++ans;
        marked[res.se.se] = 1;
    }
    cout << ans << endl;
    for (int i=1; i<=n; i++){
        if (marked[i]) cout << i << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
