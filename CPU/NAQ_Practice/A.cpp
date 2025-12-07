/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,k,c;

/*Solution*/
void solve(){
    cin >> n >> k >> c;
    vector<pii> v;
    vector<int> cnt(n+10,0);
    vector<bool> vis(n+10,false);
    for (int i=1; i<=n; i++){
        int x,y; cin >> x >> y;
        v.push_back({x,y});
    }
    vector<pii> ans;
    int prev = 0;
    int cntq = 0;
    for (int i=0; i<n; i++){
        if (cntq == k) break;
        if (cnt[v[i].se]<c){
            ans.push_back({i,v[i].fi});
            vis[i] = true;
            ++cnt[v[i].se];
            ++cntq;
        }
    }
    for (int i=0; i<n; i++){
        if (cntq == k) break;
        if (vis[i]) continue;
        ans.push_back({i,v[i].fi});
        ++cnt[v[i].se];
        ++cntq;
    }

    sort(all(ans));
    for (auto [x,y]:ans){
        cout << y << endl;
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
