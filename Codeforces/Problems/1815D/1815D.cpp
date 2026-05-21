/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 998244353;
const int LG = 61;
const int M = 11;
const long long LLINF = 1e18+3;

//Starts here

int n,m;

map<int,int> dp,cnt;

void calcdp(int n) {
    if (dp.count(n)) return;
    if (n%2 == 0) {
        if (!dp.count(n/2)) calcdp(n/2);
        if (!dp.count(n/2 - 1)) calcdp(n/2 - 1);

        int count = (cnt[n/2] + cnt[n/2-1])%MD;
        int val = (2*dp[(n/2)] + 2*dp[(n/2-1)])%MD;

        cnt.insert({n,count});
        dp.insert({n,val});
    }
    else {
        if (!dp.count(n/2)) calcdp(n/2);
        int count =  cnt[n/2];
        int val = ((2*dp[n/2])%MD + count)%MD;
        cnt.insert({n,count});
        dp.insert({n,val});
    }

}

void solve(){
    cin >> n >> m;
    if (m == 1) {
        cout << n%MD << endl;
        return;
    }
    if (m>2) {
        int lmao = n/2;
        cout << (((lmao%MD)*((lmao+1)%MD))%MD + ((n%2==1)?((lmao+1)%MD):(0)))%MD << endl;
        return;
    }
    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    calcdp(n);

    int res = dp[n];
    cout << res << endl;
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
    dp.insert({n,0});
    cnt.insert({n,1});
    while (testCount--){
        solve();
    }

    return 0;
}

