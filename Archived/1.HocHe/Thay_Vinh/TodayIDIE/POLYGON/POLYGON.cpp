/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "POLYGON"

using namespace std;

/*Constants*/
const int N = 5e3+10;
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
vector<pii> a[20010],b[20010];
vector<pair<int,string>> adj[N];
string s1,s2;
bool vis[N];
int s = 0;

//DFS
void DFS(int u){
    vis[u] = true;
    if (u==1) swap(s1,s2);
    if (u==s){
        for (auto in:adj[u]){
            if (in.se!="S") continue;
            s1+=in.se;
            DFS(in.fi);
        }
        return;
    }
    if (vis[adj[u][0].fi] && vis[adj[u][1].fi]){
        for (auto in:adj[u]){
            int v = in.fi;
            if (v==s){
                s1+=in.se;
            }
        }
        return;
    }
    for (auto in:adj[u]){
        int v = in.fi;
        if (!vis[v]){
            s1+=in.se;
            DFS(v);
        }
    }
}

/*Solution*/
void solve(){
    cin >> n;
    pii rawr = make_pair(-10001,-10001);
    s = 0;
    for (int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        if (rawr < make_pair(x,y)){
            rawr = make_pair(x,y);
            s = i;
        }

        a[x].push_back({y+10000,i});
        b[y].push_back({x+10000,i});
    }
    for (int i=0; i<=20000; i++){
        sort(a[i].begin(),a[i].end());
        for (int j=0; j<(int)a[i].size(); j+=2){
            adj[a[i][j].se].push_back({a[i][j+1].se,"E"});
            adj[a[i][j+1].se].push_back({a[i][j].se,"W"});
        }
    }
    for (int i=0; i<=20000; i++){
        sort(b[i].begin(),b[i].end());
        for (int j=0; j<(int)b[i].size(); j+=2){
            adj[b[i][j].se].push_back({b[i][j+1].se,"N"});
            adj[b[i][j+1].se].push_back({b[i][j].se,"S"});
        }
    }
    DFS(s);
    cout << s1 << s2 << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
