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
int n,m;
vector<int> a[N];
int cnt[N];
int ans[N];

pair<int,bool> DFS(int u, int p, int k){

    vector<int> cres;
    for (auto v:a[u]){
        if (v==p) continue;
        auto tmp = DFS(v,u,k);
        cres.push_back(tmp.fi);

        if (!tmp.se) return tmp;
    }
    for (auto oof:cres){
        if (oof){
            if (cnt[k-oof]){
                --cnt[k-oof];
            }
            else ++cnt[oof];
        }
    }
    int c = 0;
    int rawr = 0;
    for (auto oof:cres){
        if (cnt[oof]){
            c+=cnt[oof];
            rawr = oof;
            cnt[oof]=0;
        }
    }
//    cout << k << " " << u << " " << rawr << " " << c << endl;
    if (c>1) return make_pair(0,false);
    else return make_pair((rawr+1)%k,true);
}

/*Solution*/
void solve(){
    cin >> n;
    m = n-1;
    for (int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1; i<=m; i++){
        if (m%i==0){
            pair<int,bool> tmp = DFS(1,0,i);
            if (tmp.se) ans[i] = 1;
        }
    }
    for (int i=1; i<=m; i++){
        cout << ans[i];
    }
}

/*Driver Code*/
signed main(){
    freopen("deleg.in","r",stdin);
    freopen("deleg.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
