/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 3e5+10;
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
int n,m,t;
vector<piii> edges;
int a[510][510];
int ans[N];

//DSU
int parent[N];
vector<int> child[N];
int cnt[N];

void Init(){
    for (int i=0; i<n*m; i++){
        parent[i] = i;
        child[i].push_back(i);
        cnt[i] = 1;
    }
}

int Find(int x){
    return (x == parent[x])? x : parent[x] = Find(parent[x]);
}

void Union(int u, int v, int w){
    int x = Find(u);
    int y = Find(v);
    if (child[x].size() < child[y].size()) swap(x,y);
    if (x!=y){
        while ((int)child[y].size()){
            child[x].push_back(child[y].back());
            child[y].pop_back();
        }
        cnt[x]+=cnt[y];
        cnt[y] = 0;
        parent[y] = x;
        if (cnt[x]>=t){
            while ((int)child[x].size()){
                ans[child[x].back()] = w;
                child[x].pop_back();
            }
        }
    }
}

/*Solution*/
void solve(){
    cin >> n >> m >> t;
    Init();
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i!=0) edges.push_back({abs(a[i][j]-a[i-1][j]),{i*m+j,(i-1)*m+j}});
            if (i!=n-1) edges.push_back({abs(a[i][j]-a[i+1][j]),{i*m+j,(i+1)*m+j}});
            if (j!=0) edges.push_back({abs(a[i][j]-a[i][j-1]),{i*m+j,i*m+j-1}});
            if (j!=m-1) edges.push_back({abs(a[i][j]-a[i][j+1]),{i*m+j,i*m+j+1}});
        }
    }
    sort(edges.begin(),edges.end());
    for (auto in:edges){
        int w = in.fi;
        int u = in.se.fi;
        int v = in.se.se;

        Union(u,v,w);
    }
    ll res = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int x;
            cin >> x;
            if (x){
                res+=ans[i*m+j];
            }
        }
    }
    cout << res << endl;
}

/*Driver Code*/
signed main(){
//    freopen("skilevel.in","r",stdin);
//    freopen("skilevel.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
