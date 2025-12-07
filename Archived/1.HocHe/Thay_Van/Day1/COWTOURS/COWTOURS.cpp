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
const int N = 160;
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
int n;
double dist[N][N];
pair<int,int> a[N];
int adj[N][N];
double diam[N];
double diamcomp[N];
vector<int> rawr[N];
bool vis[N];
int cmp[N];

double calc(int x, int y, int u, int v){
    int cock = abs(x-u);
    int balls = abs(y-v);
    return sqrt(cock*cock+balls*balls);
}

void BFS(int s, int idx){
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        cmp[u] = idx;
        rawr[idx].push_back(u);

        for (int i=1; i<=n; i++){
            if (dist[u][i]>=INF) continue;
            diam[u] = max(diam[u],dist[u][i]);
            diamcomp[idx] = max(diamcomp[idx],dist[u][i]);
            if (adj[u][i]){
                if (!vis[i]) q.push(i);
            }
        }
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            char c;
            cin >> c;
            if (c == '1') adj[i][j] = 1;
            else adj[i][j] = 0;
            if (adj[i][j]) dist[i][j] = calc(a[i].fi,a[i].se,a[j].fi,a[j].se);
            else dist[i][j] = INF;
        }
    }

    for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				double new_dist = dist[i][k] + dist[k][j];
				if (new_dist < dist[i][j]) {
					dist[i][j] = dist[j][i] = new_dist;
				}
			}
		}
	}

    int cnt = 0;
    for (int i=1; i<=n; i++){
        if (!vis[i]) BFS(i,++cnt);
    }

    double ans = INF;

    for (int i=1; i<=cnt; i++){
        for (int j=i+1; j<=cnt; j++){
            double new_diam = INF;
            double woof = max(diamcomp[i],diamcomp[j]);

            for (auto u:rawr[i]){
                for (auto v:rawr[j]){
                    new_diam = min(new_diam,diam[u]+diam[v]+calc(a[u].fi,a[u].se,a[v].fi,a[v].se));
//                    cout << new_diam << endl;
                }
            }
//            cout << new_diam << endl;
            ans = min({ans,max({new_diam,woof})});
        }
    }

//    for (int i=1; i<=n; i++){
//        cout << diam[i] << endl;
//    }
    cout << fixed << setprecision(6) <<  ans << endl;
}

/*Driver Code*/
signed main(){
//    freopen("COWTOURS.INP","r",stdin);
//    freopen("COWTOURS.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
