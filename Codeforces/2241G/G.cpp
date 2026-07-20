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
const int LG = 18;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];
int st[LG][N];

string convert_int128(__int128_t val) {
    string s;
    while (val!=0) {
        s+=char('0'+val%10);
        val/=10;
    }
    reverse(all(s));
    if (s.size() == 0) return "0";
    return s;
}

void solve(){
    cin >> n;
    ffor(i,1,n) cin >> a[i];
    a[n+1] = 1;
    ffor(lg,0,LG-1) st[lg][n+1] = 1;
    for (int i=n; i>0; i--){
        st[0][i] = a[i];
        for (int lg=1; lg<LG; lg++){
            int j = i+(1<<(lg-1));
            if (j>n) st[lg][i] = 1;
            else st[lg][i] = __gcd(st[lg-1][i],st[lg-1][j]);
        }
    }
    __int128_t ans = 0;
    ffor (i,1,n) {
        int cur = i;
        int gcd = a[i];
        int max_up = 0, max_down = 0, max_smaller_up=0, max_smaller_down=0;
        while (cur!=n) {
            int prev = cur;
            rfor(lg,LG-1,0){
                if (cur+(1<<lg)>n) continue;
                if (__gcd(gcd,st[lg][cur+1])==gcd) {
                    cur += (1<<lg);
                }
            }
            ans += (cur-prev)*min({max_up,max_down,max_smaller_down+max_smaller_up});
            if (cur!=n) {
                int down = a[cur+1]%gcd, up = gcd-(a[cur+1]%gcd);
                max_up = max(max_up,up);
                max_down = max(max_down,down);
                if (up<down) {
                    max_smaller_up = max(max_smaller_up,up);
                }
                else {
                    max_smaller_down = max(max_smaller_down,down);
                }
                gcd = __gcd(gcd,a[cur+1]);
            }

            // cout << i << " " << gcd << " " << cur << " " << convert_int128(ans) << endl;
        }
    }
    cout << convert_int128(ans) << endl;
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

