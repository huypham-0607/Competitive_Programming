/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "camera"

using namespace std;

/*Constants*/
const int N = 3e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,k,r,t;
int a[N];
bool res[N];

/*Solution*/
void solve(){
    int rawr = 0;
    cin >> n >> k >> r >> t;
    for (int i=1; i<=k; i++){
        int x; cin >> x;
        a[x] = 1;
        if (x<=r) ++rawr;
    }
    int ans = 0;
    int tmp = r;
//    cout << rawr << endl;
    while (rawr<t){
        if (!a[tmp]){
            a[tmp] = 1;
            res[tmp] = true;
            ++rawr;
            ++ans;
        }
        --tmp;
    }

    int cur = 0;
    for (int i=1; i<=n; i++){
        cur+=a[i];
        if (i>r){
            cur-=a[i-r];
            if (cur<t){
                a[i] = 1;
                res[i] = true;
                ++cur;
                ++ans;
            }
        }
    }
//    for (int i=1; i<=n; i++){
//        cout << a[i] << " " << res[i] << endl;
//    }
    cout << ans << endl;
    for (int i=1; i<=n; i++){
        if (res[i]) cout << i << " ";
    }
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
