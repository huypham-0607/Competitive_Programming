/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "tallbarn"

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

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k;
int a[N];

pair<ld,int> check(ld x) {
    ld g = 0;
    int gc = 0;
    // cout << "check: " << " " << x << endl; 
    for (int i=1; i<=n; i++){
        ld c = floor(((ld)sqrt((ld)(4*a[i])/x + 1)-1)/2)+1;
        // cout << i << " " << c << endl;
        g += (ld)a[i]/c + c*x;
        gc += c;
    }
    return {g,gc};
}

void solve(){
    cin >> n >> k;
    int t = 0;
    ffor(i,1,n) {
        cin >> a[i];
        t += a[i];
    }
    if (k == n) {
        cout << t << endl;
        return;
    }

    ld ans = 0;
    pair<ld,int> inans = {(ld)1e13,(ld)1e13};
    ld l = (ld)0, r = (ld)1e13;
    for (int epoch = 0; epoch<250; epoch++){
        ld mid = (l+r)/2;
        auto in = check(mid);
        // cout << mid << " " << in.se << endl;
        if (in.se >= k) {
            inans = in;
            ans = mid;
            l = mid;
        }
        else {
            r = mid;
        }
    }
    
    // cout << fixed << setprecision(6) << ans << " " <<  inans.fi << " " << inans.se << endl;

    ll res = round(inans.fi - k*ans);
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".in","r")){
        freopen(TEXT".in","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

