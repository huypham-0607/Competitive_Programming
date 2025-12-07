//Author: Thiuwunh
//Date: Sun, 28/04/2024, 22:42
//~kuru kuru

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5 + 5, lg = 20, INF = 1e18, MOD = 1e9 + 7;
pii edge[N];
vector<int> a[N];
int p[N][lg], h[N];
map<pair<int, int>, int> mp;
set<int> s, mi[N], M[N];

int random(int l, int r)
{
    return l + rd() % (r - l + 1);
}

void dfs(int u, int pa)
{
    for (int v : a[u])
    if (v != pa)
    {
        h[v] = h[u] + 1;
        p[v][0] = u;
        for (int i = 1; i < lg; ++i)
            p[v][i] = p[p[v][i - 1]][i - 1];
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];

    for (int i = lg - 1; i >= 0; --i)
    if (1 & (delta >> i)) u = p[u][i];
    if (u == v) return v;

    for (int i = lg - 1; i >= 0; --i)
    if (p[u][i] != p[v][i])
    {
        u = p[u][i];
        v = p[v][i];
    }

    return p[u][0];
}

void sol(int u, int pa)
{
    for (int v : a[u])
    if (v != pa) sol(v, u);

    int v = p[u][0];
    for (int i : mi[u]) s.insert(i);
    mp[{min(u, v), max(u, v)}] = *s.begin();

    for (int i : M[v])
    {
        if (s.find(i) != s.end()) s.erase(i);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
//    freopen("disrupt.in", "r", stdin);
//    freopen("disrupt.out", "w", stdout);

    int n, m; cin >> n >> m;
    for (int i = 1; i < n; ++i)
    {
        int x, y; cin >> x >> y;
        edge[i].f = min(x, y); edge[i].s = max(x, y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs(1, -1);

    while (m--)
    {
        int u, v, w; cin >> u >> v >> w;
        int z = lca(u, v);
        if (u != z) mi[u].insert(w);
        if (v != z) mi[v].insert(w);
        M[z].insert(w);
    }

    s.insert(INF);
    sol(1, -1);

    for (int i = 1; i < n; ++i)
    cout << (mp[{edge[i].f, edge[i].s}] == INF ? -1 : mp[{edge[i].f, edge[i].s}]) << '\n';

    return 0;
}

// ⡆⣐⢕⢕⢕⢕⢕⢕⢕⢕⠅⢗⢕⢕⢕⢕⢕⢕⢕⠕⠕⢕⢕⢕⢕⢕⢕⢕⢕⢕
// ⢐⢕⢕⢕⢕⢕⣕⢕⢕⠕⠁⢕⢕⢕⢕⢕⢕⢕⢕⠅⡄⢕⢕⢕⢕⢕⢕⢕⢕⢕
// ⢕⢕⢕⢕⢕⠅⢗⢕⠕⣠⠄⣗⢕⢕⠕⢕⢕⢕⠕⢠⣿⠐⢕⢕⢕⠑⢕⢕⠵⢕
// ⢕⢕⢕⢕⠁⢜⠕⢁⣴⣿⡇⢓⢕⢵⢐⢕⢕⠕⢁⣾⢿⣧⠑⢕⢕⠄⢑⢕⠅⢕
// ⢕⢕⠵⢁⠔⢁⣤⣤⣶⣶⣶⡐⣕⢽⠐⢕⠕⣡⣾⣶⣶⣶⣤⡁⢓⢕⠄⢑⢅⢑
// ⠍⣧⠄⣶⣾⣿⣿⣿⣿⣿⣿⣷⣔⢕⢄⢡⣾⣿⣿⣿⣿⣿⣿⣿⣦⡑⢕⢤⠱⢐
// ⢠⢕⠅⣾⣿⠋⢿⣿⣿⣿⠉⣿⣿⣷⣦⣶⣽⣿⣿⠈⣿⣿⣿⣿⠏⢹⣷⣷⡅⢐
// ⣔⢕⢥⢻⣿⡀⠈⠛⠛⠁⢠⣿⣿⣿⣿⣿⣿⣿⣿⡀⠈⠛⠛⠁⠄⣼⣿⣿⡇⢔
// ⢕⢕⢽⢸⢟⢟⢖⢖⢤⣶⡟⢻⣿⡿⠻⣿⣿⡟⢀⣿⣦⢤⢤⢔⢞⢿⢿⣿⠁⢕
// ⢕⢕⠅⣐⢕⢕⢕⢕⢕⣿⣿⡄⠛⢀⣦⠈⠛⢁⣼⣿⢗⢕⢕⢕⢕⢕⢕⡏⣘⢕
// ⢕⢕⠅⢓⣕⣕⣕⣕⣵⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣷⣕⢕⢕⢕⢕⡵⢀⢕⢕
// ⢑⢕⠃⡈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢃⢕⢕⢕
// ⣆⢕⠄⢱⣄⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢁⢕⢕⠕⢁
// ⣿⣦⡀⣿⣿⣷⣶⣬⣍⣛⣛⣛⡛⠿⠿⠿⠛⠛⢛⣛⣉⣭⣤⣂⢜⠕⢑⣡⣴⣿
// ⠀⠀⠀⣿⣿⡆⠀⠀⢸⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀ ⣾⣿⡆⠀⠀
// ⠀⠀⠀⣿⣿⡇⠀⠀⢸⣿⢰⣿⡆⠀⣾⣿⡆⠀⣾⣷ ⣿⣿⡇ ⠀⣿⣿⡇⠀
// ⠀⠀⠀⣿⣿⡇⠀⠀⢸⣿⠘⣿⣿⣤⣿⣿⣿⣤⣿⡇⢻⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀
// ⠀⠀⠀⣿⣿⡇⠀⠀⢸⡿⠀⢹⣿⣿⣿⣿⣿⣿⣿⠁⢸⣿⣇⠀⢀⣿⣿⠇⠀⠀
// ⠀⠀⠀⠙⢿⣷⣶⣶⡿⠁⠀⠈⣿⣿⠟⠀⣿⣿⠇⠀⠈⠻⣿⣶⣾⡿⠋⠀⠀⠀⠀
