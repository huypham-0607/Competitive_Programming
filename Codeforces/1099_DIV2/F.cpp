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

int n,q;
int ps[N];
int f[N];
int g[N];

bool check1(int a, int b) {
    if (a>b) swap(a,b);
    return ps[b-a];
}

bool check2(int a, int b) {
    if (a>b) swap(a,b);
    int delta = b-a;
    int ex = max(a-1,n-b);
    return (f[delta] || (g[delta]*g[delta]-delta<=ex));
}

bool check3(int a, int b) {
    if (a>b) swap(a,b);
    for (int i=1; a+i*i<=n; i++) {
        int mid = a+i*i;
        if (check2(mid,b)) return true;
    }
    for (int i=1; a-i*i>0; i++) {
        int mid = a-i*i;
        if (check2(mid,b)) return true;
    }
    return false;
}

void solve(){
    cin >> n >> q;

    for (int i=0; i<=n; i++){
        g[i] = INF;
        f[i] = 0;
        ps[i] = 0;
    }
    for (int i=1; i*i<=n; i++) {
        ps[i*i] = true;
        for (int j=1; j<=i; j++){
            int x = i*i+j*j;
            if (x<=n) f[x] = 1;

            x = i*i-j*j;
            if (x<=n) g[x] = min(g[x],i);
        }
    }

    for (int i=1; i<=q; i++){
        int a,b; cin >> a >> b;
        // cout << a << " " << b << " " << g[b-a] << endl;
        if (check1(a,b)) {
            cout << 1 << endl;
            continue;
        }
        if (check2(a,b)) {
            cout << 2 << endl;
            continue;
        }
        if (check3(a,b)) {
            cout << 3 << endl;
            continue;
        }
        else {
            cout << 4 << endl;
        }
    }
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

