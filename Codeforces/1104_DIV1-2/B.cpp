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


void solve(){
    cin >> n;
    vector<int> a,b,c;
    ffor(i,1,n) {int x; cin >> x; a.push_back(x);}
    ffor(i,1,n) {int x; cin >> x; b.push_back(x);}

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (a[i]<=b[j]) {
                c.push_back(j);
                break;
            }
            if (j==n-1) c.push_back(n);
        }
    }

    // for (auto x:c) cout << x << " "; cout << endl;

    int ans = 0;
    for (int i=0; i<n; i++){
        if (c[i]<=i) continue;
        int x = n;
        for (int j=i+1; j<n; j++){
            if (c[j]<=i) {
                x = j;
                break;
            }
        }
        if (x == n) {
            cout << -1 << endl;
            return;
        }
        int val = c[x];
        for (int j=x; j>i; j--){
            swap(c[j-1],c[j]);
            ++ans;
        }
    }
    // for (auto x:c) cout << x << " "; cout << endl;

    for (int i=0; i<n; i++){
        if (c[i] > i){
            cout << -1 << endl;
            return;
        }
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

