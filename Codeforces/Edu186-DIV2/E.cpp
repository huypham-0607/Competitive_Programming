/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "E"

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

int n,m,k;
vector<int> box;
vector<pii> item;
map<int,int> mp;

void solve(){
    box.clear();
    item.clear();
    mp.clear();
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++){
        int x; cin >> x;
        box.push_back(x);
    }
    sort(all(box));
    for (int i=1; i<=n; i++){
        int x,y,z; cin >> x >> y >> z;
        k-=y;
        int delta = z-y;
        item.push_back({x,delta});
    }
    sort(all(item));
    int idx = 0;
    int ans = 0;
    for (int i=0; i<m; i++){
        int val = box[i];
        while (idx!=n && item[idx].fi<=val) {
            auto [x,y] = item[idx];
            mp[y]++;
            ++idx;
        }
        // cerr << idx << endl;
        if (!mp.empty()){
            auto it = mp.rbegin();
            it->se--;
            if (it->se == 0) {
                mp.erase(it->fi);
            }
            ++ans;
        }
    }
    while (idx!=n) {
        auto [x,y] = item[idx];
        mp[y]++;
        ++idx;
    }
    vector<int> lst;
    for (auto it = mp.begin(); it!=mp.end(); it++){
        for (int i=1; i<=it->se; i++){
            lst.push_back(it->fi);
        }
    }

    int t = 0;
    for (int i=0; i<lst.size(); i++){
        // cout << lst[i] << " ";
        t+=lst[i];
        if (t <= k) ++ ans;
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

    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

