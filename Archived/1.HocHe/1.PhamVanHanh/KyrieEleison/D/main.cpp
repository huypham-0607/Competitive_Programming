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
const int N = 5e4+10;
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
int n,k;
bool breedable[N];
vector<pii> adj[N];

bool check(vector<pii>* v, int idx, int lim){
    int l=0, r=(int)v->size()-1;
    while (l<=r){
        if (l==idx) ++l;
        if (r==idx) --r;

        if ((*v)[l].fi+(*v)[r].fi>lim) return true;

        ++l;
        --r;
    }
    return false;
}

pair<int,int> DFS(int u, int p, int lim,int prev){
    vector<pii>* v;
    if (breedable[u]) v->push_back({0,u});
    for (auto in:adj[u]){
        int child = in.fi;
        int w = in.se;
        if (child==p) continue;
        pii val = DFS(child,u,lim,w);
        if (val.fi<0) return make_pair(-1,0);
        if (val.fi) v->push_back(val);
    }
    int m = (int)v->size();
    sort(v->begin(),v->end());
    if (m%2==0){
        for (int i=0; i<m/2; i++){
            if ((*v)[i].fi+(*v)[m-i-1].fi>lim) return make_pair(-1,0);
        }
        return make_pair(0,0);
    }
    else{
        int res = -1;
        int l=0, r=m-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (check(v,mid,lim)){
                res = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        res+=1;
        pii oof;
        if (res!=m) oof = (*v)[res];
        delete v;
        if (res == m) return make_pair(-1,0);
        if (oof.fi+prev>lim) return make_pair(-1,0);
        return make_pair(oof.fi+prev,oof.se);
    }
}

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=k; i++){
        int x;
        cin >> x;
        breedable[x] = true;
    }
    for (int i=1; i<n; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    ll l = 1, r = 1LL*N*INF;
    ll ans = 0;
    while (l<=r){
        int mid = (l+r)/2;
        pii sus = DFS(1,0,mid,0);
        if (sus.fi>=0){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }

    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
