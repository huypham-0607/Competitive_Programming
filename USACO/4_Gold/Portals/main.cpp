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
int n;
vector<piii> edge;

//DSU
int parent[N];

void Init(){
    for (int i=1; i<=n*2; i++){
        parent[i] = i;
    }
}

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
    cin >> n;
    Init();
    for (int i=1; i<=n; i++){
        int w,u1,v1,u2,v2;
        cin >> w >> u1 >> v1 >> u2 >> v2;
        Union(u1,v1);
        Union(u2,v2);
        edge.push_back({w,{u1,u2}});
    }
    sort(edge.begin(),edge.end());
    int ans = 0;
    for (auto in:edge){
        int w = in.fi;
        int u = in.se.fi;
        int v = in.se.se;

        if (Find(u) != Find(v)){
            ans+=w;
            Union(u,v);
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
