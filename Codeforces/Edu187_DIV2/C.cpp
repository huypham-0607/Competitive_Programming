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
const int LG = 60;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int s,mask;

bool check(int val) {
    bool activated = false;
    // cout << "check: " << val << endl;
    // for (int lg = LG-1; lg>=0; lg--) {
    //     cout << ((s&(1LL<<lg)) ? 1 : 0) << " " << ((val&(1LL<<lg)?1:0)) << endl;
    // }
    int sum = 0;
    for (int lg = 0; lg<LG; lg++) {
        sum/=2;
        if (mask&(1LL<<lg)) {
            sum += val;
        }

        if (s&(1LL<<lg)) {
            if (sum == 0) {
                return false;
            }
            sum -= 1;
        }
    }
    return true;
}

void solve(){
    cin >> s >> mask;

    int l = 0;
    int r = (int)1e18;

    bool activated = false;
    for (int lg=0; lg<LG; lg++) {
        if (mask&(1LL<<lg)) {
            activated = true;
        }
        if (s&(1LL<<lg)) {
            if (!activated) {
                cout << -1 << endl;
                return;
            }
        }
    }

    int ans = r+1;
    while (l<=r) {
        int mid = (l+r)/2;
        // cout << "mid: " << mid << endl;

        if (check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
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

