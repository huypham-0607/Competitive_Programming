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
const int N = 500+10;
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
int a[N];
vector<piii> edge;
int parent[N];

//DSU
int Find(int x){
    return (parent[x] == x)? x : parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    int u = Find(x);
    int v = Find(y);
    if (u!=v){
        parent[v] = u;
    }
}

int binpow(int x, int y){
    x%=m;
    int res = 1;
    while (y>0){
        if (y&1){
            res = res*x%m;
        }
        x = x*x%m;
        y = (y>>1);
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        parent[i] = i;
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            edge.push_back({(binpow(a[i],a[j]) + binpow(a[j],a[i]))%m,{i,j}});
        }
    }
    int ans = 0;
//    cout << (binpow(2,2) + binpow(2,2))%m << endl;
    sort(edge.begin(),edge.end(),greater<piii>());
    for (auto in:edge){
        int w = in.fi;
        int u = in.se.fi;
        int v = in.se.se;
//        cout << u << " " << v << " " << w << endl;

        if (Find(u)!=Find(v)){
            ans+=w;
            Union(u,v);
        }
    }
    cout << ans;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

