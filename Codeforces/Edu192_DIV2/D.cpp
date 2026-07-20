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
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 5e3+10;
const int INF = 1e9+7;
const int MD = 10; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
int a[N],b[N];
pair<int,pii> dp[N][N];

void solve(){
    string s; cin >> s;
    n=s.size();
    frep(i,0,s.size()){
        a[i] = s[i]-'0';
    }
    cin >> s; m = s.size();
    frep(i,0,s.size()) b[i] = s[i]-'0';
    
    frep(i,0,n){
        frep(j,0,m){
            dp[i][j] = {-1,{0,0}};
        }
    }

    int ans = 0;
    dp[0][0] = {0,{a[0],b[0]}};
    frep(i,0,n){
        frep(j,0,m){
            if (i==n-1 && j==m-1) {
                auto val = dp[i][j];
                if (val.se.fi == val.se.se){
                    ++val.fi;
                    ans = val.fi;
                    if (ans == 0) ans = -1;
                }
                else ans = -1;
            }
            if (i+1!=n) {
                auto val = dp[i][j];
                val.se.fi = (val.se.fi+a[i+1])%MD;
                dp[i+1][j] = max(dp[i+1][j],val);
            }
            if (j+1!=m) {
                auto val = dp[i][j];
                val.se.se = (val.se.se+b[j+1])%MD;
                dp[i][j+1] = max(dp[i][j+1],val);
            }
            if (i+1!=n && j+1!=m) {
                auto val = dp[i][j];
                if (val.se.fi == val.se.se){
                    ++val.fi;
                }
                val.se.fi = (val.se.fi+a[i+1])%MD;
                val.se.se = (val.se.se+b[j+1])%MD;
                dp[i+1][j+1] = max(dp[i+1][j+1],val);
            }
        }
    }

    // frep(i,0,n){
    //     frep(j,0,m){
    //         cout << dp[i][j].fi << "," << dp[i][j].se.fi << "," << dp[i][j].se.se << " ";
    //     }
    //     cout << endl;
    // }

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
        solve();
    }

    return 0;
}

