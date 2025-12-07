/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "bubbletea"

using namespace std;

/*Constants*/
const int N = 1e7+10;
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
int n;
ll p,q,m,k;
deque<pair<ll,int>> dq;

/*Solution*/
void solve(){
    cin >> n >> k;
    cin >> p >> q >> m;
    for (ll i=1; i<=n; i++){
        ll x = (p*i)%m+q;
        ll val = x+i*k;
        while (!dq.empty() && val>=dq.back().fi) dq.pop_back();
        dq.push_back({val,i});
    }
    ll res = dq.front().fi;
//    cout << res << endl;
    for (ll i=1; i<=n; i++){
        while (!dq.empty() && dq.front().se<=i) dq.pop_front();
        ll x = (p*i)%m+q;
        ll val = x+n*k+i*k;
        while (!dq.empty() && val>=dq.back().fi) dq.pop_back();
        dq.push_back({val,i+n});
        res = min(res,dq.front().fi-i*k);
    }
    cout << res;
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

