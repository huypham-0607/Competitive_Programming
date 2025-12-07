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
int n;
vector<vector<int>> a(1010),b(1010);
vector<bool> vis(1010), rawr(1010), woof(1010);

void BFS(int s, vector<vector<int>>& adj){
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto v:adj[u]){
            if (!vis[v]){
                q.push(v);
            }
        }
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int idx,k,x;
        cin >> idx >> k;
        for (int j=1; j<=k; j++){
            cin >> x;
            a[idx].push_back(x);
            b[x].push_back(idx);
        }
    }
    BFS(0,b);
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (!vis[i]) rawr[i] = true;
        else ++cnt;
        vis[i] = false;
    }
    BFS(0,a);
    for (int i=0; i<n; i++){
        if (!vis[i]) woof[i] = true;
        else ++cnt;
    }
    if (cnt == n*2) cout << "OK" << endl;
    else{
        for (int i=0; i<n; i++){
            if (rawr[i]) cout << "A " << i << endl;
            if (woof[i]) cout << "B " << i << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    freopen("PLAN.inp","r",stdin);
    freopen("PLAN.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
