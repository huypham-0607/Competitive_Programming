/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
vector<int> adj[N];
int deg[N];
int flag[N];
int vis[N];

void solve(){
    cin >> n >> m;
    int sum = 0;
    priority_queue<pii> pq;
    for (int i=2; i<=n; i++){
        sum += (n/i);
        deg[i]++;
        for (int j=2*i; j<=n; j+=i) {
            ++deg[i];
            ++deg[j];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        flag[i] = 1;
        pq.push({deg[i],i});
    }
    if (m > sum) {
        cout << "No" << endl;
        return;
    }

    // for (int i=1; i<=n; i++){
    //     cout << deg[i] << " ";
    // }
    // cout << endl;

    int cnt = 0;
    while (!pq.empty()) {
        int u = pq.top().se;
        int val = pq.top().fi;

        pq.pop();

        if (vis[u]) continue;
        if (val != deg[u]) continue;

        vis[u] = true;
        // cout << sum << " " << u << " " << deg[u] << endl;

        if (sum - deg[u] >= m) {
            ++cnt;
            flag[u] = 0;
            for (auto v:adj[u]) {
                if (!vis[v] && flag[v]) {
                    --deg[v];
                    pq.push({deg[v],v});
                }
            }
            sum -= deg[u];
        }
    }

    if (sum != m) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        cout << n-cnt << endl;
        cout << 1 << " ";
        for (int i=1; i<=n; i++){
            if (flag[i]) cout << i << " ";
        }
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

