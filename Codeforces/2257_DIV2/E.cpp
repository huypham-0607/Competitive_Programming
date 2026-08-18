/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>
#include <queue>

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
const int MD = 1e9+7; //998244353;
const long long LLINF = 2e18+3;

//Starts here

int n, s_capital;
int m[N];
vector<int> a[N];
vector<int> b[N];

vector<pii> profit[N];
int goals[N];
int tracker[N];

int check(int x) {
    // cerr << "mid: " << x << endl;
    ffor(i,1,n) {
        goals[i] = 0;
        tracker[i] = 0;
        profit[i].clear();
    }
    for (int idx=1; idx<=n; idx++){
        int cur = 0;
        int req = 0;
        // cerr << "idx: " << idx << endl;
        // cerr << m[idx] << endl;
        for (int i=0; i<min(m[idx],x); i++){
            // cerr << i << endl;
            req = min(req,cur - a[idx][i]);
            cur += b[idx][i] - a[idx][i];
 
            if (cur >= 0) {
                profit[idx].push_back({-req,cur});
                cur = 0;
                req = 0;
            }
        }
        if (m[idx] >= x) {
            goals[idx] = -req;
        }
        else goals[idx] = LLINF;
    }
    // ffor(idx,1,n) {
    //     for (auto [req,prof] : profit[idx]) cerr << req << ":" << prof << " ";
    //     cerr << endl;
    // }
    // ffor(idx,1,n) cout << goals[idx] << " "; cout << endl;
    // cerr << "passed init" << endl;
    priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>>> pq;
    ffor(idx,1,n) {
        if (profit[idx].size()) {
            pq.push({profit[idx][0],idx});
        }
    }
    int capital = s_capital; 
    // cerr << capital << " " << pq.top().fi.fi << endl;
    while (!pq.empty() && capital >= pq.top().fi.fi) {
        capital += pq.top().fi.se;
        int idx = pq.top().se;
        pq.pop();

        ++tracker[idx];
        if (tracker[idx] != profit[idx].size()) {
            pq.push({profit[idx][tracker[idx]], idx});
        }
    }

    ffor(idx,1,n) {
        if (tracker[idx] == profit[idx].size() && capital >= goals[idx]) return idx;
    }
    return 0;
}

void solve(){
    cin >> n >> s_capital;
    ffor(i,1,n){
        a[i].clear();
        b[i].clear();
    }
    ffor(idx,1,n) {
        cin >> m[idx];
        ffor(i,1,m[idx]) {
            int x; cin >> x;
            a[idx].push_back(x);
        }
        ffor(i,1,m[idx]){
            int x; cin >> x; b[idx].push_back(x);
        }
    }

    int bidx = 1;
    int ans = 0, l = 1, r = N;
    while (l<=r) {
        int mid = (l+r)/2;
        int res = check(mid);
        if (res) {
            ans = mid;
            bidx = res;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    cout << ans << " " << bidx << endl;
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

