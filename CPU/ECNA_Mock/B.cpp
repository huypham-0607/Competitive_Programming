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

const int N = 110;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int A,B,n,m;
int pref[N][N];
vector<pii> nitem, mitem;
int ci[N];
int cj[N];

bool checkBound(int i, int j){
    return (i>0 && i<=A && j>0 && j<=B);
}

void solve(){
    cin >> A >> B >> n >> m;
    int truen = n, truem = m;
    vector<int> neni, nenj;
    for (int idx=1; idx<=n; idx++){
        int i,j; cin >> i >> j;
        i+=7;
        j+=4;
        if (!checkBound(i,j)) continue;
        nitem.push_back({i,j});
        neni.push_back(i);
        nenj.push_back(j);
    }
    for (int idx=1; idx<=m; idx++){
        int i,j; cin >> i >> j;
        i+=7;
        j+=4;
        if (!checkBound(i,j)) continue;
        mitem.push_back({i,j});
        neni.push_back(i);
        nenj.push_back(j);
    }
    sort(all(neni));
    neni.resize(unique(all(neni)) - neni.begin());
    sort(all(nenj));
    nenj.resize(unique(all(nenj)) - nenj.begin());

    int ndim = neni.size();
    int mdim = nenj.size();

    for (int i=0; i<neni.size(); i++){
        ci[i+1] = neni[i];
    }

    for (int i=0; i<nenj.size(); i++){
        cj[i+1] = nenj[i];
    }

    for (auto [i,j]: nitem) {
        i = lower_bound(all(neni), i) - neni.begin() +1;
        j = lower_bound(all(nenj), j) - nenj.begin() +1;
        pref[i][j] -= 1;
    }

    for (auto [i,j]: mitem) {
        i = lower_bound(all(neni), i) - neni.begin() +1;
        j = lower_bound(all(nenj), j) - nenj.begin() +1;
        pref[i][j] += 1;
    }

    for (int i=1; i<=ndim; i++){
        for (int j=1; j<=mdim; j++){
            pref[i][j] += pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1];
        }
    }

    int ans = INF;

    for (int i1=1; i1<=ndim; i1++){
        for (int i2=i1; i2<=ndim; i2++){
            for (int j1=1; j1<=mdim; j1++){
                for (int j2=j1; j2<=mdim; j2++){
                    int spc = (ci[i2] - ci[i1-1]) * (cj[j2] - cj[j1-1]);
                    int val = pref[i2][j2] - pref[i2][j1-1] - pref[i1-1][j2] + pref[i1-1][j1-1];
                    if (spc < n) continue;
                    ans = min(ans,n+val);
                }
            }
        }
    }

//    cout << ndim << " " << mdim << endl;
//    for (int i=1; i<=ndim; i++){
//        cout << ci[i] << " ";
//    }
//    cout << endl;
//
//    for (int i=1; i<=mdim; i++){
//        cout << cj[i] << " ";
//    }
//    cout << endl;


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

