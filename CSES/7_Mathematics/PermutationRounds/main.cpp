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
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

const int MXP = 448;

vector<int> primes;
bitset<MXP+1> bs;
int np;
void Sieve(){

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
    np = primes.size();
}


int n;

bool vis[N];
int nxt[N];
vector<int> v;
vector<int> cnt;
set<int> st;

void decomp(int x) {
    for (int i = 0; i<np; i++){
        int val = 0;
        while (x%primes[i]==0) {
            ++val;
            x = x/primes[i];
        }
        cnt[i] = max(cnt[i],val);
    }
    if (x!=1) {
        st.insert(x);
    }
}

int DFS(int u, int prev){
    vis[u] = true;
    ++prev;

    if (!vis[nxt[u]]){
        return DFS(nxt[u],prev);
    }
    return prev;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> nxt[i];
    }
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            v.push_back(DFS(i,0));
        }
    }

    cnt.resize(np,0);

    for (auto x:v){
        // cout << x << endl;
        decomp(x);
    }

    int ans = 1;
    for (int i=0; i<np; i++){
        // cout << cnt[i] << " ";
        for (int j=1; j<=cnt[i]; j++){
            ans = (ans*primes[i])%MD;
        }
    }
    // cout << endl;
    for (auto x:st) {
        ans = (ans*x)%MD;
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

