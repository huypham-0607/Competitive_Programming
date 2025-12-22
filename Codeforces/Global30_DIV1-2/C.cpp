/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
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
int a[N],b[N],c[N];
map<int,int> mp;

void solve(){
    mp.clear();
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i=0; i<m; i++){
        cin >> b[i];
    }
    for (int i=0; i<m; i++){
        cin >> c[i];
    }
    vector<pii> v;
    vector<int> mon;
    for (int i=0; i<m; i++){
        if (c[i] != 0) {
            v.push_back({b[i],c[i]});
        }
        else {
            mon.push_back(b[i]);
        }
    }

    int cnt = 0;

    sort(all(v));
    for (auto [req,val]:v){
        auto it = mp.lower_bound(req);
        val = max(val,it->fi);
        if (it!=mp.end()){
            ++cnt;
            it->se--;
            if (!it->se) mp.erase(it);
            mp[val]++;
        }
    }

    sort(all(mon));

    for (auto x:mon) {
        auto it = mp.lower_bound(x);
        if (it!=mp.end()) {
            ++cnt;
            it->se--;
            if (!it->se) mp.erase(it);
        }
    }

    cout << cnt << endl;
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

