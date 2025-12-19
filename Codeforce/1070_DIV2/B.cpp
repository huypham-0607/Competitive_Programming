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

const int N = 4e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
vector<int> v;
int a[N];

void solve(){
    cin >> n;
    v.clear();
    int pre = 0;
    int ans = 0;

    for (int i=1; i<=n; i++){
        char c; cin >> c;
        if (c == '1') {
            a[i] = 1;
            a[i+n] = 1;
        }
        else {
            a[i] = 0;
            a[i+n] = 0;
        }
    }

    for (int i=1; i<=2*n; i++){
        if (a[i] == 1) {
            if (pre!=0);
            ans = max(ans,pre);
            v.push_back(pre);
            pre = 0;
        }
        else ++pre;
    }
    if (pre!=0){
        v.push_back(pre);
        ans = max(ans,pre);
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

