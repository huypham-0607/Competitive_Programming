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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
// Count of excess brackets of i,j state
// i: 0 = round brac; 1 = square brac
// j: 0 = left excess; 1 = right excess
int cnt[2][2];
char a[N];
int dp[2][N];

void solve(){
    cin >> n;
    string s; cin >> s;
    for (int i=0; i<n; i++){
        a[i] = 'A';
    }
    int cur = 0;
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            cnt[i][j] = 0;
        }
    }
    
    for (int i=0; i<n; i++){
        if (s[i] == '(') ++cur;
        if (s[i] == ')') --cur;
        if (cur < 0) {
            ++cnt[0][0];
            cur = 0;
            a[i] = ')';
        }
    }

    cur = 0;
    for (int i=n-1; i>=0; i--){
        if (s[i] == ')') ++cur;
        if (s[i] == '(') --cur;
        
        if (cur < 0) {
            ++cnt[0][1];
            cur = 0;
            a[i] = '(';
        }
    }

    cur = 0;
    for (int i=0; i<n; i++){
        if (s[i] == '[') ++cur;
        if (s[i] == ']') --cur;
        if (cur < 0) {
            ++cnt[1][0];
            cur = 0;
            a[i] = ')';
        }
    }

    cur = 0;
    for (int i=n-1; i>=0; i--){
        if (s[i] == ']') ++cur;
        if (s[i] == '[') --cur;
        if (cur < 0) {
            ++cnt[1][1];
            cur = 0;
            a[i] = '(';
        }
    }

    int lcnt = 0;
    int rcnt = 0;

    int validcnt = 0;
    cur = 0;
    for (int i=0; i<n; i++){
        if (a[i] == '(') {
            ++cur;
            ++lcnt;
        }
        if (a[i] == ')') {
            --cur;
            ++rcnt;
            if (cur >= 0) validcnt++;
            else cur = 0;
        }
    }

    int res = INF;

    for (int i=0; i <= validcnt; i++){
        int l = lcnt - i;
        int r = rcnt - i;
        res = min(res,l/2 + l%2 + r/2 + r%2 + i);
    }
    cout << res << endl;
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

