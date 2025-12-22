/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 998244353;
const int LG = 30;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,p,q;
int dp[N];
int cur[N];
int pre[N];
pair<pii,pii> v[N];

int bin_pow(int a, int b){
    ll res = 1;
    for (int lg=LG-1; lg>=0; lg--){
        res = res*res%MD;
        if ((1<<lg)&b) res = res*a%MD;
    }
    return res;
}

int inv_mod(int x){
    return bin_pow(x,MD-2);
}

//int BIT[N];
//void Update(int x, int val){
//    while (x<=n){
//        BIT[N] = BIT[val]
//    }
//}

void Update(int x, int i){
    dp[x] = dp[x]*(pre[i]*inv_mod(pre[cur[x]])%MD)%MD;
    cur[x] = i;
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        int l,r,p,q; cin >> l >> r >> p >> q;
        v[i] = make_pair(make_pair(r,l),make_pair(p,q));
        cur[i] = 0;
        dp[i] = 0;
        pre[i] = 0;
    }
    pre[0] = 1;
    sort(v+1,v+1+n);
    for (int i=1; i<=n; i++){
        int p = v[i].se.fi;
        int q = v[i].se.se;
        pre[i] = (q-p)*inv_mod(q)%MD;
        pre[i] = pre[i]*pre[i-1]%MD;
//        cout << pre[i] << endl;
    }

    dp[0] = 1;
    for (int i=1; i<=n; i++){
        int r = v[i].fi.fi;
        int l = v[i].fi.se;
        int p = v[i].se.fi;
        int q = v[i].se.se;
        Update(r,i);
        Update(l-1,i-1);
        dp[r] = (dp[r] + dp[l-1]*(p*inv_mod(q)%MD)%MD)%MD;
    }
    cout << dp[m] << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
