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
const int N = 5e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

struct info{
    int val, cnt, pre, total;
    info (int _val=0; int _cnt=0; int _pre=0; int _total=0): val{_val}, cnt{_cnt}, pre{_pre}, total{_total} {};
    void
};

/*Global Variables*/
int n;
vector<int> a[N];
int f[N][5], g[N];

void update(info &x, info &y,info &z, int val, int cnt){
    if (val > x.val){
        z = y;
        y = x;
        x = info(val,1,cnt,0);
    }
    else if (val == x.val){
        ++x.cnt;
        x.total+=x.pre*cnt;
        x.pre+=cnt;
    }
    else if (val > y.val){
        z = y;
        y = info(val,1,cnt,0);
    }
    else if (val == y.val){
        ++y.cnt;
        y.total+=y.pre*cnt;
        y.pre+=cnt;
    }
    else if (val > x.val){
        z = info(val,1,cnt,0);
    }
    else if (val == z.val){
        ++z.cnt;
        z.total+=z.pre*cnt;
        z.pre+=cnt;
    }
    return;
}

//DP ON TREE
void DFSDOWN(int u, int p){
    vector<pii> tmp;
    int
    for (auto v:a[u]){
        if (v == p) continue;
        DFSDOWN();
        tmp.push_back({f[v].val,f[v].cnt});
    }
    sort(tmp.begin(),tmp.end(),greater<pii>());
    int prev = 0;
    for (int i=0; i<tmp.size(); i++){
        update(f[u][1],f[u][2],f[u][3],tmp.fi,tmp.se);
    }
}

void DFSUP(int u, int p){

}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFSDOWN(1,0);
    DFSUP(1,0);
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
