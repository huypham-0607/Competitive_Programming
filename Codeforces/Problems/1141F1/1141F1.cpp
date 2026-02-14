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

const int N = 1510;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
int a[N];
int dp[N*N];
vector<pii> store[N*N];

void solve(){
    cin >> n;
    vector<int> nen;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        int val = 0;
        for (int j=i; j<=n; j++) {
            val+=a[j];
            nen.push_back(val);
        }
    }
    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());
    m = nen.size();
    // for (int i=0; i<m; i++){
    //     cout << nen[i] << " ";
    // }
    // cout << endl;


    for (int i=1; i<=n; i++) {
        int val = 0;
        for (int j=i; j>0; j--) {
            val+=a[j];
            int idx = lower_bound(all(nen),val) - nen.begin()+1;
            if (!store[idx].size() || store[idx].back().se < j) {
                dp[idx]++;
                store[idx].push_back({j,i});
            }

        }
    }
    int t_idx = 0;
    int ans = 0;
    for (int idx=1; idx<=m; idx++) {
        if (ans < dp[idx]) {
            ans = dp[idx];
            t_idx = idx;
        }
    }
    cout << ans << endl;
    // cout << t_idx << endl;

    for (auto [l,r]:store[t_idx]) {
        cout << l << " " << r << endl;
    }

    // for (int idx=1; idx<=m; idx++) {
    //     for (int i=1; i<=n; i++){
    //         cout << dp[idx][i] << " ";
    //     }
    //     cout << endl;
    // }
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

