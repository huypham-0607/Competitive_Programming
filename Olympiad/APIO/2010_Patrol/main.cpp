#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10;
const int INF = 2e9;

int test;
int n,k;
int f[maxn],g[maxn],h[maxn],path[maxn][10];
vector<int> a[maxn];
vector<int> pre[maxn];
queue<pii> q;
int meow,cnt = 0;
queue<pair<string,int>> q2;

void update(int u, int val){
    path[u][5] = val;
    for (int i=4; i>0; i--){
        if (path[u][i] < path[u][i+1]) swap(path[u][i],path[u][i+1]);
    }
}

void dfs1(int u, int p){
//    if (a[u].size() > 3){
//            cnt+=a[u].size()-2;
//                ++cnt;
//            if (u > 5000){
//                ++cnt;
//                q.push({u,a[u].size()});
//            }
//    }
    int sec = 0;
    for (auto v:a[u]){
        if (v!=p){
            dfs1(v,u);
            update(u,path[v][1]+1);
            if (f[v] > f[u]){
                sec = f[u];
                f[u] = f[v];
            }
            else if (f[v] > sec){
                sec = f[v];
            }
        }
    }
    for (auto v:a[u]){
        if (f[u]  == f[v]){
            pre[u].push_back(sec);
        }
        else pre[u].push_back(f[u]);
    }
    f[u] = max(f[u],path[u][1]+path[u][2]);
}

void dfs2(int u, int p){
    for (int idx = 0; idx < (long long)a[u].size(); idx++){
        int v = a[u][idx];
        if (v == p) continue;

        if (path[v][1]+1 == path[u][1]) g[v] = max(path[u][2]+1,g[u]+1);
        else g[v] = max(path[u][1]+1,g[u]+1);

        if (path[v][1]+1 == path[u][1]) h[v] = max({g[u]+path[u][2], path[u][2]+path[u][3],h[u],pre[u][idx]});
        else if (path[v][1]+1 == path[u][2]) h[v] = max({g[u]+path[u][1], path[u][1]+path[u][3],h[u],pre[u][idx]});
        else h[v] = max({g[u]+path[u][1], path[u][1]+path[u][2],h[u],pre[u][idx]});

        dfs2(v,u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);

    int start = (n-1)*2;
    int preans = (n-1)*2+2;
    int ans = (n-1)*2+2;
//    int ans2 = (n-1)*2;
//    cout << ans << endl;
    if (k == 2){
        for (int i=1; i<=n; i++){
//            cout << i << ": ";
            ans = min(ans,start-path[i][1]-path[i][2]-path[i][3]-path[i][4]+2);
            if (start-path[i][1]-path[i][2]-path[i][3]-path[i][4]+2 == 18921) q2.push({"4 child ",i});
            ans = min(ans,start-path[i][1]-path[i][2]-path[i][3]-g[i]+2);
            if (start-path[i][1]-path[i][2]-path[i][3]-g[i]+2 == 18921) q2.push({"g path ",i});
            ans = min(ans,start-path[i][1]-path[i][2]-h[i]+2);
            if (start-path[i][1]-path[i][2]-h[i]+2 == 18921){
                    q2.push({"h path ",i});
                    q.push({path[i][1],path[i][2]});
                    q.push({h[i],g[i]});
            }
//            cout << start-path[i][1]-path[i][2]-path[i][2]-path[i][4]+2 << " " << start-path[i][1]-path[i][2]-path[i][3]-g[i]+2 << " " << start-path[i][1]-path[i][2]-h[i]+2 << endl;
            if (ans != preans && ans == 18921){
                q.push({i,ans});
                preans = ans;
            }
        }
    }
    else{
        for (int i=1; i<=n; i++){
            ans = min(ans,start-path[i][1]-path[i][2]+1);
            ans = min(ans,start-path[i][1]-g[i]+1);
        }
    }
//    cout << ans << " " << ans2 << endl;
//    cout << ans;
    if (ans == 18921){
//        cout << meow;
//        cout << cnt << endl;
//        while (!q.empty()){
//            cout << q.front().fi << " " << q.front().se << endl;
//            q.pop();
//        }
//        while (!q2.empty()){
//            cout << q2.front().fi << q2.front().se;
//            q2.pop();
//        }
//        for (int i=1; i<=n; i++){
            for (int j=1; j<=4; j++){
                cout << path[88][j] << " ";
            }
            cout << h[88] << " " << g[88] << endl;
            for (int j=1; j<=4; j++){
                cout << path[38][j] << " ";
            }
            cout << h[38] << " " << g[38] << endl;
//            cout << endl;
//        }
    }
    else cout << ans;
//    cout << endl;
//    cout << "g:" << endl;
//    for (int i=1; i<=n; i++){
//        cout << g[i] << " ";
//    }
//    cout << endl;
//    cout << "f: " << endl;
//    for (int i=1; i<=n; i++){
//        cout << h[i] << " ";
//    }
//    cout << endl;
//    cout << "path:" << endl;
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=4; j++){
//            cout << path[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
