#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll mod = 1'000'000'007LL;

struct Info {
  int m, ct;
  Info(int M, int C) : m(M), ct(C%mod) {}
  Info() : Info(0, 0) {}
  Info combine(Info &other) {
    if (m == other.m) return {m, ct + other.ct};
    else if (m > other.m) return {m, ct};
    else return {other.m, other.ct};
  }
};

struct Tree {
  vector<Info> info;
  Tree(int size) { info.resize(size*4); }
  void update(int v, int x, int xl, int xr, Info delta) {
    if (xl == xr) {
      info[x] = delta;
    } else {
      int xm = (xl + xr) / 2;
      if (v <= xm) update(v, x*2, xl, xm, delta);
      else update(v, x*2+1, xm+1, xr, delta);
      info[x] = info[x*2].combine(info[x*2+1]);
    }
  }
  Info query(int l, int r, int x, int xl, int xr) {
    if (l > r) return {};
    if (l == xl && r == xr) {
      return info[x];
    } else {
      int xm = (xl + xr) / 2;
      Info left = query(l, min(r, xm), x*2, xl, xm);
      Info right = query(max(l, xm+1), r, x*2+1, xm+1, xr);
      return left.combine(right);
    }
  }
};

ll modmul(ll a, ll b) {
  return a * b % mod;
}

ll modpow(ll a, ll b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  ll half = modpow(a, b/2);
  ll ans = modmul(half, half);
  if (b % 2) return modmul(ans, a);
  else return ans;
}

int main() {
    freopen("Zoltan.inp","r",stdin);
    freopen("Zoltan.ans","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  int N;
  cin >> N;
  vector<int> X(N);
  for (int i=0; i<N; i++) cin >> X[i];

  // find longest increasing subsequence starting at node 'i'
  vector<int> order(N);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) -> bool {
    if (X[i] == X[j]) return i < j;
    return X[i] > X[j];
  });
  Tree tree(N);
  vector<Info> incr(N);
  for (int i : order) {
    Info info = tree.query(i+1, N-1, 1, 0, N-1);
    info.m += 1;
    if (info.m == 1) info.ct = 1; // start once
    tree.update(i, 1, 0, N-1, info);
    incr[i] = info;
  }

  // find longest decreasing subsequence starting at node 'i'
  tree = Tree(N);
  sort(order.begin(), order.end(), [&](int i, int j) -> bool {
    if (X[i] == X[j]) return i < j;
    return X[i] < X[j];
  });
  vector<Info> decr(N);
  for (int i : order) {
    Info info = tree.query(i+1, N-1, 1, 0, N-1);
    info.m += 1;
    if (info.m == 1) info.ct = 1; // start once
    tree.update(i, 1, 0, N-1, info);
    decr[i] = info;
  }

  Info best;
  for (int i=0; i<N; i++) {
    Info here = {
      decr[i].m + incr[i].m - 1,
      (int) modmul(decr[i].ct, incr[i].ct),
    };
    best = best.combine(here);
  }

  int M = best.m, C = best.ct;
  cout << M << " " << modmul(C, modpow(2, N-M)) << "\n";

  return 0;
}
