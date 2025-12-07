/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
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
int n,m;
bool vis[N];
int OnStack[N];
vector<int> adj[N];
stack<int> s;
vector<int> ans;

void DFS(int u){
//    cout << u << endl;
    vis[u] = true;
    s.push(u);
    OnStack[u] = true;
    for (auto v:adj[u]){
        if (!vis[v]){
            DFS(v);
        }
        else{
            if (OnStack[v]){
                ans.push_back(v);
                while (s.top()!=v){
                    ans.push_back(s.top());
                    s.pop();
                }
                ans.push_back(v);
                cout << ans.size() << endl;
                while (ans.size()){
                    cout << ans.back() << " ";
                    ans.pop_back();
                }
                exit(0);
            }
        }
    }
    s.pop();
    OnStack[u] = false;
}

/*Solution*/
void solve(){
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            DFS(i);
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
