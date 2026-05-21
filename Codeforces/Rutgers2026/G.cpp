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

int n;
int a[N];
int cnt[N];
pair<pii,pii> pref[N],suf[N];
int ans = 0;

void check(pii a, pii b) {
    if (a.fi == 0 || b.fi == 0) return;
    if (a.se == b.se) return;
    ans = max(ans,a.fi + b.fi);
}

void solve(){
    cin >> n;
    vector<int> nen;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        nen.push_back(a[i]);
    }
    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());
    // cerr << "woof" << endl;
    for (int i=1; i<=n; i++){
        a[i] = lower_bound(all(nen),a[i]) - nen.begin();
    }

    for (int i=0; i<nen.size(); i++){
        cnt[i] = 0;
    }
    pref[0] = {{0,0},{0,0}};
    for (int i=1; i<=n; i++){
        cnt[a[i]]++;
        pref[i] = pref[i-1];
        if (cnt[a[i]] > pref[i].fi.fi) {
            if (a[i] != pref[i].fi.se) {
                pref[i].se = pref[i].fi;
            }
            pref[i].fi.fi = cnt[a[i]];
            pref[i].fi.se = a[i];
        }
        else if (cnt[a[i]] > pref[i].se.fi) {
            pref[i].se.fi = cnt[a[i]];
            pref[i].se.se = a[i];
        }
    }

    for (int i=0; i<nen.size(); i++){
        cnt[i] = 0;
    }

    // cerr << "meow" << endl;
    suf[n+1] = {{0,0},{0,0}};
    for (int i=n; i>0; i--){
        cnt[a[i]]++;
        suf[i] = suf[i+1];
        if (cnt[a[i]] > suf[i].fi.fi) {
            if (a[i] != suf[i].fi.se) {
                suf[i].se = suf[i].fi;
            }
            suf[i].fi.fi = cnt[a[i]];
            suf[i].fi.se = a[i];
        }
        else if (cnt[a[i]] > suf[i].se.fi) {
            suf[i].se.fi = cnt[a[i]];
            suf[i].se.se = a[i];
        }
    }

    // cerr << "rawr" << endl;
    ans = 0;
    for (int i=1; i<n; i++){
        check(pref[i].fi,suf[i+1].fi);
        check(pref[i].fi,suf[i+1].se);
        check(pref[i].se,suf[i+1].fi);
        check(pref[i].se,suf[i+1].se);
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

