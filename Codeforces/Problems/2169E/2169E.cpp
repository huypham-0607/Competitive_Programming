/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "2169E"

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

const int N = 3e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int px[N],py[N];
int cost[N];

void solve(){
    cin >> n;
    vector<pii> qx1,qx2,qy1,qy2,qd1,qd2;
    vector<int> bx1,bx2,by1,by2,bd1,bd2;
    bx1.resize(n+10);
    bx2.resize(n+10);
    by1.resize(n+10);
    by2.resize(n+10);
    bd1.resize(n+10);
    bd2.resize(n+10);
    int mn = LLINF;
    int t = 0;
    for (int i=1; i<=n; i++){
        int val; cin >> val;
        px[i] = val;
        qx1.push_back({val,i});
        qx2.push_back({val,i});
    }
    for (int i=1; i<=n; i++){
        int val; cin >> val;
        py[i] = val;
        qy1.push_back({val,i});
        qy2.push_back({val,i});
    }
    for (int i=1; i<=n; i++){
        cin >> cost[i];
        t+=cost[i];
        mn = min(mn,cost[i]);
        qd1.push_back({px[i]-py[i],i});
        qd2.push_back({px[i]+py[i],i});
    }

    int ans = t-mn;
    // cerr << ans << endl;

    sort(all(qx1));
    sort(all(qx2),greater<pii>());
    sort(all(qy1));
    sort(all(qy2),greater<pii>());
    sort(all(qd1));
    sort(all(qd2));

    int bestx = -LLINF;
    int besty = -LLINF;

    int opt = -LLINF;
    for (auto [pos,idx]:qx1) {
        bx1[idx] = opt;
        bestx = max(bestx,2*pos-cost[idx]+opt);
        opt = max(opt,-2*pos-cost[idx]);
    }

    opt = -LLINF;
    for (auto [pos,idx]:qx2) {
        bx2[idx] = opt;
        bestx = max(bestx,-2*pos-cost[idx]+opt);
        opt = max(opt,2*pos-cost[idx]);
    }

    opt = -LLINF;
    for (auto [pos,idx]:qy1) {
        by1[idx] = opt;
        besty = max(besty,2*pos-cost[idx]+opt);
        opt = max(opt,-2*pos-cost[idx]);
    }

    opt = -LLINF;
    for (auto [pos,idx]:qy2) {
        by2[idx] = opt;
        besty = max(besty,-2*pos-cost[idx]+opt);
        opt = max(opt,2*pos-cost[idx]);
    }

    int bestd = -LLINF;

    opt = -LLINF;
    for (auto [pos,idx]:qd1) {
        bd1[idx] = opt;
        bestd = max(bestd,2*pos-cost[idx]+opt);
        opt = max(opt,-2*pos-cost[idx]);
    }

    opt = -LLINF;
    for (auto [pos,idx]:qd2) {
        bd2[idx] = opt;
        bestd = max(bestd,2*pos-cost[idx]+opt);
        opt = max(opt,-2*pos-cost[idx]);
    }

    ans = max(ans,t+bestx+besty);
    ans = max(ans,t+bestd);
    // cerr << bestx << " " << besty << " " << bestd << endl;
    // cerr << ans << endl;

    for (int idx=1; idx<=n; idx++){
        int res = -LLINF;
        int x1 = bx1[idx]  +2*px[idx];
        int x2 = bx2[idx]  -2*px[idx];
        int y1 = by1[idx]  +2*py[idx];
        int y2 = by2[idx]  -2*py[idx];

        res = max(res,x1+y1-cost[idx]);
        res = max(res,x1+y2-cost[idx]);
        res = max(res,x2+y1-cost[idx]);
        res = max(res,x2+y2-cost[idx]);

        ans = max(ans,t+res);
    }
    // cerr << ans << endl;
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
   cin >> testCount;
    while (testCount--){
        // cerr << "New Test: " << endl;
        solve();
    }

    return 0;
}

