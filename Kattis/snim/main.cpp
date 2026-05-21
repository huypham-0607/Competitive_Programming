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

int n,k,m;
int grundy[N];
vector<int> s;

void solve(){
    cin >> k;
    // cout << k << endl;
    for (int i=1; i<=k; i++){
        int x; cin >> x;
        s.push_back(x);
    }

    for (int i=1; i<=10000; i++) {
        vector<int> tmp;
        for (auto delta:s) {
            int j = i-delta;
            if (j < 0) continue;
            tmp.push_back(grundy[j]);
        }
        sort(all(tmp));
        tmp.resize(unique(all(tmp)) - tmp.begin());
        int mex = 0;
        for (int idx=0; idx<tmp.size(); idx++){
            if (tmp[idx] == idx) ++mex;
        }
        grundy[i] = mex;
    }

    // for (int i=1; i<=20; i++){
    //     cout << grundy[i] << " ";
    // }
    // cout << endl;

    cin >> m;
    // cout << m << endl;
    for (int t=1; t<=m; t++){
        cin >> n;
        int res = 0;
        for (int i=1; i<=n; i++){
            int x; cin >> x;
            res^=grundy[x];
        }
        if (res == 0) {
            cout << "L";
        }
        else cout << "W";
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

