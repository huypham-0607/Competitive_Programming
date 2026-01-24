#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

mt19937_64 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7;
const long long LLINF = 1e18+3;

ll rd(ll l, ll r){
    return uniform_int_distribution<ll> (l,r) (mt);
}

int n,m,p;
int a[N];
int SOS[(1<<15)+10];

pii check(int x) {
    // cout << "x: " << x << endl;
    vector<int> pos;
    for (int lg=0; lg<m; lg++){
        if (a[x]&(1LL<<lg)) pos.push_back(lg);
    }

    // for (auto val:pos) cout << val << " ";
    // cout << endl;

    memset(SOS,0,sizeof(SOS));

    for (int i=1; i<=n; i++){
        int val = 0;
        for (int lg=0; lg<pos.size(); lg++) {
            if (a[i]&(1LL<<pos[lg])) val+=(1LL<<lg);
        }
        SOS[val]++;
    }

    for (int lg=0; lg<p; lg++){
        for (int mask=(1LL<<p)-1; mask>=0; mask--){
            if (!(mask&(1LL<<lg))) SOS[mask] += SOS[mask^(1LL<<lg)];
        }
    }

    int res = 0;
    int msk = 0;
    for (int mask=0; mask<(1LL<<p); mask++){
        // cout << SOS[mask] << " ";
        if (SOS[mask]>=(n+1)/2) {
            int tmp = (int)__builtin_popcountll(mask);
            if (res < tmp) {
                res = tmp;
                msk = mask;
            }
        }
    }
    // cout << endl;

    int realmask = 0;
    for (int lg=0; lg<pos.size(); lg++){
        if (msk&(1LL<<lg)) realmask+=(1LL<<pos[lg]);
    }
    return make_pair(res,realmask);
}

void solve(){
    cin >> n >> m >> p;
    for (int i=1; i<=n; i++){
        string s; cin >> s;
        int val = 0;
        for (int lg=0; lg<m; lg++){
            if (s[lg] == '1') val+=(1LL<<lg); 
        }
        a[i] = val;
    }

    int ans = 0;
    int mask = 0;
    for (int i=1; i<=67; i++){
        int x = rd(1,n);
        pii in = check(x);
        if (ans < in.fi) {
            ans = in.fi;
            mask = in.se;
        }
    }

    for (int lg=0; lg<m; lg++){
        if (mask&(1LL<<lg)) cout << "1";
        else cout << "0";
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
    // cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

