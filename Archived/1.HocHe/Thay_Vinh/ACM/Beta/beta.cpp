/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
vector<piii> edge;
int parent[N];

//DSU
int Find(int x){
    return (parent[x] == x)? x : parent[x] = Find(parent[x]);
}

void Union(int u, int v){
    int x = Find(u);
    int y = Find(v);
    if (x!=y){
        parent[y] = x;
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        edge.push_back({w,{u,v}});
    }

    int ans=0, cnt=1;

    sort(edge.begin(), edge.end(), greater<piii>());
    for (auto in:edge){
        int w = in.fi;
        int u = in.se.fi;
        int v = in.se.se;

        if (Find(u)!=Find(v)){
            ans+=w;
            ++cnt;
            Union(u,v);
        }
    }

    if (cnt<n) cout << "Impossible" << endl;
    else cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("BETA.inp","r",stdin);
    freopen("BETA.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
