/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
vector<int> v;

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int ans = 0;
    int diff = 0;
    sort(v.begin(),v.end(),greater<int>());
    for (int i=0; i+1<n; i+=2){
        diff+=v[i]-v[i+1];
    }
    if (n%2==1) ans+=v[n-1];
    cout << ans+max((int)0,diff-k) << endl;
    v.clear();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
