//#include "swap.h"

#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

struct Swap {
  vector<int> top, prt, val, dep;

  void init(int N, int M,
          const vector<int>& U, const vector<int>& V, const vector<int>& W) {
    vector<tuple<int, int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
      edges[i] = make_tuple(W[i], U[i], V[i]);
    }
    sort(edges.begin(), edges.end());
    vector<int> f(N * 2);
    iota(f.begin(), f.end(), 0);
    vector<vector<int>> ch(N * 2);
    val.assign(N * 2, -1); top.assign(N * 2, -1);
    prt.resize(N * 2); dep.resize(N * 2);
    vector<int> deg(N * 2), sub(N * 2), pref(N * 2, -1);
    vector<bool> ok(N * 2);
    function<int(int)> find = [&](int x) {
      return f[x] == x ? x : f[x] = find(f[x]);
    };
    for (const auto& e : edges) {
      int u, v, w;
      tie(w, u, v) = e;
      ++deg[u]; ++deg[v];
      bool fl = deg[u] > 2 || deg[v] > 2;
      u = find(u); v = find(v);
      fl |= u == v || ok[u] || ok[v];
      int x;
      if (u == v) x = u;
      else {
        x = N++;
        ch[x] = {u, v};
        prt[u] = prt[v] = f[u] = f[v] = x;
      }
      ok[x] = fl;
      if (fl && val[x] == -1) val[x] = w;
    }

    function<void(int)> dfs = [&](int u) {
      sub[u] = ch[u].empty();
      for (int v : ch[u]) {
        dep[v] = dep[u] + 1;
        if (val[v] == -1) val[v] = val[u];
        dfs(v);
        sub[u] += sub[v];
        if (pref[u] == -1 || sub[pref[u]] < sub[v]) pref[u] = v;
      }
    };
    dfs(N - 1);
    function<void(int)> hld = [&](int u) {
      if (top[u] == -1) top[u] = u;
      if (pref[u] != -1) {
        top[pref[u]] = top[u];
        hld(pref[u]);
        for (int v : ch[u])
          if (v != pref[u])
            hld(v);
      }
    };
    hld(N - 1);
  }

  int getMinimumFuelCapacity(int X, int Y) const {
    int U = top[X], V = top[Y];
    while (U != V) {
      if (dep[U] > dep[V]) {
        swap(U, V);
        swap(X, Y);
      }
      Y = prt[V];
      V = top[Y];
    }
    X = dep[X] < dep[Y] ? X : Y;
    return val[X];
  }

} solver;

void init(int N, int M,
          std::vector<int> U, std::vector<int> V, std::vector<int> W) {
  solver.init(N, M, U, V, W);
}

int getMinimumFuelCapacity(int X, int Y) {
  return solver.getMinimumFuelCapacity(X, Y);
}

int _n,_m,q;
vector<signed> U, V, W;

/*Solution*/
void solve(){
    cin >> _n >> _m;
    for (int i=0; i<_m; i++){
        signed u,v,w; cin >> u >> v >> w;
        U.push_back(u);
        V.push_back(v);
        W.push_back(w);
    }
    init((signed)_n,(signed)_m,U,V,W);
    cin >> q;
    for (int i=1; i<=q; i++){
        int x,y; cin >> x >> y;
        cout << getMinimumFuelCapacity(x,y) << endl;
    }
}

/*Driver Code*/
signed main(){
    freopen("SwappingCities.inp","r",stdin);
    freopen("SwappingCities.ans","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
