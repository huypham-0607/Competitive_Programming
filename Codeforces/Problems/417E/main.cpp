/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
vector<int> a,b;

void get(int x, vector<int> &v) {
    if (x == 1) {
        v.push_back(x);
    }
    else if (x == 2) {
        v.push_back(3);
        v.push_back(4);
    }
    else if (x%2 == 0) {
        int p = x/2;
        for (int i=1; i<x; i++) {
            v.push_back(1);
        }
        v.push_back(p-1);
    }
    else {
        int p = (x-1+4)/2;
        for (int i=1; i<p*2-4; i++) {
            v.push_back(1);
        }
        v.push_back(2);
        v.push_back(p-1);
    }
}

void solve(){
    cin >> n >> m;
    get(n,a);
    get(m,b);
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++) {
            cout << a[i]*b[j] << " ";
        }
        cout << endl;
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
