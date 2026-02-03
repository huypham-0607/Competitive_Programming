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

int n,m,k;
vector<pii> pts;
int dp[N];

void solve(){
    pts.clear();
    cin >> n >> m >> k;
    for (int i=1; i<=k; i++){
        int x,y; cin >> x >> y;
        pts.push_back({y,x});
    }

    sort(all(pts));

    int unit = 0;
    int dictate = 0;

    int flag = 0;
    int pre = 0;
    int cnt = 0;
    for (auto [j,i]:pts) {
        if (j == 1) continue;
        if (j!=pre) {
            if (cnt%2 == 1) flag = 1;
            cnt = 0;
        }
        ++cnt;
        if (j == 2) ++unit;

        pre = j;
    }
    if (pre!=1 && cnt%2==1) flag = 1;

    // cout << unit << " " << dictate << endl;
    if (n == 1) {
        if ((unit)%2==0) cout << "Yuyu" << endl;
        else cout << "Mimo" << endl;
    }
    else {
        if (flag) cout << "Mimo" << endl;
        else cout << "Yuyu" << endl;
        // if (dictate%2==0 && unit%2==0) cout << "Yuyu" << endl;
        // else cout << "Mimo" << endl;
    }
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

