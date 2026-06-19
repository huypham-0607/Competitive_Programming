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

int n,k,l;
string s;
int a[N];
int pref[N];
pii dp[N];

pii check(int x) {
    ffor(i,l,n) {
        pii val = {pref[i]-x+dp[i-l].fi,dp[i-l].se+1};
        dp[i] = max(dp[i-1],val);
    }
    return dp[n];
}

int relax() {
    int cur = 0;
    int t = 0;
    for (int i=1; i<=n; i++){
        // cout << a[i] << " ";
        if (a[i]) {
            ++cur;
            ++t;
        }
        if (i>l && a[i-l]) --cur;
        pref[i] = cur;
    }
    // cout << endl;

    int ans = 0;
    pii inans = {t,(int)1e13};
    int l = 1, r = n;
    while (l<=r) {
        int mid = (l+r)/2;
        pii in = check(mid);
        // cout << l << " " << r << " " << mid << " " << in.fi << " " << in.se << endl;
        if (in.se>=k) {
            ans = mid;
            inans = in;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    int w = inans.fi + ans*k;
    // cout << w << " " << t-w << endl;
    return t-w;
}

void solve(){
    cin >> n >> k >> l;
    cin >> s;
    for (int i=1; i<=n; i++){
        a[i] = ((s[i-1]>=97)?1:0);
    }
    
    int ans = relax();

    ffor (i,1,n) {
        a[i] = ((a[i])?0:1);
    }

    ans = min(ans,relax());
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

