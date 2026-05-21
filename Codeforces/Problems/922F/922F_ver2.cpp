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

const int N = 3e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
int val[N];
int flag[N];

void solve(){
    cin >> n >> m;
    int sum = 0;
    for (int i=1; i<=n; i++){
        sum += (n/i)-1;
        val[i] = (n/i)-1;
        flag[i] = 1;
    }
    // cout << sum << endl;
    // for (int i=1; i<=n; i++){
    //     cout << val[i] << " ";
    // }
    // cout << endl;
    if (m > sum) {
        cout << "No" << endl;
        return;
    }
    int cnt = 0;
    for (int i=2; i<=n; i++){
        if (sum-val[i]-1>=m) {
            flag[i] = 0;
            sum -= val[i]+1;
            ++cnt;
        }
        else {
            for (int j=2*i; j<=n; j+=i) {
                val[j]++;
            }
        }
    }

    if (sum != m) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        cout << n-cnt << endl;
        for (int i=1; i<=n; i++){
            if (flag[i]) cout << i << " ";
        }
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
