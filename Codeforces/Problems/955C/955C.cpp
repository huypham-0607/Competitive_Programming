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

const int MXP = 1e6;

int q;
vector<int> lmao,lmeo;
vector<int> lmao2;

int root(int x) {
    int l = 1, r = 1e9;
    int ans = 0;
    while (l<=r) {
        int mid = (l+r)/2;
        if (mid*mid<=x) {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}

int compute(int x){
    int res = 0;
    res = upper_bound(all(lmao2),x) - lmao2.begin();
    return res;
}

void solve(){

    for (int i=2; i<=(int)10; i++){
        int val = i*i;
        for (int lg=3; lg<61; lg++) {
            if (val > ((ll)1e18)/i) break;
            val=val*i;

            lmao.push_back(val);
        }
    }
    sort(all(lmao));
    lmao.resize(unique(all(lmao))-lmao.begin());

    for (auto x:lmao) {
        int r = root(x);
        if (r*r != x) lmao2.push_back(x); 
    }

    for (int i=0; i<=10; i++){
        cout << lmao2[i] << " ";
    }
    cout << endl;

    cin >> q;
    for (int i=1; i<=q; i++){
        int l,r; cin >> l >> r;
        int lval = compute(l-1);
        int rval = compute(r);
        int delta = root(r) - root(l-1);
        cout << lval << " " << rval << " " << delta << endl;
        cout << rval - lval + delta << endl;
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

