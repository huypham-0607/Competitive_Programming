/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
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
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 4e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k,d,s,m;
int a[N];
vector<int> cyc[N];
vector<int> cycpref[N];
int sz[N];
int t[N];
int pref[N];
int val[N];
int vis[N];
int winval[N];

void DFS(int u, int id) {
    vis[u] = true;
    cyc[id].push_back(u);
    int v = (u-1+k)%n+1;
    
    if (!vis[v]) {
        DFS(v,id);
    }
}

void solve(){
    cin >> n >> k >> d >> s;
    k%=n;
    // cout << k << endl;
    m = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    for (int i=n+1; i<=2*n; i++){
        a[i] = a[i-n];
        pref[i] = pref[i-1] + a[i];
    }

    for (int i=1; i<=n; i++){
        val[i] = pref[i+s-1] - pref[i-1];
    }

    for (int i=1; i<=n; i++){
        if (!vis[i]) {
            ++m;
            DFS(i,m);
        }
    }

    // for (int i=1; i<=n; i++){
    //     cout << val[i] << " ";
    // }
    // cout << endl;

    // if (n == 8190) {
    //     cout << m << endl;
    // }

    for (int id=1; id<=m; id++){
        sz[id] = cyc[id].size();
        for (int i=0; i<sz[id]; i++){
            cyc[id].push_back(cyc[id][i]);
            t[id] += val[cyc[id][i]];
        }
        // for (int i=0; i<cyc[id].size(); i++){
            // cerr << cyc[id][i] << " ";
        // }
        // cerr << endl;
        cycpref[id].resize(cyc[id].size(),0);
        for (int i=0; i<cyc[id].size(); i++){
            cycpref[id][i] = val[cyc[id][i]];
            if (i!=0) cycpref[id][i] += cycpref[id][i-1];
        }
        for (int i=0; i<sz[id]; i++){
            winval[cyc[id][i]] = t[id]*(d/sz[id]);
            int delta = d%sz[id];
            if (delta) {
                winval[cyc[id][i]] += cycpref[id][i+delta-1];
                if (i!=0) winval[cyc[id][i]] -= cycpref[id][i-1]; 
            }
        }
    }

    // for (int i=1; i<=n; i++){
    //     cout << winval[i] << " ";
    // }
    // cout << endl;

    int ans = -LLINF;

    deque<pii> dq;

    int max_pos_req = n-s+1;
    int max_day_range = n-d+1;

    for (int id=1; id<=m; id++) {
        dq.clear();
        for (int i=0; i<cyc[id].size(); i++){
            while (!dq.empty() && dq.front().se <= i-max_day_range) dq.pop_front();
            while (!dq.empty() && dq.back().fi >= cyc[id][i]) dq.pop_back();
            dq.push_back({cyc[id][i],i});

            // if (n == 8190 && k == 0) {
            //     if (dq.front().fi != cyc[id][i]) {
            //         cout << cyc[id][i] << " " << dq.front().fi << " " << max_pos_req << endl;
            //     }
            // }

            // cout << cyc[id][i] << " " << dq.front().fi << endl;

            if (dq.front().fi <= max_pos_req) {
                ans = max(ans,winval[cyc[id][i]]);
            }
        }
    }

    cout << ans << endl;
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