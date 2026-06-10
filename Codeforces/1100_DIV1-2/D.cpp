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
int b[N];
vector<int> pos[N];
int val[N];

bool check(int x) {
    for (int i=1; i<=n; i++){
        val[i] = 0;
    }
    for (int i=1; i<x; i++){
        for (auto idx:pos[i]) {
            ++val[idx];
        }
    }

    int t = 0;
    int cmp = 0;
    int cur = 0;
    for (int i=1; i<=n; i++){
        if (val[i] == 0) {
            ++cmp;
            if (cur != 0) {
                ++cmp;
                t+=cur;
                cur = 0;
            }
        }
        cur = max(cur,val[i]);
    }
    if (cur != 0) {
        ++cmp;
        t+=cur;
    }
    return (t > cmp-1);
}

void solve(){
    cin >> n;
    vector<int> v;
    for (int i=1; i<=2*n; i++){
        pos[i].clear();
    }
    for (int i=1; i<=n; i++){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    ffor (i,1,n) {
        cin >> b[i];
        pos[b[i]].push_back(i);
    }
    int ans = 2*n+1;
    int l = 1, r = 2*n;

    while (l<=r) {
        int mid = (l+r)/2;
        if (check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans-1 << endl;
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

