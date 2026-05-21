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
pair<int,char> a[3];

void solve(){
    cin >> a[0].fi >> a[1].fi >> a[2].fi;
    a[0].se = 'R';
    a[1].se = 'G';
    a[2].se = 'B';
    sort(a,a+3,greater<pair<int,char>>());

    // for (int i=0; i<3; i++){
    //     cout << a[i].fi << " " << a[i].se << endl;
    // }

    int ans = a[0].fi + a[1].fi + a[2].fi;

    int l = ans/2 + ans%2;
    int r = ans/2;

    while (a[1].fi + a[2].fi < r) {
        --ans;
        l = ans/2 + ans%2;
        r = ans/2;
    }

    // cout << ans << endl;
    // cout << l << " " << r << endl;

    string sl,sr;
    for (int i=1; i<=l; i++){
        if (l-i >= a[0].fi) sl += a[2].se;
        else sl += a[0].se;
    }

    for (int i=1; i<=r; i++){
        if (i <= a[1].fi) sr += a[1].se;
        else sr += a[2].se;
    }
    string sans;
    for (int i=0; i<ans; i++){
        if (i%2==0){
            sans += sl[i/2]; 
        }
        else sans += sr[i/2];
    }
    cout << sans << endl;
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

