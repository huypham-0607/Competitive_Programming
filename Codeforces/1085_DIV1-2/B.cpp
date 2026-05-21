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

int n,m,L;
int a[N];
int val[N];

void check (int x) {

}

void solve(){
    cin >> n >> m >> L;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    for (int i=1; i<=m; i++) {
        val[i] = 0;
    }

    m = min(m,n+1);

    // int ans = L;
    // int l = 0, r = L;

    // while (l<=r) {
    //     int mid = (l+r)/2;
    //     if (check(mid)) {
    //         ans = mid;
    //         r = mid-1;
    //     }
    //     else {
    //         l = mid+1;
    //     }
    // }
    int lmao = 1;
    for (int i=1; i<=L; i++){
        int mn = INF;
        int pos = 0;
        for (int idx=1; idx<=m; idx++){
            if (val[idx] == -1) continue;
            if (val[idx] < mn) {
                mn = val[idx];
                pos = idx;
            }
        }
        val[pos]++;
        if (lmao <= n && a[lmao] == i) {
            int mx = -1;
            int pos = 0;
            for (int idx=1; idx<=m; idx++){
                if (val[idx] == -1) continue;
                if (val[idx] > mx) {
                    mx = val[idx];
                    pos = idx;
                }
            }
            if (n-lmao+1 < m) {
                val[pos] = -1;
            }
            else val[pos] = 0;
            ++lmao;
        }
    }
    int sum = 0;
    // for (int i=1; i<=m; i++){
    //     cout << val[i] << " ";
    // }
    // cout << endl;
    for (int i=1; i<=m; i++){
        if (val[i] == -1) continue;
        sum = max(sum,val[i]);
    }
    cout << sum << endl;
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