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
int s[N];
int a[N], c[N];

void solve(){
    cin >> n;
    c[0] = -LLINF;
    for (int i=1; i<=n; i++){
        char c; cin >> c;
        s[i] = c-'0';
    }
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> c[i];
    }
    for (int i=1; i<=n; i++){
        if (c[i-1] > c[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    int lost_idx = 0;
    int cur_perf = 0;
    int prev = -LLINF;
    for (int i=1; i<=n; i++){
        // cout << "idx: " << i << endl;
        // for (int i=1; i<=n; i++){
        //     cout << a[i] << " ";
        // }
        if (i == 1) {
            if (s[i]) {
                if (a[i] != c[i]) {
                    cout << "NO" << endl;
                    return;
                }
            }
            a[i] = c[i];
            prev = c[i];
            // cout << a[i] << endl;
            continue;
        }

        if (prev != c[i]) {
            int delta = c[i] - prev + abs(cur_perf);
            if (s[i]) {
                if (a[i] < delta) {
                    cout << "NO" << endl;
                    return;
                }
                else {
                    if (lost_idx) {
                        a[lost_idx] -= a[i] - delta;
                    }
                    else if (a[i] != delta) {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
            else {
                a[i] = delta;
            }
            cur_perf = 0;
            lost_idx = 0;
            prev = c[i];
        }
        else {
            if (!lost_idx) {
                if (s[i]) {
                    cur_perf += a[i];
                    if (cur_perf > 0) {
                        cout << "NO" << endl;
                        return;
                    }
                }
                else {
                    lost_idx = i;
                    a[lost_idx] = -cur_perf;
                    cur_perf = 0;
                }
            }
            else {
                if (s[i]) {
                    cur_perf += a[i];
                    if (cur_perf > 0) {
                        a[lost_idx] -= cur_perf;
                        cur_perf = 0;
                    }
                }
                else {
                    lost_idx = i;
                    a[lost_idx] = -cur_perf;
                    cur_perf = 0;
                }
            }
        }

        // for (int i=1; i<=n; i++){
        //     cout << a[i] << " ";
        // }
        // cout << endl;
    }

    cout << "YES" << endl;
    for (int i=1; i<=n; i++) {
        cout << a[i] << " ";
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

