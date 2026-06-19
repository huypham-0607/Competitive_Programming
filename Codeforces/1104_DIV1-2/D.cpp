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

const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int dp[N][3][3];
int p0[N],p1[N];

void solve(){
    cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            dp[0][i][j] = 0;
        }
    }
    for (int i=1; i<=n; i++){
        int val = s[i-1]-'0';
        p0[i] = p0[i-1];
        p1[i] = p1[i-1];
        if (val) ++ p1[i];
        else ++p0[i];
    }

    int last = 0;
    ffor(idx,1,n){
        int val = s[idx-1]-'0';

        if (val) {
            for (int i=0; i<3; i++){
                for (int j=0; j<3; j++){
                    dp[idx][i][j] = dp[idx-1][i][(j-1+3)%3];
                }
            }
            dp[idx][0][1]++;
        }
        else {
            for (int i=0; i<3; i++){
                for (int j=0; j<3; j++){
                    dp[idx][i][j] = dp[idx-1][(i-1+3)%3][j];
                }
            }
            dp[idx][1][0]++;
        }

        // for (int i=0; i<3; i++){
        //     for (int j=0; j<3; j++){
        //         cout << dp[idx][i][j] << " ";
        //     }
        //     cout << endl;
        // }

        if (idx>1 && s[idx-1] == s[idx-2]) {
            last = idx-1;
        }

        ++ans;

        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                int i2 = (i + p0[idx] - ((last)?p0[last]:0)+3)%3;
                int j2 = (j + p1[idx] - ((last)?p1[last]:0)+3)%3;

                if ((2*i2+j2)%3==1 || (i2+2*j2)%3==1) ans += dp[last][i][j];
            }
        }
        // cout << ans << " " << last << endl;
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

    int testCount = 1;
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

