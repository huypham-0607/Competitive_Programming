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
const int N = 3e5+10;
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
int n,s,e;
int mark[N];
int dp[N];
int parent[N];
stack<int> st;
vector<int> adj[N];
vector<int> lst;

bool Mika(int u, int p){
    parent[u] = p;
    bool ver = 0;
    if (u == e) ver = 1;
    for (auto v:adj[u]){
        if (v==p) continue;
        bool sus = Mika(v,u);
        ver = (ver||sus);
    }
    if (ver) st.push(u);
    return ver;
}

void DP(int u, int p, int banned){
    int t = 0;
    vector<int> tmp;
    for (auto v:adj[u]){
        if (v==p) continue;
        if (v==banned) continue;
        DP(v,u,banned);
        tmp.push_back(dp[v]);
    }
    sort(tmp.begin(),tmp.end(),greater<int>());
    for (int i=0; i<(int)tmp.size(); i++){
        t = max(t,tmp[i]+i+1);
    }
    dp[u] = t;
}

bool check(int mid){
    memset(dp,0,sizeof(dp));
    int banned1 = lst[mid];
    int banned2 = parent[banned1];
    DP(s,0,banned1);
    DP(e,0,banned2);
    if (dp[s]>dp[e]) return false;
    else return true;
}

/*Solution*/
void solve(){
    cin >> n >> s >> e;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Mika(s,0);
    while (!st.empty()){
        lst.push_back(st.top());
        st.pop();
    }
//    for (auto x:lst){
//        cout << x << endl;
//    }
    DP(s,0,lst[1]);
    DP(e,0,parent[lst[1]]);
    int ans = max(dp[s],dp[e]);
    int l = 2, r = (int)lst.size()-1;
    int pos = 1;
    while (l<=r){
        int mid = (l+r)/2;
        if (check(mid)){
            ans = max(dp[s],dp[e]);
            pos = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    if (pos+1<(int)lst.size()){
        check(pos+1);
        int rawr = max(dp[s],dp[e]);
        ans = min(ans,rawr);
    }
    cout << ans << endl;
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
