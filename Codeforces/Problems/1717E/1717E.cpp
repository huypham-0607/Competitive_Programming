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

/*
    | Sieve of Eratosthenes |
    Desc: Get all primes from 1 to MXP in O(n*log(log(n)))
    Source: KawakiMeido
    State: Tested
*/
const int MXP = 1e6;

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


int n;
int cnt1[N];

void decomp(int x, vector<int>& v){
    v.clear();
    for (int i=2; i*i<=x; i++){
        if (x%i==0) {
            v.push_back(i);
            if (i*i!=x) v.push_back(x/i);
        }
    }
}

vector<int> divs;

void solve(){
    divs.clear();
    cin >> n;
    int ans = 0;
    cnt1[1] = 0;
    for (int i=2; i<n; i++){
        int localsum = 0;
        int c = n-i;
        cnt1[i] = i-1;
        // cout << cnt1[i] << endl;
        decomp(i,divs);
        for (auto x:divs) {
            int inst = cnt1[i/x];
            cnt1[i] -= inst;
            int gcd = __gcd<ll>(x,c);
            // cout << x << " " << inst << endl;
            localsum = (localsum + inst*((c*x/gcd)%MD)%MD)%MD;
            ans = (ans + inst*((c*x/gcd)%MD)%MD)%MD;
        }
        ans = (ans + cnt1[i]*c%MD)%MD;
        localsum = (localsum + cnt1[i]*c%MD)%MD;
        // cout << i << " " << c << " " << localsum << " " << cnt1[i] << endl; 
    }

    // for (int i=1; i<=5; i++){
    //     cout << cnt1[i] << " ";
    // }
    // cout << endl;
    cout << ans << endl;
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

