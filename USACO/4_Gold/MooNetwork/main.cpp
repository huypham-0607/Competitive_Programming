/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
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
vector<piii> vertex;
vector<piii> edge;
pii last[11];

//DSU
int parent[N];

void Init(){
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
}

int Find(int x){
    return (x == parent[x])? x : parent[x] = Find(parent[x]);
}

void Union(int u, int v){
    if (Find(u) != Find(v)){
        int x = Find(u);
        int y = Find(v);
        parent[y] = x;
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        vertex.push_back({x,{y,i}});
    }
    sort(vertex.begin(),vertex.end());
    for (int i=0; i<=10; i++){
        last[i] = {-1,0};
    }
    for (auto in:vertex){
        int x1 = in.fi;
        int y1 = in.se.fi;
        int idx1 = in.se.se;

        for (int y2=0; y2<=10; y2++){
            if (last[y2].fi == -1) continue;

            int x2 = last[y2].fi;
            int idx2 = last[y2].se;
            edge.push_back({(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2),{idx1,idx2}});
        }
        last[y1] = {x1,idx1};
    }
    sort(edge.begin(),edge.end());
    Init();
    int ans = 0;
    for (auto in:edge){
        int w = in.fi;
        int u = in.se.fi;
        int v = in.se.se;

//        cout << w << " " << u << " " << v << endl;

        if (Find(u)!=Find(v)){
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
