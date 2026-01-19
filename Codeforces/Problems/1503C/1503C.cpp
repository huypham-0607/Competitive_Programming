/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "1503C"

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

int n;

int calc(int s, int e, vector<pii>& v) {
    priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>>> query;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({LLINF,LLINF});

    int res = LLINF;
    int cur = s;
    int ans = 0;
    // cout << cur << " " << ans << endl;
    for (auto [x,w]:v) {
        query.push({{x,1},w});
    }
    while (!query.empty()) {
        int pos = query.top().fi.fi;
        int id = query.top().fi.se;
        int w = query.top().se;

        query.pop();

        // cout << pos << " " << id << " " << w << endl;

        ans += (pos-cur);
        cur = pos;
        while (!pq.empty() && pq.top().se < pos) pq.pop();

        if (id == 1) {
            int val = min(ans,pq.top().fi);
            if (pos == e) res = min(res,val);
            pq.push({val,pos+w});
            query.push({{pos+w,0},val});
        }
        else {
            ans = min(ans,w);
        }
    }
    // cout << res << endl;
    return res;
}

void solve(){
    cin >> n;

    int pivot;
    int mx = 0;
    int mn = LLINF;

    int ans = 0;
    vector<pii> high,low;
    for (int i=1; i<=n; i++){
        int x,w; cin >> x >> w;
        ans += w;
        if (i==1) pivot = x;
        mx = max(mx,x);
        mn = min(mn,x);
        low.push_back({x,w});
    }

    int val1 = calc(mn,mx,low);
    // cout << val1 << " " << val2 << " " << ans << endl;
    cout << ans + val1 << endl;
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

