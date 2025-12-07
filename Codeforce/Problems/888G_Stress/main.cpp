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
int n;
int a[N];
vector<piii> edge;

//DSU
int parent[N];

int Find(int x){
    return (x == parent[x])? x : parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    int u = Find(x);
    int v = Find(y);
    if (u!=v) parent[v] = u;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        parent[i] = i;
    }
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            edge.push_back({(a[i]^a[j]),{i,j}});
        }
    }

    sort(edge.begin(),edge.end());

    int ans = 0;

    for (auto in:edge){
        int w = in.fi;
        int u = in.se.fi;
        int v = in.se.se;

        if (Find(u)!=Find(v)){
            ans+=w;
            cout << a[u] << " " << a[v] << " " << w << endl;
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

