/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "1106E"

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

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m,k;
multiset<pii,decltype(greater<pii>())> st;
ll dp[202][N];

void solve(){
    cin >> n >> m >> k;
    vector<pair<pii,pii>> v;
    for (int i=1; i<=k; i++) {
        int s,t,d,w;
        cin >> s >> t >> d >> w;
        v.push_back({{s,0},{w,d}});
        v.push_back({{t+1,1},{w,d}});
    }
    sort(all(v));

    for (int lvl = 0; lvl<=m; lvl++){
        for (int i=0; i<=n; i++){
            dp[lvl][i] = LLINF;
        }
    }
    dp[0][1] = 0;

    // for (int j=0; j<=m; j++){
    //     for (int i=1; i<=n; i++) {
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = LLINF;

    int idx = 0;
    for (int i = 1; i<=n; i++){
        cerr << i << endl;
        while (idx != v.size() && v[idx].fi.fi == i) {
            int op = v[idx].fi.se;
            pii val = v[idx].se;
            // cerr << "idx: " << idx << " " << op << endl;
            // cerr << val.fi << " " << val.se << " " << st.size() << endl;
            if (op == 0) {
                st.insert(val);
            }
            else {
                auto it = st.lower_bound(val);
                // cerr << (it == st.end()) << endl;
                st.erase(it);
            }

            ++idx;
        }
        int val=0, d=i;
        if (st.begin() != st.end()) {
            auto key = (*st.begin());
            val = key.fi;
            d = key.se;
        }
        for (int j=0; j<=m; j++){
            // cout << j << " " << i << " " << val << " " << d << endl;
            // cout << dp[j][i] << endl;
            if (dp[j][i] == LLINF) continue;
            

            int nxtpos = d+1;
            if (nxtpos > n){
                ans = min(ans,dp[j][i] + val);
            } else {
                dp[j][nxtpos] = min(dp[j][nxtpos],dp[j][i] + val);
            }

            if (j!=m) {
                if (i+1 > n){
                    ans = min(ans,dp[j][i]);
                } else {
                    dp[j+1][i+1] = min(dp[j+1][i+1],dp[j][i]);
                }
            }   
        }
    }

    // for (int j=0; j<=m; j++){
    //     for (int i=1; i<=n; i++) {
    //         if (dp[j][i] == LLINF) cout << "-" << " ";
    //         else cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
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

