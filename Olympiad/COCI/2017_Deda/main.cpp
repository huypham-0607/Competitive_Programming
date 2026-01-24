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
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 4e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q,m;
vector<int> nen;
vector<pair<pii,bool>> query;
set<int> BIT[N];

int getPos(int x) {
    return lower_bound(all(nen),x)-nen.begin()+1;
}

int getIdx(int idx, int x) {
    auto lmeo = BIT[idx].lower_bound(x); 
    return ((lmeo == BIT[idx].end())?INF:(*lmeo));
}

void update(int idx, int val) {
    while (idx<=m) {
        BIT[idx].insert(val);
        idx += idx&(-idx);
    }
}

int get(int idx, int val){
    int res = INF;
    while (idx>0) {
        res = min(res,getIdx(idx,val));
        idx -= idx&(-idx);
    }
    return res;
}

void solve(){
    cin >> n >> q;
    char c;
    int id,a,b;
    for (int i=1; i<=q; i++){
        cin >> c >> a >> b;
        query.push_back({{a,b},(c=='D')});
        nen.push_back(a);
    }
    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());
    
    for (int i=0; i<query.size(); i++){
        // cout << query[i].fi.fi << " ";
        query[i].fi.fi = getPos(query[i].fi.fi);
        // cout << query[i].fi.fi << endl;
    }

    m = nen.size();
    
    for (int i=0; i<query.size(); i++){
        if (query[i].se) {
            int ans = get(query[i].fi.fi,query[i].fi.se);
            if (ans == INF) cout << -1 << endl;
            else cout << ans << endl;
        } else {
            update(query[i].fi.fi,query[i].fi.se);
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

