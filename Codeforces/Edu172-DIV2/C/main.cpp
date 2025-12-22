/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
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
int n,k;
int a[N],suf[N];
vector<int> v;

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        char c;
        cin >> c;
        if (c == '1') a[i] = 1;
        else a[i] = -1;
    }
    int t = 0;
    for (int i=n; i>1; i--){
        suf[i] = suf[i+1]+a[i];
        t+=suf[i];
        v.push_back(suf[i]);
    }
    int ans = n+1;
    sort(all(v));
    for (int i=0; i<((int)v.size()); i++){
        int idx = n-i;
//        cout << idx << " " << t << " " << v[i] << endl;
        if (t>=k) ans = idx;
        t-=v[i];
    }
    if (ans == n+1) cout << -1 << endl;
    else cout << ans << endl;
    for (int i=1; i<=n; i++){
        a[i] = 0;
        suf[i] = 0;
    }
    v.clear();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
