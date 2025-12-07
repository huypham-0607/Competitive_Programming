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
vector<int> order[N];
vector<int> adj[N];
vector<int> lst[N];
int deg[N];
priority_queue<int,vector<int>,greater<int>> pq;

//Topo
bool check(int mid){
    for (int i=1; i<=n; i++){
        adj[i].clear();
        deg[i] = 0;
    }
    for (int i=1; i<=mid; i++){
        for (int j=1; j<(int)lst[i].size(); j++){
            adj[lst[i][j-1]].push_back(lst[i][j]);
            ++deg[lst[i][j]];
        }
    }
    for (int i=1; i<=n; i++){
        if (!deg[i]) pq.push(i);
    }
    while (!pq.empty()){
        int u = pq.top();
        pq.pop();

        order[mid].push_back(u);
        for (auto v:adj[u]){
            --deg[v];
            if (!deg[v]) pq.push(v);
        }
    }
    if ((int)order[mid].size()!=n) return false;
    else return true;
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int x;
        cin >> x;
        for (int j=1; j<=x; j++){
            int val;
            cin >> val;
            lst[i].push_back(val);
        }
    }
    for (int i=1; i<=n; i++){
        order[0].push_back(i);
    }
    int ans = 0;
    int l=1, r = m;
    while (l<=r){
        int mid = (l+r)/2;
        if (check(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    for (int i=0; i<n-1; i++){
        cout << order[ans][i] << " ";
    }
    cout << order[ans][n-1];
}

/*Driver Code*/
signed main(){
    freopen("milkorder.in","r",stdin);
    freopen("milkorder.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
