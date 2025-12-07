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
const int N = 1e6+10;
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
int a[N];
vector<int> v;

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        char c;
        cin >> c;
        if (c == 'T') v.push_back(i);
    }
    long long ans = 0;
    for (int i=0; i<n/2; i++){
        int idx = 1+2*i;
        ans+=abs(v[i]-idx);
    }
    cout << ans;
}

/*Driver Code*/
signed main(){
    freopen("thesis.inp","r",stdin);
    freopen("thesis.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

