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
const int INF = 1e9 + 9;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k,d,m,lol;
vector<int> p;
vector<int> mul;
vector<int> divi;

void solve(){
    cin >> lol;
    lol = lol%MD;
    cin >> d >> m;
    if (m%d != 0) {
        cout << 0 << endl;
        return;
    }

    int x = m, y = d;
    for (int i=2; i*i<=m; i++){
        if (m%i == 0) {
            p.push_back(i);
            int cnt = 0;
            while (x%i == 0) {
                ++cnt;
                x/=i;
            }
            mul.push_back(cnt);

            cnt = 0;
            while (y%i == 0) {
                ++cnt;
                y/=i;
            }
            divi.push_back(cnt);
        }
    }

    if (x!=1) {
        int i = x;
        p.push_back(i);
        int cnt = 0;
        while (x%i == 0) {
            ++cnt;
            x/=i;
        }
        mul.push_back(cnt);

        cnt = 0;
        while (y%i == 0) {
            ++cnt;
            y/=i;
        }
        divi.push_back(cnt);
    }

    int n = mul.size() + divi.size();
    int k = mul.size();

    // for (int i=0; i<k; i++){
    //     cout << mul[i] << " " << divi[i] << endl;
    // }

    int t = 0;

    for (int mask = 1; mask<(1<<n); mask++){
        int lmao = 1;
        for (int i=0; i<k; i++){
            int delta = mul[i] - divi[i]+1;
            if (mask&(1<<i)) --delta;
            if (mask&(1<<(k+i))) --delta;
            delta = max(delta,0LL);
            lmao*=delta;
        }
        int cnt = __builtin_popcountll(mask);
        if (cnt%2 == 1) t = (t + lmao*lol%MD)%MD;
        else t = (t - lmao*lol%MD)%MD;
    }

    cout << t/2 << endl;
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

