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

int n,m;
int a[N];
int x[N],y[N];
vector<int> order;
int ans[N];

void solve(){
    cin >> n;
    int t=0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        t+=a[i];
    }
    sort(a+1,a+1+n);
    cin >> m;
    vector<int> ord;
    for (int i=1; i<=m; i++){
        cin >> x[i] >> y[i];
        order.push_back(i);
    }

    sort(all(order),[&](int i, int j){return x[i] < x[j];});

    int idx = 1;
    for (auto id:order) {
        while (idx+1<n && a[idx+1]<x[id]) ++idx;
        int op1 = max(0LL,x[id]-a[idx]) + max(0LL,y[id]-(t-a[idx]));
        int op2 = max(0LL,x[id]-a[idx+1]) + max(0LL,y[id]-(t-a[idx+1]));
        ans[id] = min(op1,op2);
    }
    for (int i=1; i<=m; i++){
        cout << ans[i] << endl;
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

