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
const int N = 1e5+10;
const int M = 1e7+10;
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
vector<int> a;
vector<piii> edge;
int vis[M];
int nxt[M];

//DSU
int parent[N];

int Find(int x){
    return (x == parent[x]) ? x : parent[x] = Find(parent[x]);
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
    int mx = 0;
    int mn = INF;
    int cnt = 0;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        if (!vis[x]){
            ++cnt;
            vis[x] = cnt;;
            a.push_back(x);
            mx = max(mx,x);
            mn = min(mn,x);
        }
    }
    sort(a.begin(),a.end());
    int rawr = INF;
    for (int i=mx+1; i>=1; i--){
        if (vis[i]) rawr = i;
        nxt[i] = rawr;
    }
    for (int idx = 0; idx<(int)a.size(); idx++){
        int x = a[idx];
        for (int i=x; i<=mx; i+=x){
            if (i == x){
                if (nxt[i+1]<i+x){
                    edge.push_back({nxt[i+1]-i,{x,nxt[i+1]}});
                }
            }
            else{
                if (nxt[i]<i+x){
                    edge.push_back({nxt[i]-i,{x,nxt[i]}});
                }
            }
        }
    }
    for (int i=1; i<=cnt; i++){
        parent[i] = i;
    }
    sort(edge.begin(),edge.end());
    ll ans = 0;
    for (auto in:edge){
        int w = in.fi;
        int u = vis[in.se.fi];
        int v = vis[in.se.se];

//        cout << in.se.fi << " " << in.se.se << " " << w << endl;

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
