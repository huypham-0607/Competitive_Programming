/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
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
int a[N];
deque<pii> dq;

/*Solution*/
void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        while (!dq.empty() && dq.back().fi>=a[i]) dq.pop_back();
        dq.push_back({a[i],i});
        while (dq.front().se<=i-k) dq.pop_front();
        if (i-k>=0) cout << dq.front().fi << " ";
    }
}

/*Driver Code*/
signed main(){
    freopen("MINK.inp","r",stdin);
    freopen("MINK.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
