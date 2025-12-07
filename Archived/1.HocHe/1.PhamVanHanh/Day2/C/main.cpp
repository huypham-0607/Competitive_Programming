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
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;
const int LG = 19;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,q;
vector<pii> v;
map<ll,int> mp;
int nxt[N*2];
vector<int> adj[N*2];
int up[LG][N*2];

void DFS(int u, int p){
//    cout << u << " " << p << endl;
    up[0][u] = p;
    for (int lg=1; lg<LG; lg++){
        up[lg][u] = up[lg-1][up[lg-1][u]];
    }

    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u);
    }
}

int Lift(int u, int v){
    int res = 0;
    for (int lg=LG-1; lg>=0; lg--){
//        cout << up[lg][u] << " " << v << endl;
        if (up[lg][u]<=v){
            u = up[lg][u];
            res^=(1<<lg);
        }
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> n >> m >> q;
    v.push_back({0,0});
    for (int i=1; i<=n; i++){
        int u,w;
        cin >> u >> w;
        v.push_back({u,w});
    }
    for (int i=1; i<=m; i++){
        int u,w;
        cin >> u >> w;
        v.push_back({u,-w});
    }
    sort(v.begin(),v.end());

    mp[0] = 0;
    ll cur = 0;
    int pos = 1;
    n = n+m;
    for (int i=1; i<(int)v.size(); i++){
        cur+=v[i].se;
        if (mp.find(cur)!=mp.end()){
            int rawr = mp[cur];
            while (pos<=rawr+1){
                nxt[pos] = i+1;
                adj[i+1].push_back(pos);
                ++pos;
            }
        }
        mp[cur] = i;
    }
    while (pos<=n+1){
        nxt[pos] = n+2;
        adj[n+2].push_back(pos);
        ++pos;
    }
    DFS(n+2,n+2);

//    for (int i=1; i<=n+2; i++){
//        cout << nxt[i] << endl;
//    }

    int l,r;
    while (q--){
        cin >> l >> r;
        int x = upper_bound(v.begin(),v.end(),make_pair(l,-INF))-v.begin();
        int y = upper_bound(v.begin(),v.end(),make_pair(r,INF))-v.begin()-1;

//        cout << "gay " << x << " " << y << endl;

        cout << Lift(x,y+1) << endl;
    }

//    for (int i=1; i<=n+2; i++){
//        for (int lg=0; lg<LG; lg++){
//            cout << up[lg][i] << " ";
//        }
//        cout << endl;
//    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cerr << "Dont leave ur computer on like this again :DDD" << endl;
    cerr << "- Ly Tuan Kiet" << endl;

    TestCases(0);

    return 0;
}
