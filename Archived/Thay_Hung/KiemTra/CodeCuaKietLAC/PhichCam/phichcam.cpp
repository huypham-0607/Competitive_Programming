#include <bits/stdc++.h>

#define pii pair<int,int>
#define iii pair<int,pii>
#define fi first
#define se second

using namespace std;

const int N = 105;

bool visited[N * 4];
int match[N * 4];
vector<int> a[4 * N];
bool ok[N * 4][N * 4];
int b[N], d[N];
pair<int,int> adap[N];
pair<string,pii> c[N * 4];
vector<int> adj[N * 4];
bool vis2[N * 4];
int cur = 0;
int m,n,k;

void bfs(int t){
    queue<int> q;
    memset(vis2,0,sizeof(vis2));
    int u = t;
    vis2[u] = 1;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if (vis2[v]) continue;
            vis2[v] = 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= cur; i++){
        ok[t][i] = vis2[i];
    }
}

int aug(int u){
    if (visited[u]) return 0;
    visited[u] = 1;
    for (int i = 0; i < a[u].size(); i++){
        int v = a[u][i];
        if (match[v] == -1 || aug(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

void coorcom(){
    sort(c + 1,c + 1 + cur);
    int cnt = 0;
    for (int i = 1; i <= cur; i++){
        if (c[i].fi != c[i-1].fi) cnt++;
        int ind = c[i].se.se;
        int t = c[i].se.fi;
        if (t == 0) b[ind] = cnt;
        else if (t == 1) d[ind] = cnt;
        else if (t == 2) adap[ind].fi = cnt;
        else if (t == 3) adap[ind].se = cnt;
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    freopen("phichcam.inp","r",stdin);
    freopen("phichcam.out","w",stdout);
    string s;
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> s;
        cur++;
        c[cur].fi = s;
        c[cur].se.fi = 0;
        c[cur].se.se = i;
    }
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s >> s;
        cur++;
        c[cur].fi = s;
        c[cur].se.fi = 1;
        c[cur].se.se = i;
    }
    cin >> k;
    for (int i = 1; i <= k; i++){
        cin >> s;
        cur++;
        c[cur].fi = s;
        c[cur].se.fi = 2;
        c[cur].se.se = i;
        cin >> s;
        cur++;
        c[cur].fi = s;
        c[cur].se.fi = 3;
        c[cur].se.se = i;
    }
    coorcom();
    for (int i = 1; i <= k; i++){
        adj[adap[i].fi].push_back(adap[i].se);
    }
    for (int i = 1; i <= cur; i++){
        bfs(i);
    }
//    for (int i = 1; i <= m; i++){
//        cout << b[i] << " ";
//    } cout << "\n";
//    for (int i = 1; i <= n; i++){
//        cout << d[i] << " ";
//    } cout << "\n";
//    for (int i = 1; i <= k; i++){
//        cout << adap[i].fi << " " << adap[i].se << "\n";
//    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int u = d[i];
            int v = b[j];
            //cout << u << " " << v << " " << ok[u][v] << "\n";
            if (ok[u][v]){
                a[i].push_back(j + n);
            }
        }
    }
    int res = n;
    memset(match,-1,sizeof(match));
    for (int i = 1; i <= n; i++){
        memset(visited,0,sizeof(visited));
        res -= aug(i);
    }
    cout << res;
}
