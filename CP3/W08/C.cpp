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
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k;
int pre[N];
int suf[N];
int a[N],t[N];

void solve(){
    cin >> n >> k;
    vector<pii> v1,v2;
    for (int i=1; i<=n; i++){
        pre[i] = suf[i] = LLINF;
    }
    for (int i=1; i<=k; i++){
        cin >> a[i];
    }
    for (int i=1; i<=k; i++){
        cin >> t[i];
        v1.push_back({a[i],t[i]});
        v2.push_back({a[i],t[i]});
    }
    sort(all(v1));
    sort(all(v2),greater<pii>());
    
    int cur = LLINF;
    int idx = 0;
    for (int i=1; i<=n; i++){
        cur++;
        while (idx!=v1.size() && v1[idx].fi == i) {
            cur = min(cur,v1[idx].se);
            // cout << i << " " << v2[idx].se << endl;
            ++idx;
        }
        pre[i] = cur;
    }
    // cout << "lol" << endl;
    cur = LLINF;
    idx = 0;
    for (int i=n; i>0; i--){
        cur++;
        while (idx!=v2.size() && v2[idx].fi == i) {
            cur = min(cur,v2[idx].se);
            // cout << i << " " << v2[idx].se << endl;
            ++idx;
        }
        suf[i] = cur;
    }

    for (int i=1; i<=n; i++){
        cout << min(pre[i],suf[i]) << " ";
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

