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
const int MD = 1e9+7;

/*Global Variables*/
int n,m;
vector<int> dp;
bool cycle[N];
vector<vector<int>> adj;
vector<int> f,g;
bool vis[N];

void Init(){
    cin >> n >> m;
    adj.resize(n+10);
    f.resize(n+10);
    g.resize(n+10);
    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void DFSDP(int u, int p){
    vis[u] = true;
    g[u] = 1;
    f[u] = 0;
    vector<int> *lst = new vector<int>(), *pre = new vector<int>();

    lst->push_back(0);
    pre->push_back(1);
    int cnt = 0;

    for (auto v:adj[u]){
        if (v==p || vis[v] || cycle[v]) continue;

        DFSDP(v,u);
        g[u] = ((ll)g[u]*(ll)((ll)f[v]+g[v]))%MD;
        ++cnt;
        lst->push_back(v);
        pre->push_back(((ll)(*pre)[cnt-1]*(ll)((ll)f[v]+g[v]))%MD);
    }
    int suf = 1;
    for (int i=cnt; i>0; i--){
        f[u] = ((ll)f[u]+(ll)suf%MD*(ll)((*pre)[i-1])%MD*(ll)g[((*lst)[i])]%MD)%MD;
        suf = (ll) suf*((ll)f[(*lst)[i]]+g[(*lst)[i]])%MD;
    }
    pre->clear();
    lst->clear();
    delete pre;
    delete lst;
//    cout << cnt << endl;
}

bool Check1(){
    if (m == n-1) return true;
    return false;
}

void Solve1(){
    DFSDP(1,0);
    cout << (f[1] + g[1])%MD << endl;
//    for (int i=1; i<=n; i++){
//        cout << f[i] << " " << g[i] << endl;
//    }
}

vector<int> CycleList;

int DFSFINDCYCLE(int u, int p){
    int res = 0;

    vis[u] = true;
    for (auto v:adj[u]){
        if (v==p) continue;
        if (vis[v]){
            if (res){
                CycleList.push_back(u);
                cycle[u] = true;
                res = 0;
            }
            else res = v;
            continue;
        }
        res = max(res,DFSFINDCYCLE(v,u));
    }
    if (res){
        CycleList.push_back(u);
        cycle[u] = true;
    }
//    cout << u << " " << res << " " << p << endl;
    if (u == res) return 0;
    else return res;
}


void Solve2(){
    DFSFINDCYCLE(1,0);
    for (int i=1; i<=n; i++){
        vis[i] = false;
    }
//    cout << p1 << " " << p2 << endl;

    int res1 = 0;
    int res2 = 0;
    int res3 = 2;
    for (int i=0; i<(int)CycleList.size(); i++){
        int u = CycleList[i];
        DFSDP(CycleList[i],0);
        res3 = (ll)((ll)res3*g[u])%MD;
    }
    dp.resize(CycleList.size()+2);
    dp[0] = 1;
    int u,v;
    for (int i=1; i<=(int)CycleList.size(); i++){
        u = CycleList[i-1];
        dp[i] = (ll)((ll)((ll)f[u]+g[u])%MD*(ll)dp[i-1])%MD;
        if (i>1){
            v = CycleList[i-2];
            dp[i] = (ll)((ll)dp[i]+((ll)((ll)g[u]*g[v])%MD*dp[i-2]%MD))%MD;
        }
    }
//    for  (int i=1; i<=CycleList.size(); i++){
//        cout << dp[i] << " ";
//    }
//    cout << endl;
    res1 = dp[(int)CycleList.size()];
    res2 = ((ll)g[CycleList.front()]*g[CycleList.back()])%MD;
    dp[1] = 1;
    for (int i=2; i<(int)CycleList.size(); i++){
        u = CycleList[i-1];
        dp[i] = (ll)((ll)((ll)f[u]+g[u])%MD*dp[i-1])%MD;
        if (i>2){
            v = CycleList[i-2];
            dp[i] = (ll)((ll)dp[i]+((ll)((ll)g[u]*g[v])%MD*dp[i-2]%MD))%MD;
        }
    }
//    cout << res2 << endl;
//    for  (int i=1; i<=CycleList.size(); i++){
//        cout << dp[i] << " ";
//    }
//    cout << endl;
    res2 = (ll)((ll)res2*dp[(int)CycleList.size()-1])%MD;
//    cout << res1 << " " << res2 << " " << res3 << endl;
    cout << ((res1 + res2)%MD+res3)%MD << endl;

//    for (auto v:CycleList){
//        cout << v << " " << f[v] << " " << g[v] << endl;
//    }
//    cout << CycleList.size() << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();
    if (Check1()) return Solve1(),0;
    else return Solve2(),0;

    return 0;
}
