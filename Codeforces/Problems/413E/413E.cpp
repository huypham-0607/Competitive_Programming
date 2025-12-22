/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "413E"

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

struct Fenwick{
    int n;
    vector<int> BIT;

    Fenwick(int _n=0): n(_n){
        BIT.resize(n+10);
    }

    void Init (int _n, int val=0){
        BIT.resize(n+10,0);
    }

    void update(int idx, int val){
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int getPoint(int idx){
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    int getVal(int l, int r){
        return (getPoint(r)-getPoint(l-1));
    }
};

int n,q;
int pre[N];
int pre2[N];
int a[N][2];
int ans[N];

void solve(){
    cin >> n >> q;
    for (int i=0; i<=1; i++) {
        for (int j=1; j<=n; j++){
            char c; cin >> c;
            if (c == 'X') a[j][i] = 1;
            else a[j][i] = 0;
        }
    }

    vector<pair<pair<pii,pii>,int>> v;
    for (int i=1; i<=q; i++){
        int x,y; cin >> x >> y;
        if ((x-1)%n > (y-1)%n) swap(x,y);
        pii p1 = {(y-1)%n+1,(y-1)/n};
        pii p2 = {(x-1)%n+1,(x-1)/n};
        v.push_back({make_pair(p1,p2),i});
    }

    sort(all(v));

    Fenwick BIT(n);

    // cout << v.size() << " " << n << " " << q << endl;
    // for (auto in:v) {
    //     cout << in.fi.fi.fi << " " << in.fi.se.fi << endl;
    // }

    // for (int i=0; i<=1; i++){
    //     for (int j=1; j<=n; j++){
    //         cout << a[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    int cutoff = 0;
    int cur = -1;

    int idx = 0;
    int prev = 0;
    for (int i=1; i<=n; i++){
        if (a[i][0] && a[i][1]) {
            cutoff = i;
            cur = -1;
            continue;
        }
        else if ((a[i][0] && a[i-1][1]) || (a[i][1] && a[i-1][0])) {
            cutoff = i-1;
            cur = -1;
        }
        int val = -1;
        if (a[i][0]) val = 1;
        else if (a[i][1]) val = 0;

        if (val != -1) {
            if (val == cur) {
                BIT.update(prev,-1);
            }
            prev = i;
            cur = val;
            BIT.update(i,1);
        }

        while (idx!=v.size() && v[idx].fi.fi.fi == i) {
            pii e = v[idx].fi.fi;
            pii s = v[idx].fi.se;
            int id = v[idx].se;
            ++idx;

            if (s.fi <= cutoff) {
                ans[id] = -1;
                continue;
            }

            int sum = BIT.getVal(s.fi,e.fi);

            if (sum == 0) {
                int delta = e.fi - s.fi;
                if (s.se == e.se) ans[id] = delta;
                else ans[id] = delta+1;
                continue;
            }

            //cout << cur << endl;
            int r = cur;
            int l = (cur + (sum - 1))%2;
            // cout << pre[i] - pre[s.fi-1] << endl;
            int res = sum - 1 + (e.fi-s.fi);
            // cout << res << endl;
            // cout << l << " " << r << " " << s.se << " " << e.se << endl;
            if (s.se != l) res++;
            if (e.se != r) res++;
            ans[id] = res;
        }
    }
    for (int i=1; i<=q; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
    // cin.tie(0) -> sync_with_stdio(0);
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

