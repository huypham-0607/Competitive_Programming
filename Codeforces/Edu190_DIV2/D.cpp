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

const int N = 5e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];
int b[N];
vector<int> loc[N];
vector<int> val[N];


void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }
    for (int i=1; i<=n+1; i++){
        loc[i].clear();
        val[i].clear();
    }
    vector<pair<int,pii>> query;
    for (int i=1; i<=n; i++){
        if (a[i] == b[i]) {
            query.push_back({-a[i],{i,1}});
        }
        else {
            query.push_back({-a[i],{i,0}});
            query.push_back({-b[i],{i,0}});
        }
    }
    sort(all(query));
    for (auto in:query) {
        int vl = -in.fi;
        auto [pos,tpe] = in.se;
        if (tpe == 0) {
            loc[vl].push_back(pos);
            val[vl].push_back(0);
        }
        else {
            int idx = upper_bound(all(loc[vl+1]),pos) - loc[vl+1].begin();
            int delta = (idx == loc[vl+1].size()) ? n-pos+1 : loc[vl+1][idx]-pos + val[vl+1][idx];
            loc[vl].push_back(pos);
            val[vl].push_back(delta);
        }
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        int idx = lower_bound(all(loc[1]),i) - loc[1].begin();
        int delta = (idx == loc[1].size()) ? n-i+1 : loc[1][idx] - i + val[1][idx];
        ans += delta;
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

