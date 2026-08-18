/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>
#include <functional>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
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

int s,n;
vector<int> val;
vector<int> divi;
vector<int> pref;

int getarea(int a, int b) {
    // cerr << "a,b: " << a << " " << b << endl;
    b = min(b,divi.back());
    int res = 0;
    int idx = lower_bound(1+all(val), a, greater<int>()) - val.begin() - 1;

    res += min(b,divi[idx]) * a;

    int idx2 = lower_bound(1+all(divi), b) - divi.begin();
    
    // cerr << idx << " " << idx2 << endl;

    if (idx < idx2) {
        res += pref[idx2] - pref[idx];
        if (idx2 != divi.size()) res -= val[idx2]*(divi[idx2] - b);  
    }

    // cerr << res << endl;

    return res;
}

void solve(){
    cin >> s >> n;
    val.clear();
    divi.clear();
    pref.clear();
    val.push_back(0);
    divi.push_back(0);
    int m = 0;
    for (int i=1; i*i<=s; i++){
        if (s%i==0) {
            divi.push_back(i);
            val.push_back(s/i);
            ++m;
        }
    }
    pref.resize(divi.size(),0);

    // cerr << pref.size() << endl;

    int prev = 0;
    for (int i = 1; i <= m; i++){
        pref[i] = pref[i-1] + val[i]*(divi[i] - prev);
        prev = divi[i];
    }

    // for (auto x:divi) cerr << x << " "; cerr << endl;
    // for (auto x:val) cerr << x << " "; cerr << endl;

    ffor(i,1,n) {
        int a,b; cin >> a >> b;
        int res = 0;
        res += getarea(a,b);
        res += getarea(b,a);
        res -= min(a,divi.back()) * min(b,divi.back());

        cout << res << endl;
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

