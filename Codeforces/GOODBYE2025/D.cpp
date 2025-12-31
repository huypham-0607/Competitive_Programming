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

int n,m;
int a[N];
vector<pii> v;
vector<pii> q;

void solve(){
    v.clear();
    q.clear();
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        v.push_back({a[i],i});
    }
    if (m*2 > n) {
        cout << -1 << endl;
        return;
    }
    sort(all(v),greater<pii>());

    if (m == 0) {
        int t = 0;
        int pos;
        for (pos = 1; pos<n; pos++){
            t+=v[pos].fi;
            if (t >= v[0].fi) break;
        }
        if (pos == n) {
            cout << -1 << endl;
            return;
        }
        // cout << pos << endl;
        for (int i=v.size()-1; i>pos; i--) {
            q.push_back({v[i].se,v[i-1].se});
        }
        for (int i=1; i<=pos; i++){
            q.push_back({v[i].se,v[0].se});
        }
        cout << q.size() << endl;
        for (auto [x,y]:q) {
            cout << x << " " << y << endl;
        }
    } else {
        for (int i=v.size()-1; i>=m*2; i--) {
            q.push_back({v[i].se,v[i-1].se});
        }

        for (int i=0; i<m; i++){
            q.push_back({v[i].se,v[i+m].se});
        }
        cout << q.size() << endl;
        for (auto [x,y]:q) {
            cout << x << " " << y << endl;
        }
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
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

