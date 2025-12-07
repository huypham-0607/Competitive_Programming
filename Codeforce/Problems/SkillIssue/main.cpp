#include <bits/stdc++.h>

using namespace std;
const int LG = 19;
const int MAXN = 2e5+1;

vector<int> pa[LG],sum[LG],min_pre[LG],min_suf[LG],mn[LG],max_pre[LG],max_suf[LG],mx[LG];
vector<int> w;
vector<int> h;
vector<int> adj[MAXN+1];
int n,q;

struct Query{
    int u,v,k;
    Query(int _u,int _v,int _k) : u(_u), v(_v), k(_k) {};
};
vector<Query> qr;

void input() {
    cin >> q;
    n = 1;
    qr.clear();
    for (int i=1;i<=q;i++) adj[i].clear();
    w.assign(q+1,0);
    for (int i=1;i<=q;i++) {
        char c; cin >> c;
        if (c == '+') {
            int v,k; cin >> v >> k;
            n++;
            adj[v].push_back(n);
            adj[n].push_back(v);
            w[n] = k;
        }
        else {
            int u,v,k; cin >> u >> v >> k;
            qr.push_back(Query(u,v,k));
        }
    }
    for (int i=0;i<LG;i++) {
        pa[i].assign(n+1,0);
        sum[i].assign(n+1,0);
        min_pre[i].assign(n+1,0);
        max_pre[i].assign(n+1,0);
        min_suf[i].assign(n+1,0);
        max_suf[i].assign(n+1,0);
        mn[i].assign(n+1,0);
        mx[i].assign(n+1,0);
    }
    h.assign(n+1,0);
    w[1] = 1;
}

void dfs(int u) {
    for (int v : adj[u]) {
        if (v == pa[0][u]) continue;
        h[v] = h[u] + 1;
        pa[0][v] = u;
        sum[0][v] = w[v] + w[u];
        min_pre[0][v] = min({w[v],w[u] + w[v]});
        max_pre[0][v] = max({w[v],w[u] + w[v]});
        min_suf[0][v] = min({w[u],w[u] + w[v]});
        max_suf[0][v] = max({w[u],w[u] + w[v]});
        mn[0][v] = min({w[v],w[u],w[u] + w[v]});
        mx[0][v] = max({w[v],w[u],w[u] + w[v]});
        for (int i=1;i<LG;i++) {
            pa[i][v] = pa[i-1][pa[i-1][v]];
            sum[i][v] = sum[i-1][v] + sum[i-1][pa[i-1][v]] - w[pa[i-1][v]];
            min_pre[i][v] = min(min_pre[i-1][v], min_pre[i-1][pa[i-1][v]] + sum[i-1][v] - w[pa[i-1][v]]);
            max_pre[i][v] = max(max_pre[i-1][v], max_pre[i-1][pa[i-1][v]] + sum[i-1][v] - w[pa[i-1][v]]);
            min_suf[i][v] = min(min_suf[i-1][pa[i-1][v]], min_suf[i-1][v] + sum[i-1][pa[i-1][v]] - w[pa[i-1][v]]);
            max_suf[i][v] = max(max_suf[i-1][pa[i-1][v]], max_suf[i-1][v] + sum[i-1][pa[i-1][v]] - w[pa[i-1][v]]);
            mn[i][v] = min({min_pre[i][v],min_suf[i][v],min_suf[i-1][v] + min_pre[i-1][pa[i-1][v]]});
            mx[i][v] = max({max_pre[i][v],max_suf[i][v],max_suf[i-1][v] + max_suf[i-1][pa[i-1][v]]});
        }
        dfs(v);
    }
}

int lca(int u,int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u,v);
        int k = h[u] - h[v];
        for (int j=0;(1 << j) <= k;j++) {
            if (k & (1 << j)) {
                u = pa[j][u];
            }
        }
    }
    if (u == v) return u;
    for (int j = LG - 1; j >= 0; j--) {
        if (pa[j][u] != pa[j][v]) {
            u = pa[j][u];
            v = pa[j][v];
        }
    }
    return pa[0][u];
}

struct Data {
    int ans_max,ans_min,ans_max_pre,ans_min_pre,ans_max_suf,ans_min_suf,sum;
    Data(int _ans_max,int _ans_min,int _ans_max_pre,int _ans_min_pre,int _ans_max_suf,int _ans_min_suf,int _sum) {
        ans_max = _ans_max;
        ans_min = _ans_min;
        ans_max_pre = _ans_max_pre;
        ans_min_pre = _ans_min_pre;
        ans_max_suf = _ans_max_suf;
        ans_min_suf = _ans_min_suf;
        sum = _sum;
    }
};

Data lifting(int u,int l) {
    Data ans(max(0,w[u]),min(0,w[u]),max(0,w[u]),min(0,w[u]),max(0,w[u]),min(0,w[u]),w[u]);
    int k = h[u] - h[l];
//    cerr << k << ' ' << u << ' ' << l << '\n';
    for (int j=0; (1 << j) <= k; j++) {
        if (k & (1 << j)) {
            ans.ans_max_pre = max(ans.ans_max_pre, ans.sum + max_pre[j][u] - w[u]);
            ans.ans_min_pre = min(ans.ans_min_pre, ans.sum + min_pre[j][u] - w[u]);
            ans.ans_max = max({ans.ans_max, ans.ans_max_pre, ans.ans_max_suf + max_pre[j][u] - w[u], max_suf[j][u]});
            ans.ans_min = min({ans.ans_min, ans.ans_min_pre, ans.ans_min_suf + min_pre[j][u] - w[u], min_suf[j][u]});
            ans.ans_max_suf = max(max_suf[j][u], ans.ans_max_pre + sum[j][u] - w[u]);
            ans.ans_min_suf = min(min_suf[j][u], ans.ans_min_suf + sum[j][u] - w[u]);
            ans.sum = ans.sum + sum[j][u] - w[pa[j][u]];
//            cerr << sum[j][u] << ' ' << j << ' ' << u << '\n';
//            if (ans.ans_max == 1) cerr << u << ' ' << j << ' ' << ans.ans_max_pre << ' ' << max_suf[j][u] << ' ' << ans.ans_max_suf << ' ' << ans.ans_max_suf + max_pre[j][u] - w[u] << '\n';
            u = pa[j][u];
        }
    }
    return ans;
}

void print_debug(Data tmp) {
    cerr << tmp.ans_max << ' ' << tmp.ans_min << ' ' << tmp.ans_max_pre << ' ' << tmp.ans_min_pre << ' ' << tmp.ans_max_suf << ' ' << tmp.ans_min_suf << ' ' << tmp.sum << '\n';
}

void solve() {
    dfs(1);
    for (Query x : qr) {
        int u = x.u, v = x.v;
        int l = lca(u,v);
//        cerr << u << ' ' << v << ' ' << l <<'\n';
        Data du = lifting(u,l), dv = lifting(v,l);
        int ans = 0;
        if (l == u || l == v) {
            if (l == u) ans = (dv.ans_min <= x.k && dv.ans_max >= x.k);
            else ans = (du.ans_min <= x.k && du.ans_max >= x.k);
        }
        int ans_max = max({du.ans_max,dv.ans_max, du.ans_max_suf + dv.ans_max_suf - w[l]});
        int ans_min = min({du.ans_min,dv.ans_min, du.ans_min_suf + dv.ans_min_suf - w[l]});
        ans = (ans_min <= x.k && ans_max >= x.k);
        cout << ((ans || x.k == 0) ? "YES" : "NO");
        cout << '\n';
//        print_debug(du); print_debug(dv);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}
