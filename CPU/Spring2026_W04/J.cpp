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

const int N = 500+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int last[26];
int cnt[26];
int dp[N][N];

void solve(){
    cin >> n;
    string s; cin >> s;
    s = "#"+s;
    for (int i=1; i<=n; i++){
        dp[i][i] = 1;
    }
    for (int delta = 1; delta < n; delta++){
        for (int i=1; i+delta <= n; i++){
            int j = i+delta;
            int cl = s[i] - 'a';
            int cr = s[j] - 'a';
            dp[i][j] = INF;
            for (int idx=i; idx<j; idx++){
                dp[i][j] = min(dp[i][j], dp[i][idx] + dp[idx+1][j] + ((cl == cr)?-1:0));
            }
            
            // for (auto cidx = 0; cidx < 26; cidx++){
            //     cnt[cidx] = 0;
            //     last[cidx] = i-1;
            // }

            // for (int idx=i; idx<=j; idx++){
            //     int cidx = s[idx]-'a';
            //     cnt[cidx] += dp[last[cidx]+1][idx-1];
            //     last[cidx] = idx;
            // }

            // for (int cidx = 0; cidx < 26; cidx++){
            //     cnt[cidx] += dp[last[cidx]+1][j];
            //     dp[i][j] = min(dp[i][j],cnt[cidx]+1);
            // }
        }
    }  

    cout << dp[1][n] << endl;
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

