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
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;

void solve(){
    n = 18;
    vector<int> lst;
    for (int mask=0; mask<(1<<(n-1)); mask++) {
        vector<int> v;
        int cnt = 0;
        for (int i=0; i<(n-1); i++){
            if (!((1<<i)&mask)){
                if (cnt!=0) {
                    v.push_back(cnt);
                }
                cnt = 0;
            }
            else ++cnt;
        }
        sort(all(v));
        int realmask = 0;
        int idx = 0;
        for (auto x:v) {
            for (int i=1; i<=x; i++){
                realmask ^= (1<<idx);
                ++idx;
            }
            ++idx;
        }
        lst.push_back(realmask);
    }
    sort(all(lst));
    lst.resize(unique(all(lst)) - lst.begin());

//    for (auto x:lst) {
//        cout << x << endl;
//    }

    cout << lst.size() << endl;
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
