/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "2153E"

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

const int MXP = 1e7;

int min_prime[MXP+1];
vector<int> primes;

void Sieve(){
    bitset<MXP+1> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i*i<=MXP; i++){
        if (!bs[i]) continue;
        for (int j=i*i; j<=MXP; j+=i){
            bs[j]=0;
            min_prime[j] = i;
        }
    }

    for (int i=2; i<=MXP; i++){
        if (bs[i]){
            primes.push_back(i);
            min_prime[i] = i;
        }
    }
//     for (int i=1; i<=20; i++){
//         cout << min_prime[i] << " ";
//     }
//     cout << endl;
//     for (int i=0; i<=20; i++){
//         cout << primes[i] << " ";
//     }
//     cout << endl;
}

int n,m;

void solve(){
    cin >> n >> m;
    int pos = -1;
    int l=0, r=primes.size()-1;
    while (l<=r) {
        int mid = (l+r)/2;
        if (primes[mid] <= n) {
            pos = mid;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    // cout << primes[pos] << endl;
    set<int> st;
    int ans = 0;
    for (int x = n-1; x >= primes[pos]; x--){
        int tmp = x+1;
        while (tmp!=1) {
            st.insert(min_prime[tmp]);
            tmp/=min_prime[tmp];
        }
        int mn = LLINF;
        // cout << "x: " << x << endl;
        for (int p:st) {
            int v1=0,v2=0;
            for (int i=p; i<=x; i*=p) v1+=x/i;
            for (int i=p; i<=n; i*=p) v2+=n/i;
            // cout << v1 << " " << v2 << endl;
            for (int i=p, cnt=1; i<=m; i*=p, cnt++) {
                // cout << cnt << " ";
                if (v1/cnt != v2/cnt) mn = min({mn,v1/cnt,v2/cnt});
            }
            // cout << endl;
        }
        ans += mn;
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

    Sieve();

    int testCount = 1;
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

