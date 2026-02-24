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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];

struct lineq {
    int a,b,c,id;

    lineq(int _a=0, int _b=0, int _c=0, int _id = 0): a(_a), b(_b), c(_c), id(_id) {};

    bool operator< (const lineq &other) const {
        if (a == other.a) {
            if (b == other.b) {
                return c < other.c;
            }
            else return b < other.b;
        }
        else return a < other.a; 
    } 
};

lineq eq[N];

bool is_intersect(lineq &x, lineq &y) {
    int da = x.a - y.a;
    int db = x.b - y.b;
    int dc = x.c - y.c;

    if (da == 0) {
        if (db == 0) return false;
        else return true;
    }

    int delta = db*db - 4*da*dc;
    // cout << delta << endl;
    return (delta>=0);
}

vector<int> adj1[N], adj2[N];
int deg1[N], deg2[N];
int dp1[N],dp2[N];
int ans[N];

void calc(vector<int> adj[], int deg[], int dp[]) {
    deque<int> dq;
    for (int i=1; i<=n; i++){
        if (deg[i] == 0) {
            dq.push_back(i);
        }
    }

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (auto v:adj[u]) {
            dp[v] = max(dp[v],dp[u]+1);
            deg[v]--;
            if (deg[v] == 0) dq.push_back(v);
        }
    }
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        adj1[i].clear();
        adj2[i].clear();
        deg1[i] = 0;
        deg2[i] = 0;
        dp1[i] = 0;
        dp2[i] = 0;
    }
    for (int i=1; i<=n; i++){
        int a,b,c; cin >> a >> b >> c;
        eq[i] = lineq(a,b,c,i);
    }
    sort(eq+1,eq+1+n);

    // for (int i=1; i<=n; i++){
    //     cout << eq[i].id << endl;
    // }

    for (int i=1; i<=n; i++){
        // cout << eq[i].id << endl;
        for (int j=i-1; j>0; j--) {
            // cout << i << " " << j << endl;
            if (!is_intersect(eq[i],eq[j])) {
                adj1[j].push_back(i);
                deg1[i]++;
                adj2[i].push_back(j);
                deg2[j]++;
            }
        }
    }

    // for (int i=1; i<=n; i++){
    //     for (auto x:adj1[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    calc(adj1,deg1,dp1);
    calc(adj2,deg2,dp2);

    for (int i=1; i<=n; i++){
        int res = dp1[i] + dp2[i] + 1;
        ans[eq[i].id] = res;
    }
    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

