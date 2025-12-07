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
typedef pair<pii, pii> piiii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m,q;
vector<pii> query;

bool isBoundI(int x){ return (x>0 && x<=n); }
bool isBoundJ(int x){ return (x>0 && x<=m); }

pair<pii,pii> update(pair<pii,pii> cur, pii x){
    if (x.se == cur.fi.se || x.se == cur.se.se) return cur;
    if (x < cur.fi){
        cur.se = cur.fi;
        cur.fi = x;
    }
    else if (x < cur.se){
        cur.se = x;
    }
    return cur;
}

pair<pii,pii> updatePair(pair<pii,pii>cur, pair<pii,pii> nxt){
    cur = update(cur,nxt.fi);
    cur = update(cur,nxt.se);
    return cur;
}

vector<vector<piiii>> computeDist(vector<vector<int>>& a, int si, int sj){
    pair<pii,pii> initVal = make_pair(make_pair(INF,INF),make_pair(INF,INF));
    vector<vector<pair<pii,pii>>> res(n+2,vector<piiii>(m+2,initVal));
    int inci = ((si == 1LL)? 1 : -1);
    int incj = ((sj == 1LL)? 1 : -1);
    for (int i = si; isBoundI(i); i+=inci){
        for (int j = sj; isBoundJ(j); j+=incj){
            if (a[i][j]) res[i][j] = update(res[i][j],make_pair(0LL,a[i][j]));
            piiii nxt = res[i-inci][j];
            nxt.fi.fi++; nxt.se.fi++;
            res[i][j] = updatePair(res[i][j],nxt);
            nxt = res[i][j-incj];
            nxt.fi.fi++; nxt.se.fi++;
            res[i][j] = updatePair(res[i][j],nxt);
        }
    }
    return res;
}



void solve(){
    cin >> n >> m >> q;
    vector<vector<int>> a(n+2,vector<int>(m+2,false));
    for (int i=1; i<=q; i++){
        int x,y; cin >> x >> y;
        a[x][y] = i;
    }

//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=m; j++){
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }

    vector<vector<vector<pair<pii,pii>>>> pref(4);
    pref[0] = computeDist(a,1,1);
    pref[1] = computeDist(a,n,1);
    pref[2] = computeDist(a,1,m);
    pref[3] = computeDist(a,n,m);


    vector<vector<pair<pii,pii>>> ans(n+2,vector<piiii>(m+2));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            vector<pii> tmp;
//            cout << i << " " << j << " ";
            for (int idx=0; idx<4; idx++){
                tmp.push_back(pref[idx][i][j].fi);
                tmp.push_back(pref[idx][i][j].se);
            }
            sort(all(tmp));
            tmp.resize(unique(all(tmp)) - tmp.begin());
//            cout << tmp.size() << endl;
//            for (auto x:tmp){
//                cout << x.se << " ";
//            }
//            cout << endl;
            ans[i][j].fi = tmp[0];
            ans[i][j].se = tmp[1];
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << ans[i][j].fi.se << " ";
        }
        cout << endl;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << ans[i][j].se.se << " ";
        }
        cout << endl;
    }
}

/*Driver Code*/
signed main(){
//    cin.tie(0) -> sync_with_stdio(0);
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

