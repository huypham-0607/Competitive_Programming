/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 200+10;
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
int n;
int val[N];
pii pos[N];
bool vis[N];
int cnt = 0;
vector<int> adj[N];

void DFS(int u){
    ++cnt;
    vis[u] = true;
    for (auto v:adj[u]){
        if (vis[v]) continue;
        DFS(v);
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> pos[i].fi >> pos[i].se >> val[i];
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i==j) continue;
            int sus = (pos[i].fi-pos[j].fi)*(pos[i].fi-pos[j].fi) + (pos[i].se-pos[j].se)*(pos[i].se-pos[j].se);
            if (val[i]*val[i] >= sus) adj[i].push_back(j);
        }
    }

    int ans = 0;

    for (int i=1; i<=n; i++){
        cnt = 0;
        for (int j=1; j<=n; j++){
            vis[j] = 0;
        }
        DFS(i);
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
