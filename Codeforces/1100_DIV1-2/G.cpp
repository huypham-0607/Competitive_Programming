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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k,s;
int h[N];
int pref[N];
int d[N],t[N];
vector<int> trans[N];
int ans[N];

void solve(){
    cin >> n >> k >> s;
    for (int i=1; i<=n; i++){
        cin >> h[i];
    }
    for (int i=1; i<=n; i++){
        pref[i] = pref[i-1] + h[i];
        trans[i].clear();
    }
    frep(i,1,n) {
        cin >> d[i];
    }

    t[s] = 0;
    for (int i=s+1; i<=n; i++) {
        t[i] = max(t[i-1]+1,d[i-1]);
    }
    for (int i=s-1; i>0; i--) {
        t[i] = max(t[i+1]+1,d[i]);
    }

    // for (int i=1; i<=n; i++){
    //     cout << t[i] << " ";
    // }
    // cout << endl;

    deque<int> ldq, rdq;
    int r = n;
    for (int l=1; l<s; l++) {
        // cerr << l << endl;
        while (r > s && t[r] - t[l] >= abs(r-l)) {
            while (!rdq.empty() && h[rdq.front()] <= h[r]) {
                rdq.pop_front();
            }
            rdq.push_front(r);
            --r;
        }

        while (!ldq.empty() && h[ldq.front()] <= h[l]) {
            ldq.pop_front();
        }

        int idx = upper_bound(all(rdq), l,[&](int i, int j) {return h[i] < h[j];}) - rdq.begin();
        if (idx != rdq.size()) trans[l].push_back(rdq[idx]);
        if (!ldq.empty()) trans[l].push_back(ldq.front());

        ldq.push_front(l);
    }
    while (!ldq.empty() && h[ldq.front()] <= h[s]) {
        ldq.pop_front();
    }
    if (!ldq.empty()) trans[s].push_back(ldq.front());

    ldq.clear();
    rdq.clear();

    int l = 1;
    for (int r=n; r>s; r--) {
        while (l < s && t[l] - t[r] >= abs(r-l)) {
            while (!ldq.empty() && h[ldq.front()] <= h[l]) {
                ldq.pop_front();
            }
            ldq.push_front(l);
            ++l;
        }

        while (!rdq.empty() && h[rdq.front()] <= h[r]) {
            rdq.pop_front();
        }

        int idx = upper_bound(all(ldq), r,[&](int i, int j) {return h[i] < h[j];}) - ldq.begin();
        if (idx != ldq.size()) trans[r].push_back(ldq[idx]);
        if (!rdq.empty()) trans[r].push_back(rdq.front());

        rdq.push_front(r);
    }
    while (!rdq.empty() && h[rdq.front()] <= h[s]) {
        rdq.pop_front();
    }
    if (!rdq.empty()) trans[s].push_back(rdq.front());

    // for (int i=1; i<=n; i++){
    //     for (auto x:trans[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> stamp;
    for (int i=1; i<=n; i++){
        stamp.push_back(i);
        ans[i] = -LLINF;
    }
    ans[s] = 0;
    sort(all(stamp),
        [&](int i, int j){
            if (t[i] == t[j]) return h[i] < h[j];
            return t[i]<t[j];
        });
    
    for (auto i:stamp) {
        // cout << "i: " << i << " " << t[i] << " " << ans[i] << endl;
        if (ans[i] == -LLINF) continue;
        for (auto j:trans[i]) {
            // cout << "j:" << " " << j << endl; 
            int val = ans[i] + (t[j]-t[i]-abs(i-j))*h[i] + ((j<i) ? pref[i-1]-pref[j-1] : pref[j]-pref[i]);
            ans[j] = max(ans[j],val);
        }
    }

    // for (int i=1; i<=n; i++){
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    // for (int i=1; i<=n; i++){
    //     cout << pref[i] << " ";
    // }
    // cout << endl;

    int res = -LLINF;
    for (int i=1; i<=n; i++){
        res = max(res, ans[i] + (k-t[i])*h[i]);
    }
    cout << res << endl;
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

