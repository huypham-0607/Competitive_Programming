/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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

const int N = 5e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k;
int a[N];
int pref[N];
int prefsq[N];

void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for (int i=1; i<=n; i++){
        pref[i] = pref[i-1] + a[i];
        prefsq[i] = prefsq[i-1] + a[i]*a[i];
    }

    ld ans = LLINF;
//    cout << fixed << setprecision(9) << ans << endl;
    for (int i=1; i<=n; i++){
        if (i>=k){
            ld ave = (ld)((pref[i] - pref[i-k]))/k;
            ld avesq = (ld)((pref[i] - pref[i-k])*(pref[i]-pref[i-k]))/(k);
            ld tmp = avesq + (prefsq[i] - prefsq[i-k]);
            tmp = tmp + (ld)ave*-2*(pref[i] - pref[i-k]);
//            cout << fixed << setprecision(9) << tmp << endl;
            ans = min(ans,tmp);
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
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

