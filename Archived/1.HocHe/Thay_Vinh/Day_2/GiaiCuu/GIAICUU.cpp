/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
int n,cnt,mn,val;
int cmp[N],prv[N];
vector<int> vec[N],adj[N];
int a[N], debt[N], p[N];
bool vis[N],cycle[N];

void FindCmp(int u, int idx){
    cmp[u] = idx;
    vec[idx].push_back(u);
    for (auto v:adj[u]){
        if (!cmp[v]){
            FindCmp(v,idx);
        }
    }
}

int FindCycle(int u){
    vis[u] = true;
    if (vis[a[u]]){
        cycle[u] = true;
        if (debt[u] < val){
            mn = u;
            val = debt[u];
        }
        return a[u];
    }
    int rawr = FindCycle(a[u]);
//    cout << u << " " << rawr << endl;
    if (rawr){
        if (debt[u] < val){
            mn = u;
            val = debt[u];
        }
        cycle[u] = true;
        if (rawr == u) return 0;
        else return rawr;
    }
    else return 0;
}

int omegabruh(int u){
    int v = u;
//    cout << u << " " << p[u] << endl;
    while (p[v]!=0){
        v = p[v];
//        cout << v << endl;
    }
    return v;
}

void Beanstalk(int u, int& res){
    cout << u << endl;
    vis[u] = true;
    res+=max(debt[u]-prv[u],(int)0);
    if (!vis[a[u]]){
        prv[a[u]] += debt[u];
    }
    if (!cycle[a[u]] && !vis[a[u]]){
        Beanstalk(a[u],res);
    }
    else{
        if (!vis[a[u]]){
            int v = a[u];
            int tmp = max(debt[v] - prv[v],(int)0);
            if (tmp < val){
                mn = v;
                val = tmp;
            }
        }
    }
}

int Ayaya(int u){
    int res = max(debt[u]-prv[u],(int)0);
    int pre = u;
    int v = a[u];
//    cout << u << endl;
    while (v!=u){
        res+=max(debt[v]-debt[pre]-prv[v],(int)0);
        pre = v;
        v = a[v];
//        cout << pre << " " << v << " " << debt[v] << " " << debt[pre] << endl;
    }
    return res;
}

void wat(int u){
    vis[u] = true;
    if (!vis[a[u]]) wat(a[u]);
}

int Process(int s){
//    cout << s << endl;
    int idx = cmp[s];
    FindCycle(s);
    int res = 0;
    for (auto u:vec[idx]){
        if (cycle[u]) cout << u << endl;
        vis[u] = false;
    }
    cout << endl;
//    cout << endl;
//    cout << "rawr" << endl;
    for (auto u:vec[idx]){
        if (cmp[u] == idx && !cycle[u]){
            int v = omegabruh(u);
            Beanstalk(v,res);
            cout << "res: " << res << endl;
        }
    }
//    for (auto u:vec[idx]){
//        cout << u << " " << cycle[u] << endl;
//    }
    int oof = LLINF;
    oof = min(oof, Ayaya(mn));
    for (auto u:vec[idx]){
        if (!vis[u]) wat(u);
    }
    return res+oof;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i] >> debt[i];
        adj[i].push_back(a[i]);
        adj[a[i]].push_back(i);
        p[a[i]] = i;
    }
//    for (int i=1; i<=n; i++){
//        cout << p[i] << endl;
//    }
    cnt = 0;
    for (int i=1; i<=n; i++){
        if (!cmp[i]) FindCmp(i,++cnt);
    }
    int ans = 0;
    for (int i=1; i<=n; i++){
        mn = 0;
        val = INF;
        if (!vis[i]) ans+=Process(i);
    }
    cout << ans;
}

/*Driver Code*/
signed main(){
    freopen("GIAICUU.INP","r",stdin);
    freopen("GIAICUU.OUT","w",stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
