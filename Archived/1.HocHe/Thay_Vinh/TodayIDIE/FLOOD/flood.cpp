/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

#define NAME "FLOOD"

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
int n,q;
vector<piii> v;
bool vis[N];
int ans[N];

//DSU
int parent[N];

void Init(){
    for (int i=1; i<=n; i++) parent[i] = i;
}

int Find(int x){
    return (parent[x] == x)? x : parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    int u = Find(x);
    int v = Find(y);
    if (u!=v){
        parent[v] = u;
    }
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        v.push_back({x,{1,i}});
    }
    for (int i=1; i<=q; i++){
        int x;
        cin >> x;
        v.push_back({x,{0,i}});
    }
    sort(v.begin(),v.end(),greater<piii>());

    int cnt = 0;
    int ucnt = 0;
    for (auto in:v){
        int x = in.fi;
        int ver = in.se.fi;
        int idx = in.se.se;

        if (ver){
            ++cnt;
            vis[idx] = true;
            if (idx+1<=n && vis[idx+1]){
                Union(idx,idx+1);
                ++ucnt;
            }
            if (idx-1>0 && vis[idx-1]){
                Union(idx,idx-1);
                ++ucnt;
            }
        }
        else{
            ans[idx] = cnt - ucnt;
        }
    }
    for (int i=1; i<=q; i++){
        cout << ans[i] << " ";
    }
}

/*Driver Code*/
signed main(){
//    freopen(NAME".INP","r",stdin);
//    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
