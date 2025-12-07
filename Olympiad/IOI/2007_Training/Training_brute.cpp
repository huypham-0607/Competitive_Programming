#include <bits/stdc++.h>
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define chmax(a, b) a=max(a,b)
using namespace std;
using PII = pair <int, int>;
using VI = vector <int>;

const int N = 1001;
const int M = 5001;
const int K = 10;

int n, m, sum;
PII par[N];
int jump[N][K+1];
vector <int> paths[N];
int deg[N], order[N], lvl[N], ptr;
struct Edge {
	int a, b, c, lca;
	bool operator <(const Edge& x) const {
		return order[lca] < order[x.lca];
	}
};
vector <Edge> edges;
void dfs(int pos = 1, int p = 1) {
	jump[pos][0] = p;
	for (auto& el : paths[pos]) {
		if (el == p) continue;
		lvl[el] = lvl[pos]+1;
		par[el] = {pos, 1<<(deg[pos]++)};
		dfs(el, pos);
	}
	order[pos] = ptr++;
}
int Jump(int a, int b) {
	for (int j = 0; j <= K; j++)
		if (b & (1<<j)) a = jump[a][j];
	return a;
}
int LCA(int a, int b) {
	if (lvl[a] < lvl[b]) swap(a, b);
	a = Jump(a, lvl[a]-lvl[b]);
	if (a == b) return a;
	for (int j = K; j >= 0; j--) {
		if (jump[a][j] != jump[b][j]) {
			a = jump[a][j];
			b = jump[b][j];
		}
	}
	return jump[a][0];
}
int dp[N][1<<K], mask1, mask2;
void solve() {
	for (auto& edge : edges) {
		int a = edge.a, b = edge.b, cur = edge.c, lca = edge.lca;
		if (lvl[a]%2 != lvl[b]%2 && cur != 0) continue;

		// cutting edge a to b;

		for (mask1 = 0; a != lca; tie(a, mask1) = par[a]) cur += dp[a][mask1];
		for (mask2 = 0; b != lca; tie(b, mask2) = par[b]) cur += dp[b][mask2];

		mask1 |= mask2;
		for (int mask = (1<<deg[lca])-1; mask >= 0; mask--) {
			if (mask & mask1) continue;
			chmax(dp[lca][mask], cur + dp[lca][mask|mask1]);
		}
	}
}
signed main() {
    freopen("training.inp","r",stdin);
    freopen("training.ans","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (!c) {
			paths[a].pb(b);
			paths[b].pb(a);
		}
		sum += c;
		edges.pb({a, b, c, 0});
	}
	par[1] = {1, 0};
	dfs();
	for (int j = 1; j <= K; j++)
	for (int i = 1; i <= n; i++)
		jump[i][j] = jump[jump[i][j-1]][j-1];

	for (auto& edge : edges) {
		if (lvl[edge.a]%2 != lvl[edge.b]%2 && edge.c != 0) continue; // we must block this edge
		edge.lca = LCA(edge.a, edge.b);
	}
	sort(ALL(edges));
	solve();
	cout << sum - dp[1][0] << "\n";
}
