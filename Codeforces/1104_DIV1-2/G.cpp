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

const int N = 2e3+10;
const int INF = 1e9+7;
const int OFFSET = 20;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

const int MXP = 1e6;
const int LIM = 120;

vector<int> primes;
int gp[MXP+1];
int hsh[MXP+1];
int msk[MXP+1];
vector<pair<pii,pii>> b_encode;
vector<int> valid_num;
int q_table[LIM+1];

void Sieve(){
    bitset<MXP+1> bs;
    bs.set();
    bs[0] = bs[1] = 0;

    for (int i=2; i<=MXP; i++){
        if (!bs[i]) continue;
        for (int j=i; j<=MXP; j+=i) {
            gp[j] = max(gp[j],i);
        }
        for (int j=i*i; j<=MXP; j+=i){
            bs[j]=0;
        }
    }

    for (int i=1; i<=MXP; i++){
        if (bs[i]) primes.push_back(i);
    }

    for (int i=0; i<LIM; i++){
        int res = 1;
        while (res*primes[i]<=MXP) res*=primes[i];
        q_table[i+1] = res;
    }

    int cnt = 0;
    for (int i=2; i<=MXP; i++){
        if (gp[i]<=primes[LIM-1]) {
            ++cnt;
            valid_num.push_back(i);
        }
    }

    cnt = 0;
    for (int mask=0; mask<4; mask++) {
        for (auto x:valid_num) {
            hsh[++cnt] = (x^(mask<<OFFSET));
            msk[cnt] = mask;
            if (cnt == MXP) break;
        }
        if (cnt == MXP) break;
    }

    cnt = 0;
    
    for (int i=0; i<LIM; i++){
        if (primes[i] <= MXP) {
            b_encode.push_back({{i,-1},{-1,-1}});
            ++cnt;
        }
        for (int j=i+1; j<LIM; j++){
            if (primes[i]*primes[j]<=MXP) {
                b_encode.push_back({{i,j},{-1,-1}});
                ++cnt;
            }
            for (int k=j+1; k<LIM; k++){
                if (primes[i]*primes[j]*primes[k]<=MXP) {
                    b_encode.push_back({{i,j},{k,-1}});
                    ++cnt;
                }
                for (int l=k+1; l<LIM; l++){
                    if (primes[i]*primes[j]*primes[k]*primes[l]<=MXP){
                        b_encode.push_back({{i,j},{k,l}});
                        ++cnt;
                    }
                }
            }
        }
    }

    // for (int i=1; i<=10; i++){
    //     cout << hsh[i] << " " << msk[i] << endl;
    // }
    // cout << endl;

    // for (int i=0; i<=10; i++){
    //     int res = 1;
    //     if (b_encode[i].fi.fi!=-1) res*=primes[b_encode[i].fi.fi];
    //     if (b_encode[i].fi.se!=-1) res*=primes[b_encode[i].fi.se];
    //     if (b_encode[i].se.fi!=-1) res*=primes[b_encode[i].se.fi];
    //     if (b_encode[i].se.se!=-1) res*=primes[b_encode[i].se.se];
    //     cout << res << " ";
    // }
    // cout << endl;
}

int a[N];

void solve1(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    int k = ceil((double)n/8);

    cout << LIM + n + k << endl;
    for (int i=0; i<LIM; i++){
        cout << q_table[i+1] << " ";
    }
    for (int i=1; i<=n; i++){
        cout << (hsh[a[i]]^(msk[a[i]]<<OFFSET)) << " ";
    }
    int pos = 0;
    for (int i=1; i<=k; i++){
        int mask = 0;
        for (int idx=0; idx<8; idx++){
            if (pos == n) break;
            ++pos;
            mask^=(msk[a[pos]]<<(idx*2));
            // cout << pos << " " << a[pos] << " " << msk[a[pos]] << endl;
        }
        int res = 1;
        if (b_encode[mask].fi.fi!=-1) res*=primes[b_encode[mask].fi.fi];
        if (b_encode[mask].fi.se!=-1) res*=primes[b_encode[mask].fi.se];
        if (b_encode[mask].se.fi!=-1) res*=primes[b_encode[mask].se.fi];
        if (b_encode[mask].se.se!=-1) res*=primes[b_encode[mask].se.se];
        cout << res << " ";
    }
    cout << endl;
}

int ask(int i, int j) {
    cout << "?  " << i << " " << j << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void answer(int n) {
    cout << "! ";
    for (int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout.flush();
}

void solve2(){
    int n,k; cin >> n >> k;
    k = k-n-LIM;
    // cout << k << endl;

    int LIM2 = LIM;

    for (int i=1; i<=n; i++){
        a[i] = 1;
        for (int idx=0; idx<LIM2; idx++){
            a[i]*=ask(idx+1,LIM+i);
        }
    }

    // for (int i=1; i<=n; i++){
    //     cout << a[i] << " ";
    //     cout << endl;
    // }

    vector<int> v(4,-1);
    int pos = 0;
    for (int i=1; i<=k; i++){
        int x = 1;
        for (int idx=0; idx<4; idx++){
            v[idx] = -1;
        }
        int cur = 0;
        for (int idx=0; idx<LIM2; idx++){
            int tmp = ask(idx+1,LIM+n+i);
            if (tmp!=1){
                v[cur] = idx;
                ++cur;
            }
        }

        int mask = lower_bound(all(b_encode),make_pair(make_pair(v[0],v[1]),make_pair(v[2],v[3]))) - b_encode.begin();
        for (int idx=0; idx<8; idx++){
            if (pos==n) break;
            ++pos;
            int bit_encode = ((mask&(3<<(2*idx)))>>(2*idx));
            a[pos] = (a[pos]^(bit_encode<<OFFSET));
        }
    }

    for (int i=1; i<=n; i++){
        a[i] = lower_bound(hsh+1,hsh+1+MXP,a[i]) - hsh;
    }
    answer(n);
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    Sieve();
    string s; cin >> s;
    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        if (s == "first") {
            solve1();
        }
        else {
            solve2();
        }
    }

    return 0;
}

