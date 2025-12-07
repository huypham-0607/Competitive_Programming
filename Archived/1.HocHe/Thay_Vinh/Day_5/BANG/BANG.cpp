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
int a[N][4];
int cnt[N][2];
bool vis[N];
vector<pii> v;

/*Solution*/
void solve(){
    cin >> n;
    v.resize(n+10);
    for (int i=1; i<=3; i++){
        for (int j=1; j<=n; j++){
            cin >> a[j][i];
        }
    }
    for (int i=1; i<=n; i++){
        v[a[i][1]] = {a[i][2],a[i][3]};
        cnt[a[i][2]][0]++;
        cnt[a[i][3]][1]++;
    }
    queue<int> q;
    for (int i=1; i<=n; i++){
        if (!cnt[i][0] || !cnt[i][1]){
            q.push(i);
            vis[i] = true;
        }
    }

    int ans = 0;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        ++ans;

        cnt[v[u].fi][0]--;
        if (!vis[v[u].fi] && !cnt[v[u].fi][0]){
            q.push(v[u].fi);
            vis[v[u].fi] = true;
        }
        cnt[v[u].se][1]--;
        if (!vis[v[u].se] && !cnt[v[u].se][1]){
            q.push(v[u].se);
            vis[v[u].se] = true;
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("BANG.inp","r",stdin);
    freopen("BANG.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
