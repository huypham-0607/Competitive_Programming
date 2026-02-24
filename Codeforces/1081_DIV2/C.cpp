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

int n,h,k,t;
int a[N];

bool check(int mid) {
    int round = mid/n;
    int lim = mid%n;

    int cur = t*round;

    if (lim!=0) {
        int mn = INF;
        for (int i=1; i<=lim; i++){
            mn = min(a[i],mn);
            cur += a[i];
        }
        int mx = 0;
        for (int i=lim+1; i<=n; i++) {
            mx = max(a[i],mx);
        }
        cur += max(0LL,mx-mn);
    }
    // cout << mid << " " << cur << endl;
    return (cur>=h);
}

void solve(){
    // cerr << "meow" << endl;
    cin >> n >> h >> k;
    t = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        t += a[i];
    }
    // cerr << t << endl;
    int l = 1;
    int r = (h/t+1)*n;
    // cerr << "meow" << endl;
    int ans = r+1;
    int tme = 0;

    // cout << l << " " << r << endl;

    while (l<=r) {
        int mid = (l+r)/2;
        int tmp = mid+((mid-1)/n)*k;
        if (check(mid)) {
            ans = mid;
            tme = tmp;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    cout  << tme << endl;
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

