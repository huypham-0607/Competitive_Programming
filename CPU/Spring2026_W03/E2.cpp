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

int n,m;

void solve(){
    cin >> n >> m;
    pii mx = {-LLINF,-LLINF};
    pii mn = {LLINF,LLINF};

    for (int i=1; i<=n; i++){
        int x; cin >> x;
        if (x > mx.fi) {
            mx.se = mx.fi;
            mx.fi = x;
        }
        else {
            if (x > mx.se) {
                mx.se = x;
            }
        }
        if (x < mn.fi) {
            mn.se = mn.fi;
            mn.fi = x;
        }
        else {
            if (x < mn.se) {
                mn.se = x;
            }
        }
    }
    // cout << mx.fi << " " << mx.se << endl;
    // cout << mn.fi << " " << mn.se << endl;

    int ans1 = -LLINF;
    int ans2 = LLINF;

    for (int i=1; i<=m; i++){
        int x; cin >> x;

        ans1 = max(ans1,x);
        ans2 = min(ans2,x);
    }

    int finans = LLINF;
    finans = min(finans,max({mx.se*ans1,mn.fi*ans2,mx.se*ans2,mn.fi*ans1}));
    finans = min(finans,max({mx.fi*ans1,mn.se*ans2,mx.fi*ans2,mn.se*ans1}));
    cout << finans << endl;
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

