/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "poetry"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;
const int MD = 1e9+7;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,k;
int dpline[10010];
int w[10010], v[10010];
int linecnt[10010];
int cls[30];

ll binpow(ll a, ll b) {
	if (a == 0) { return 0; }
	ll ret = 1;
	while (b > 0) {
		if (b % 2 == 1) { ret = (ret * a) % MD; }
		a = (a * a) % MD;
		b /= 2;
	}
	return ret;
}

/*Solution*/
void solve(){
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        cin >> w[i] >> v[i];
    }
    dpline[0] = 1;
    for (int i=1; i<=k; i++){
        for (int j=1; j<=n; j++){
            if (i-w[j]>=0) dpline[i] = (dpline[i]+dpline[i-w[j]])%MD;
            if (i==k) linecnt[v[j]] = (linecnt[v[j]]+dpline[i-w[j]])%MD;
        }
    }
    for (int i=1; i<=m; i++){
        char c;
        cin >> c;
        ++cls[c-'A'];
    }
    ll ans = 1;
    for (int i=0; i<26; i++){
        if (cls[i] == 0) continue;
        ll res = 0;
        for (int j=1; j<=n; j++){
            if (linecnt[j] == 0) continue;
            res = (res+binpow(linecnt[j],cls[i]))%MD;
        }
        ans = (ans*res)%MD;
    }
    cout << ans << endl;
//    for (int i=1; i<=n; i++){
//        cout << linecnt[i] << " ";
//    }
//    cout << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".in","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
