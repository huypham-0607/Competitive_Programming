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
const int N = 2e3+10;
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
int pre[N][N];
vector<pii> ans;

//DSU
int parent[N];

void Init(){
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
}

int Find(int u){
    return (u==parent[u])? u : parent[u]=Find(parent[u]);
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
    Init();
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=n-1; i>0; i--){
        for (int j=1; j<=n; j++){
            int k = a[j]%i;
            int idx = Find(j);
            if (pre[i][k] && idx!=Find(pre[i][k])){
                ans.push_back({pre[i][k],j});
                Union(pre[i][k],j);
                break;
            }
            else pre[i][k] = j;
        }
    }
    cout << "YES" << endl;
    for (int i=(int)ans.size()-1; i>=0; i--){
        cout << ans[i].fi << " " << ans[i].se << endl;
    }
    ans.clear();
    for (int i=1; i<n; i++){
        for (int j=0; j<n; j++){
            pre[i][j] = 0;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
