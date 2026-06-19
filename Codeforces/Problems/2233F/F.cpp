/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

typedef int int2;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1400;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;


const int MXP = 31623;

vector<int> primes;

void Sieve(){
    bitset<MXP+1> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i*i<=MXP; i++){
        if (!bs[i]) continue;
        for (int j=i*i; j<=MXP; j+=i){
            bs[j]=0;
        }
    }

    for (int i=1; i<=MXP; i++){
        if (bs[i]) primes.push_back(i);
    }
}


int n,a,b;
int fact_sz_a[N], fact_sz_b[N];
int fact_a[N][N];
int fact_b[N][N];
int dp[N][N];
vector<int> pa,pb;
vector<pii> da,db;

void factorize(int x, vector<int>& v) {
    for (auto p:primes) {
        if (x%p==0) {
            // cout << p << endl;
            v.push_back(p);
            while (x%p==0) x/=p;
        }
    }
    // cout << x << endl;
    if (x!=1) v.push_back(x);
}

void get_div(int pos, vector<pii> &da, int fact[N][N], int sz[N]) {
    a = da[pos].fi;
    int cnt = 0;
    for (int idx=0; idx<=pos; idx++){
        int i = da[idx].fi;
        if (a%i==0) {
            fact[pos][cnt++] = idx;
        }
    }
    sz[pos] = cnt;
}

void solve(){
    cin >> n >> a >> b;
    int gcd = __gcd<ll>(a,b);
    a/=gcd;
    b/=gcd;

    factorize(a,pa);
    factorize(b,pb);

    // for (auto x:pa) cout << x << " "; cout << endl;
    // for (auto x:pb) cout << x << " "; cout << endl;

    for (int i=1; i*i<=a; i++){
        if (a%i==0) {
            int x = 1;
            for (auto p:pa) {
                if (i%p==0) x = p; 
            }
            da.push_back({i,x});

            if (i*i==a) continue;

            x = 1;
            for (auto p:pa) {
                if ((a/i)%p==0) x = p;
            }
            da.push_back({a/i,x});
        }
    }
    sort(all(da));
    for (int i=0; i<da.size(); i++){
        get_div(i,da,fact_a,fact_sz_a);
    }
    for (int i=1; i*i<=b; i++){
        if (b%i==0) {
            int x = 1;
            for (auto p:pb) {
                if (i%p==0) x = p; 
            }
            db.push_back({i,x});

            if (i*i==b) continue;

            x = 1;
            for (auto p:pb) {
                if ((b/i)%p==0) x = p;
            }
            db.push_back({b/i,x});
        }
    }
    sort(all(db));
    for (int i=0; i<db.size(); i++){
        get_div(i,db,fact_b,fact_sz_b);
    }

    dp[0][0] = 0;
    for (int i=0; i<da.size(); i++){
        for (int j=0; j<db.size(); j++){
            if (i==0 && j==0) continue;
            if (da[i].se > db[j].se) {
                int p = da[i].se;
                int k = lower_bound(all(da),make_pair(da[i].fi/da[i].se,0)) - da.begin();
                int val = INF;
                for (int idx=0; idx<fact_sz_b[j]; idx++){
                    int l = fact_b[j][idx];
                    val = min(dp[k][l] + ((db[j].fi/db[l].fi > p)?db[j].fi/db[l].fi:p),val);
                }
                dp[i][j] = val;
            }
            else {
                int p = db[j].se;
                int l = lower_bound(all(db),make_pair(db[j].fi/db[j].se,0)) - db.begin();
                int val = INF;
                for (int idx=0; idx<fact_sz_a[i]; idx++){
                    int k = fact_a[i][idx];
                    val = min(dp[k][l] + ((da[i].fi/da[k].fi > p)?da[i].fi/da[k].fi:p),val);
                }
                dp[i][j] = val;
            }
        }
    }
    // for (int i=0; i<da.size(); i++){
    //     for (int j=0; j<db.size(); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[da.size()-1][db.size()-1] << endl;
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

