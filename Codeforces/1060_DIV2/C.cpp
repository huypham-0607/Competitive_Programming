/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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
const int sz = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
vector<int> primes;
int maxw[N],maxval[N],cnt[N];
int a[N],w[N];

void Sieve(){
    bitset<N> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i<N; i++){
        if (bs[i]){
            for (int j=i*i; j<N; j*=i){
                bs[j] = 0;
            }
        }
    }

    for (int i=2; i<N; i++){
        if (bs[i]) primes.push_back(i);
    }
    m = primes.size();
}

vector<int> upt;
int ans = INF*4;

void updateMaxW(int pos, int val, int na){
    if (maxw[pos] == INF){
        if (!na){
            maxw[pos] = val;
            upt.push_back(pos);
        }
    }
    else ans = min(ans,maxw[pos]+val);
}

void Process(int x, int val, int na = 0){
    for (int i=0; primes[i]*primes[i]<=x; i++){
        int p = primes[i];
        if (x%p == 0){
            updateMaxW(i,val,na);
            while (x%p == 0){
                x/=p;
            }
        }
    }
    if (x!=1 && x<N){
        int i = lower_bound(all(primes),x) - primes.begin();
        updateMaxW(i,val,na);
    }
}

void solve(){
    cin >> n;
    ans = INF*4;
    while (upt.size()){
        maxw[upt.back()] = INF;
        upt.pop_back();
    }
    int maxx = 0;
    vector<pii> v,v2;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        maxx = max(maxx,a[i]);
//        Process(a[i],0);
    }
    for (int i=1; i<=n; i++){
        cin >> w[i];
        v.push_back({w[i],a[i]});
    }

    sort(all(v));

    for (int i=1; i<v.size(); i++){
        Process(v[i].se,0);
    }

    for (auto pos:upt){
        int p = primes[pos];
        int i = (p-(v[0].se%p))%p;
        int x = v[0].se+i;
        int val = v[0].fi*i;
//        cout << x << " " << val << endl;
        Process(x,val,1);
    }

    Process(v[0].se,0);

    for (auto [val,x]:v){
        Process(x+1,val);
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
    for (int i=0; i<m; i++){
        maxw[i] = INF;
    }
    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

