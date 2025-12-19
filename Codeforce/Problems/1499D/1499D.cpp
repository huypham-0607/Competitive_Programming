/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#define TEXT "1499D"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
//#define int long long

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

const int MXP = 2e7;

vector<int> primes;
int minp[MXP+1];
int cntp[MXP+1];

void Sieve(){
    for (int i=0; i<=MXP; i++){
        minp[i] = 1;
        cntp[i] = 0;
    }
    bitset<MXP+1> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i*i<=MXP; i++){
        if (!bs[i]) continue;
        minp[i] = i;
        for (int j=i*i; j<=MXP; j+=i){
            bs[j]=0;
            minp[j] = i;
        }
    }

    for (int i=2; i<=MXP; i++){
        if (bs[i]) {
            cntp[i] = 1;
            continue;
        }
        int prev = i/minp[i];
        if (prev%minp[i] != 0) {
            cntp[i] = cntp[prev]+1;
        }
        else cntp[i] = cntp[prev];
    }
    
    // for (int i=0; i<=20; i++){
    //     cout << cntp[i] << " ";
    // }
    // cout << endl;

    for (int i=1; i<=MXP; i++){
        cntp[i] = (1LL<<cntp[i]);
    }
}

void addAns(int x, int &ans) {
    ans += cntp[x];
}

void getFact(int x, vector<int>& f) {
    int res = 0;
    for (int i=1; i*i<=x; i++){
        if (x%i == 0) {
            f.push_back(i);
            if (!(i*i == x)) f.push_back(x/i);
        }
    }
    // sort(all(f));
}

int a,b,x;

void solve(){
    cin >> a >> b >> x;

    vector<int> f;
    getFact(x,f);
    int ans = 0;
    for (auto gcd:f) {
        int cgcd = x/gcd;
        // cout << gcd << " " <<cgcd << endl;
        if ((cgcd+b)%a == 0) {
            int lcm = (cgcd+b)/a;
            // cout << lcm << " " << lcm*gcd << endl;
            // cout << endl;
            addAns(lcm,ans);
        }
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

    // int tmp = 0;
    // addAns(8002,tmp);
    // vector<int> v;
    // getFact(100,v);
    // for (auto x:v) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // cout << tmp << endl;
    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

