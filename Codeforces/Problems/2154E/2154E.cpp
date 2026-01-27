/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "2154E"

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

int n,k;
int a[N];
int pre[N];
int preb[N];
int b[N];

int bin_search(int s, int range) {
    int ans = 0;
    int delta = 0;
    int l = 1, r = range;
    while (l<=r) {
        int mid = (l+r)/2;
        int x = a[s]*(k*(mid-1)+(mid-1)) - preb[mid-1] - (pre[s+mid-1]-pre[s]);
        int y = a[s]*(k*mid+mid) - preb[mid] - (pre[s+mid]-pre[s]);
        // cout << mid << " " << x << " " << y << endl;
        if (y >= x) {
            ans = mid;
            delta = y;
            l = mid+1;
        } 
        else {
            r = mid-1;
        }
    }
    return delta;
}

void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);

    for (int i=1; i<=n; i++){
        pre[i] = pre[i-1]+a[i];
        b[i] = LLINF;
        preb[i] = LLINF;
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        int bid = (i-2)/k+1;
        if (i>1) {
            int bid = (i-2)/k+1;
            int md = (i-2)%k;
            if (md == 0) {
                b[bid] = a[i]*k;
            } else {
                b[bid] += (a[i]-a[i-1])*(k-md);
            }
            b[bid] += a[i-1]-a[i];
            preb[bid] = b[bid]+preb[bid-1];
        }
        // for (int i=0; i<=n; i++){
        //     cout << b[i] << " ";
        // }
        // cout << endl;
        int res = bin_search(i,min(n-i,bid));
        // cout << res << endl;
        ans = max(ans,res);
    }
    cout << pre[n]+ans << endl;
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

