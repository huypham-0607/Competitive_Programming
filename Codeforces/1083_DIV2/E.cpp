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

const int N = 8010;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];
int pi[N];
int dp[N];

void calc_pi(int l) {
    pi[0] = 0;
    for (int i=1; l+i<n; i++){
        int cur = i;
        while (cur!=0){
            if (a[l+i]==a[l+pi[cur-1]]){
                pi[i] = pi[cur-1]+1;
                break;
            }
            cur = pi[cur-1];
        }
        if (cur == 0){
            if (a[l+i] == a[l+0]) pi[i] = 1;
            else pi[i] = 0;
        }
    }
}

void solve(){
    cin >> n;
    for (int i=0; i<=n; i++){
        dp[i] = 0;
    }
    dp[n] = 1;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=n-1; i>=0; i--) {
        calc_pi(i);
        // for (int j=i; j<n; j++){
        //     cout << pi[j-i] << " ";
        // }
        // cout << endl;
        for (int j=i; j<n; j++){
            if (pi[j-i] == 0) {
                dp[i] = (dp[i] + dp[j+1])%MD; 
            }
        }
    }
    cout << dp[0] << endl;
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

