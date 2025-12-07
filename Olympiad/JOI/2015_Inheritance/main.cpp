/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piiii pair<pii,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e3+10;
const int M = 3e5+10;
const int K = 1e4+10;
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
int ans[M];
vector<piiii> edge;

//DSU
int parent[K][N];

int Find(int x, int l){
    return (x==parent[l][x])? x : parent[l][x] = Find(parent[l][x],l);
}

bool Same(int u, int v, int l){
    return (Find(u,l) == Find(v,l));
}

void Union(int u, int v, int l){
    if (!Same(u,v,l)){
        int x = Find(u,l);
        int y = Find(v,l);
        if (x > y) swap(x,y);
        parent[l][y] = x;
    }
}

int BinSearch(int u, int v){
    int res = 0;
    int l = 1;
    int r = k;
    while (l<=r){
        int mid = (l+r)/2;
        if (Same(u,v,mid)){
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> n >> m >> k;
    for (int i=1; i<=k; i++){
        for (int j=1; j<=n; j++){
            parent[i][j] = j;
        }
    }
    for (int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge.push_back({{w,i},{u,v}});
    }
    sort(edge.begin(),edge.end(),greater<piiii>());
    for (auto in:edge){
        int w = in.fi.fi;
        int idx = in.fi.se;
        int u = in.se.fi;
        int v = in.se.se;

        int level = BinSearch(u,v);
        if (level!=k){
            ans[idx] = level+1;
            Union(u,v,level+1);
        }
        else ans[idx] = 0;
    }
    for (int i=1; i<=m; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
