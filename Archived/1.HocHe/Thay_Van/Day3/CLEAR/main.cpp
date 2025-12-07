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
vector<int> adj[1010];
bool vis[1010];

void BFS(int s){
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();

        if (vis[u]) continue;

//        cout << u << endl;

        vis[u] = true;
        for (auto v:adj[u]){
            q.push(v);
        }
    }
}

/*Solution*/
void solve(){
    for (int i=2; i<=1000; i++){
        int tmp = i, t=0;
        while (tmp){
            int c = tmp%10;
            t+=c*c;
            tmp/=10;
        }
        adj[t].push_back(i);
    }
    BFS(1);
    int l,r,ans=0;
    cin >> l >> r;
    for (int i=l; i<=r; i++){
        int tmp = i, t=0;
        while (tmp){
            int c = tmp%10;
            t+=c*c;
            tmp/=10;
        }
        if (vis[t]) ++ans;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("CLEAR.inp","r",stdin);
    freopen("CLEAR.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
