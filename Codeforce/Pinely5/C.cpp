/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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

int n,x;
int a[N];

void solve(){
    cin >> n >> x;
    int t =0 ;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        t+=a[i];
    }
    sort(a+1,a+1+n);
    int cnt = t/x;
    int ans = 0;



    int l=1,r=n;
    int cur = 0;
    vector<int> order;
    int idx = 0;
    while (l<=r){
        if (cur < x-a[r]){
            order.push_back(a[l]);
            cur = (cur+a[l])%x;
            ++l;
        }
        else {
            order.push_back(a[r]);
            cur = (cur+a[r])%x;
            ans += a[r];
            --r;
        }
//        cout << l << " " << r << endl;
    }
    cout << ans << endl;
    for (auto x:order){
        cout << x << " ";
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

