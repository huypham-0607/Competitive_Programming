/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "cowpatibility"

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
vector<int> a[N];
map<vector<int>,int> mp;

void solve(){
    cin >> n;
    int ans = 0;
    for (int i=1; i<=n; i++){
        for (int idx=0; idx<5; idx++){
            int x; cin >> x;
            a[i].push_back(x);
        }
        sort(all(a[i]));
        for (int mask=1; mask<(1<<5); ++mask){
            vector<int> val;
            for (int lg=0; lg<5; lg++){
                if ((1<<lg)&mask) val.push_back(a[i][lg]);
            }
            int si = ((__builtin_popcountll(mask)%2)? 1 : -1);
            ans+=si*mp[val];
            mp[val]++;
        }
    }
    int total = (n*(n-1))/2;
//    cout << total << " " << ans << endl;
    cout << total - ans << endl;
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
