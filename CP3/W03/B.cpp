#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

typedef int int2;
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7;
const int LG = 30;
const long long LLINF = 1e18+3;

int n,m;
int v2[N];

vector<pii> query[LG];
vector<pair<pii,int>> qr;

void solve(){
    qr.clear();
    for (int lg=0; lg<LG;lg++){
        query[lg].clear();
    }
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int l,r,x; cin >> l >> r >> x;

        qr.push_back({{l,1},x});
        qr.push_back({{r+1,-1},x});
    }

    sort(all(qr));

    for (auto in:qr) {
        int pos = in.fi.fi;
        int val = in.fi.se;
        int x = in.se;

        for (int lg = 0; lg <LG;lg++){
            if (!(x&(1LL<<lg))) {
                query[lg].push_back({pos,val});
            }
        }
    }

    ll ans = 0;
    for (int lg=0; lg<LG; lg++){
        int idx = 0;
        int cur = 0;
        int cnt1 = 0;
        int cnt0 = 0;
        for (int i=1; i<=n; i++){
            while (idx!=query[lg].size() && query[lg][idx].fi == i) {
                cur+=query[lg][idx].se;
                ++idx;
            }
            if (cur == 0) ++cnt1;
            else ++cnt0;
        }

        // cout << lg << " " << cnt0 << " " << cnt1 << endl;

        if (cnt1) ans = (ans + 1LL*v2[cnt1-1]*v2[cnt0]%MD*(1LL<<lg)%MD)%MD;
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

    v2[0] = 1;
    for (int i=1; i<N; i++){
        v2[i] = v2[i-1]*2%MD;
    }

    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

