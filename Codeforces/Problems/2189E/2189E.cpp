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

void solve(){
    cin >> n;
    vector<int> a(n+2);
    vector<int> pref0(n+2),suf0(n+2);
    vector<int> pref1(n+2),suf1(n+2);
    vector<int> pref(n+2,0), suf(n+2,0);
    int t = 0;
    for (int i=1; i<=n; i++){
        char c; cin >> c;
        a[i] = c-'0';
        if (a[i] == 0) ++t;
        else --t;
    }
    for (int i=1; i<=n; i++){
        pref0[i] = pref0[i-1];
        pref1[i] = pref1[i-1];
        if (a[i] == 0) {
            ++pref0[i];
        }
        else ++pref1[i];
    }
    for (int i=n; i>0; i--){
        suf0[i] = suf0[i+1];
        suf1[i] = suf1[i+1];
        if (a[i] == 0) {
            ++suf0[i];
        }
        else ++suf1[i];
    }

    if (pref1[n] == 0) {
        cout << -1 << endl;
        return;
    }

    if (n==1) {
        cout << 0 << endl;
        return;
    }

    int ans = 4;
    if (t<=0) ans = 1;

    int val = 1;
    for (int i=1; i<=n; i++){
        pref[i] = pref[i-1];
        if (a[i] == 0) --val;
        else ++val;
        if (val > 0) val = 1;
        pref[i] = min(pref[i],val);
    }

    val = 1;
    for (int i=n; i>0; i--){
        suf[i] = suf[i+1];
        if (a[i] == 0) --val;
        else ++val;
        if (val>0) val = 1;
        suf[i] = min(suf[i],val);
    }

    for (int i=1; i<=n; i++){
        if (a[i] == 0) continue;
        int l = pref[i-1];
        if (pref0[i-1]) l = min(l,-1LL);
        int r = suf[i+1];
        if (suf0[i+1]) r = min(r,-1LL);

        // cout << l << " " << r << endl;
        if (t+l <= 0) ans = min(ans,2LL);
        if (t+r <= 0) ans = min(ans,2LL);
        if (t+l+r <= 0) ans = min(ans,3LL); 
    }

    cout << n-1+ans << endl;
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

