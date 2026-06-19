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
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

const int MXP = 5e5;

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

int n,k;
int a[N];
map<int,int> mp;

void solve(){
    cin >> n >> k;
    mp.clear();
    ffor(i,1,n) cin >> a[i];
    for (int i=1; i<=n; i++){
        int x = a[i];
        int val = x;
        for (int pi=0; pi<primes.size(); pi++){
            int p = primes[pi];
            if (p*p>x) break;
            if (val%p == 0) {
                if (mp.find(p)==mp.end()) mp[p] = 1;
                int cnt = 0;
                while (val%p == 0){
                    val=val/p;
                    ++cnt;
                }
                mp[p] = (mp[p]+cnt)%MD;
            }
        }
        if (val != 1) {
            if (mp.find(val)==mp.end()) mp[val] = 1;
            mp[val] = (mp[val]+1)%MD;
        }
    }
    int ans = 1;
    for (auto it=mp.begin(); it!=mp.end(); it++){
        // cout << it->fi << " " << it->se << endl;
        ans= (ans*it->se)%MD;
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
    // for (int i=0; i<10; i++) cout << primes[i] << " "; cout << endl;
    int testCount = 1;
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

