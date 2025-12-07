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

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,k;

//DSU

int parent[N];
int Find(int x){
    return (parent[x]==x)? x : parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    int u = Find(x);
    int v = Find(y);
    if (u!=v) parent[v] = u;
}

/*Solution*/
void solve(){
    cin >> n >> m >> k;
    int u,v;
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
    for (int i=1; i<=m; i++){
        cin >> u >> v;
        Union(u,v);
    }
    while (k--){
        cin >> u >> v;
        cout << (Find(u)==Find(v))<< endl;
    }
}

/*Driver Code*/
signed main(){
    freopen("LVO.inp","r",stdin);
    freopen("LVO.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
