/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "762E"

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
typedef pair<pii,int> piii;
typedef pair<pii,pii> piiii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k,m;
vector<vector<piiii>> sussybaka(10100,vector<piiii>());

struct Fenwick{
    int n;
    vector<int> BIT;

    Fenwick(int _n=0): n(_n){
        n = _n;
        BIT.resize(n+10);
    }

    void Init (int _n, int val=0){
        n = _n;
        BIT.resize(n+10,0);
    }

    void update(int idx, int val){
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int getPoint(int idx){
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    int getVal(int l, int r){
        return (getPoint(r)-getPoint(l-1));
    }
} BIT;


int calc(vector<piiii> v, int freq, int tpe) {
    priority_queue<piiii,vector<piiii>,greater<piiii>> pq;

    for (auto in:v) {
        auto [x,f] = in.fi;
        auto [l,r] = in.se;
        pq.push({{x,1},{l,f}});
        pq.push({{r,0},{x,f}});
    }

    int ans = 0;
    while (!pq.empty()) {
        auto [pos,id] = pq.top().fi;
        auto [x,f] = pq.top().se;

        // cout << pos << " " << id << " " << x << " " << f << " " << endl;

        pq.pop();

        if (id == 0) {
            if (tpe == 0) {
                BIT.update(x,-1);
            }
            else {
                if (f!=freq) BIT.update(x,-1);
            }
        }
        else {
            if (tpe == 0) {
                if (f == freq) ans+=BIT.getVal(x,m);
                BIT.update(pos,1);
            }
            else {
                if (f == freq) ans += BIT.getVal(x,m);
                else BIT.update(pos,1);
            }
        }
    }
    return ans;
}

void solve(){
    cin >> n >> k;

    vector<piii> tmp;
    vector<int> nen;
    for (int i=0; i<n; i++){
        int x,r,f; cin >> x >> r >> f;
        tmp.push_back({{x,r},f});
        nen.push_back(x);
        nen.push_back(x-r);
        nen.push_back(x+r+1);
    }
    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());

    // for (auto x:nen) {
    //     cout << x << " ";
    // }
    // cout << endl;

    m = nen.size();
    // cout << m << endl;
    BIT.Init(nen.size());

    int mxfreq = 0;
    for (int i=0; i<n; i++){
        int x = tmp[i].fi.fi;
        int rad = tmp[i].fi.se;
        int f = tmp[i].se;

        mxfreq = max(mxfreq,f);

        int l = lower_bound(all(nen),x-rad) - nen.begin()+1;
        int r = lower_bound(all(nen),x+rad+1) - nen.begin()+1;
        x = lower_bound(all(nen),x) - nen.begin()+1;
        for (int j = f; j<=f+k; j++) {
            sussybaka[j].push_back({{x,f},{l,r}});
        }
    }

    int ans = 0;
    for (int i=1; i<=mxfreq; i++) {
        int res = calc(sussybaka[i],i,0);
        // cout << "calcpara: " << i << " " << res << endl;
        ans += res;
    }
    for (int i=mxfreq+k; i>k; i--) {
        int res = calc(sussybaka[i],i-k,1);
        // cout << "calcpara: " << i-k << " " << res << endl;
        ans += res;
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

