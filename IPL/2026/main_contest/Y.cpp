/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
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
const int LG = 18;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;

vector<int> stamp[LG];
vector<int> e[LG];
int dp[(1<<LG)+10];
int t[N];

int get(int idx, int ed) {
    int i = upper_bound(all(stamp[idx]),ed)-stamp[idx].begin();
    return e[idx][i];
}

void solve(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> t[i];
    }
    for (int i=1; i<=m; i++){
        int s,u; cin >> s >> u;
        stamp[s-1].push_back(u);
    }
    for (int i=0; i<n; i++){
        sort(all(stamp[i]));
        e[i].resize(stamp[i].size()+1);
        e[i][0] = 0;
        for (int j=1; j<=stamp[i].size(); j++){
            e[i][j] = max(e[i][j-1],stamp[i][j-1]) + t[i]; 
        }
    }

    dp[0] = 0;
    for (int mask=1; mask<(1<<n); mask++){
        dp[mask] = LLINF;
        // cout << "mask: " << mask << endl;
        for (int idx=0; idx<n; idx++){
            if (mask&(1<<idx)) {
                // cout << "idx: " << idx << endl;
                int ed = dp[mask^(1<<idx)];
                int w = get(idx,ed);

                // cout << ed << " " << w << endl;
                
                dp[mask] = min(dp[mask],max(ed,w)+t[idx]);
            }
        }
        // cout << dp[mask] << endl;
    }

    // for (int i=0; i<n; i++){
    //     cout << "shop: " << i << endl;
    //     for (auto x:stamp[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    //     for (auto x:e[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    
    cout << dp[(1<<n)-1] << endl;
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

