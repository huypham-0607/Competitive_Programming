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
const int LG = 20;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
vector<pii> cond[LG];
vector<vector<int>> lst[LG];

void solve(){
    cin >> n;
    for (int i=0; i<n; i++){
        lst[i].resize((1<<i));
        for (int mask=1; mask<(1<<i); mask++){
            lst[i][mask].resize(1<<(n-i));
        }
    }

    cerr << "woof" << endl;

    for (int mask=1; mask<(1<<n); mask++) {
        int val; cin >> val;
        int lsb = __builtin_ctzll(mask);
        cond[lsb+1].push_back({mask,val});
    }

    cerr << "meow" << endl;

    for (int i=1; i<n; i++){
        for (int mask=1; mask<(1<<i); mask++){
            for (int mask2=1; mask2<(1<<n-i); mask2++) {
                lst[i][mask][mask2] = (1<<(LG+1))-1;
            }

            int bit = ((1<<(i-1))&mask);

            for (auto [maskq,val]:cond[i]) {
                if (bit) val = (val>>1);
                lst[i][mask][maskq>>(i)] &= val;
            }

            int premask = (bit) ? (mask^bit) : mask;

            for (int mask2=1; mask2<(1<<n-i+1); mask2++) {
                int val = lst[i-1][premask][mask2];

                if ((mask2&1) && (bit)) val = (val>>1);
                
                lst[i][mask][mask2>>(1)] &= val;
            }
        }
    }

    vector<int> ans;

    for (int mask=1; mask<(1<<n); mask++){
        if ((lst[n-1][mask][0])&1) {
            ans.push_back(mask);
        }
    }
    cout << ans.size() << endl;
    for (auto x:ans) {
        cout << x << endl;
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

