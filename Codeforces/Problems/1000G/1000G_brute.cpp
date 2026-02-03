#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(x, v) for(auto &x : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

const int N = 3e5+5, LOG = 19;
int n, q, t, a[N], st[N], en[N], anc[N][LOG];
ll sum[N][LOG], part[N][LOG];
ll dp[N], up[N], edge[N][LOG];
vector<pair<int, int>> graph[N];

bool isanc(int u, int v) {
  return st[u] <= st[v] && st[v] <= en[u];
}

void dfs1(int u, int p) {
  st[u] = ++t;
  anc[u][0] = p;
  fore(e, graph[u]) if (e.fi != p) {
    int v = e.fi, w = e.se;
    dfs1(v, u);
    ll value = max(0LL, dp[v] - 2*w);
    part[v][0] = value;
    dp[u] += value;
    edge[v][0] = w;
  }
  dp[u] += a[u];
  fore(e, graph[u]) if (e.fi != p) sum[e.fi][0] = dp[u];
  en[u] = t;
}

void dfs2(int u, int p) {
  up[u] = dp[u];
  fore(e, graph[u]) if (e.fi != p) {
    int v = e.fi, w = e.se;
    ll value = max(0LL, dp[v] - 2*w);
    dp[u] -= value;
    ll value2 = max(0LL, dp[u] - 2*w);
    dp[v] += value2;
    dfs2(v, u);
    dp[v] -= value2;
    dp[u] += value;
  }
}

void prep() {
  foru(j, 1, LOG-1) {
    foru(i, 1, n) {
      anc[i][j] = anc[anc[i][j-1]][j-1];
      sum[i][j] = sum[i][j-1] + sum[anc[i][j-1]][j-1];
      part[i][j] = part[i][j-1] + part[anc[i][j-1]][j-1];
      edge[i][j] = edge[i][j-1] + edge[anc[i][j-1]][j-1];
    }
  }
}

int lca(int u, int v) {
  if (isanc(u, v)) return u;
  ford(j, LOG-1, 0) if (!isanc(anc[u][j], v)) u = anc[u][j];
  return anc[u][0];
}

ll query(int u, int v) {
  if (u == v) return up[u];
  if (isanc(v, u)) swap(u, v);
  int l = lca(u, v);
  ll ret = (u == l ? up[l] : dp[u] + up[l]) + dp[v];
  ford(j, LOG-1, 0) {
    if (!isanc(anc[u][j], l)) { ret += sum[u][j] - part[u][j] - edge[u][j]; u = anc[u][j]; }
    if (!isanc(anc[v][j], l)) { ret += sum[v][j] - part[v][j] - edge[v][j]; v = anc[v][j]; }
  }
  return ret - (u == l ? 0 : edge[u][0] + part[u][0]) - edge[v][0] - part[v][0];
}

int main() {
    freopen("1000G.inp","r",stdin);
    freopen("1000G.ans","w",stdout);
  cin >> n >> q;

  foru(i, 1, n) {
    cin >> a[i];
  }

  foru(i, 2, n) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
  }

  dfs1(1, 1); 
  dfs2(1, 1); 
  prep();

  foru(i, 1, q) {
    int u, v;
    cin >> u >> v;
    cout << query(u, v) << "\n";
  }
}