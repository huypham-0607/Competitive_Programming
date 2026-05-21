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

int n,k,x,y;
int a[N];
int loc[N];
int dist[N];
vector<int> bucket[N];

void solve(){
    cin >> n >> k >> x >> y;
    int delta = (y-x+n)%n;
    // cout << delta << endl;

    for (int i=0; i<n; i++){
        bucket[i].clear();
    }

    for (int i=1; i<=k; i++){
        cin >> a[i];
    }

    int cur = 0;
    for (int i=1; i<=k; i++){
        cur = (cur + a[i])%n;
        loc[i] = cur;
    }

    // for (int i=1; i<=k; i++){
    //     cout << loc[i] << " ";
    // }
    // cout << endl;

    set<pii> st;
    for (int i=k; i>0; i--){
        pii cur = {loc[i],i};
        pii fkey = {(loc[i]-delta+n)%n, 0};
        auto it = st.lower_bound(fkey);
        if (it != st.end() && it->fi == (loc[i]-delta+n)%n) {
            dist[i] = dist[it->se];
        }
        else {
            dist[i] = (loc[k]-loc[i]+delta+n)%n;
        }
        st.insert(cur);
    }

    // for (int i=1; i<=k; i++){
    //     cout << dist[i] << " ";
    // }
    // cout << endl;

    for (int i=1; i<=k; i++){
        bucket[loc[i]].push_back(i);
    }

    vector<int> ans;
    for (int i=0; i<n; i++){
        if (i == x) continue;
        int mnidx = k+1;

        for (auto idx:bucket[(x-i+n)%n]) {
            mnidx = min(mnidx,idx);
        }

        // cout << (x-i+n)%n << " " << mnidx << endl;

        if (mnidx == k+1) {
            int res = (loc[k]+i)%n;
            ans.push_back(res); 
        }
        else {
            int res = (loc[mnidx]+i+dist[mnidx])%n;
            ans.push_back(res);
        }
    }
    for (auto x:ans) {
        cout << x << " ";
    }
    cout << endl;
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

