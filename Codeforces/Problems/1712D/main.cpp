/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
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
const int INF = 1e9;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k;

int a[N],b[N];

bool check(int x) {
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] <= (x-1)/2){
            b[i] = INF;
            ++cnt;
        }
        else b[i] = a[i];
    }

    int mn = 2;
    for (int i=1; i<n; i++){
        int lmeo = 0;
        if (b[i] < x) ++lmeo;
        if (b[i+1] < x) ++lmeo;
        mn = min(mn,lmeo);
    }
    cnt += mn;
//    cout << x << " " << cnt << endl;
    return (cnt<=k);
}

void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    int l = 1, r = INF;
    while (l<=r) {
        int mid = (l+r)/2;
        if (check(mid)) {
            ans=mid;
            l = mid+1;
        }
        else {
            r = mid-1;
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
