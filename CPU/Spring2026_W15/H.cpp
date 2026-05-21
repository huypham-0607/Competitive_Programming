/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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
pii pts[4];

int get_val(int delta, pii pts[4]) {
    // cout << "delta: " << delta << endl;
    int ans = LLINF;
    do {
        pii xs = {INF,INF}, ys = {INF,INF};
        for (int i=0; i<4; i++) {
            int val = pts[i].fi + ((i>1) ? 0 : -delta);
            if (val < xs.fi) {
                xs.se = xs.fi;
                xs.fi = val;
            }
            else xs.se = min(val,xs.se);
        }
        for (int i=0; i<4; i++) {
            int val = pts[i].se + ((i%2) ? 0 : -delta);
            if (val < ys.fi) {
                ys.se = ys.fi;
                ys.fi = val;
            }
            else ys.se = min(val,ys.se);
        }

        int res = 0;
        for (int i=0; i<4; i++){
            int valx = pts[i].fi + ((i>1) ? 0 : -delta);
            int valy = pts[i].se + ((i%2) ? 0 : -delta);

            res += abs(valx - xs.se);
            res += abs(valy - ys.se);
        }
        // cout << x[1] << " " << y[1] << " " << res << endl;
        ans = min(ans,res);
    } while (next_permutation(pts,pts+4));
    return ans;
}

int comp(int delta1, pii pts[4]) {
    // cout << "delta: " << delta << endl;
    int ans = LLINF;
    int ans1 = LLINF;
    do {
        vector<int> x = {pts[0].fi, pts[1].fi, pts[2].fi-delta1, pts[3].fi-delta1};
        vector<int> y = {pts[0].se, pts[1].se-delta1, pts[2].se, pts[3].se-delta1};
        vector<int> x1 = {pts[0].fi, pts[1].fi, pts[2].fi-delta1-1, pts[3].fi-delta1-1};
        vector<int> y1 = {pts[0].se, pts[1].se-delta1-1, pts[2].se, pts[3].se-delta1-1};

        sort(all(x)); sort(all(y));
        sort(all(x1)); sort(all(y1));

        int res = 0;
        int res1 = 0;
        for (int i=0; i<4; i++){
            res += abs(x[i] - x[1]);
            res1 += abs(x1[i] - x1[1]);
            res += abs(y[i] - y[1]);
            res1 += abs(y1[i] - y1[1]);
        }
        // cout << x[1] << " " << y[1] << " " << res << endl;
        ans = min(ans,res);
        ans1 = min(ans1,res1);
    } while (next_permutation(pts,pts+4));
    return ans-ans1;
}

void solve(){
    for (int i=0; i<4; i++){
        cin >> pts[i].fi >> pts[i].se;
    }
    sort(pts,pts+4);

    int sans = get_val(0,pts);
    int ans = 0;
    int l = 0, r = INF;
    while (l<r) {
        int mid = (l+r)/2;
        int a = get_val(mid,pts);
        int b = get_val(mid+1,pts);
        if (a >= b) {
            l = mid+1;
        }
        else {
            r = mid;
        }
    }
    
    // cout << l << endl;
    cout << get_val(l,pts) << endl;
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

