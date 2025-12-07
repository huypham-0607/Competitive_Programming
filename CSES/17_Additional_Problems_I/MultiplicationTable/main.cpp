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
int n;

bool check(int x){
    int pos = 0;
    for (int i=1; i<=n; i++){
        pos += min(n,x/i);
    }
    if (pos<=n*n/2) return true;
    return false;
}

/*Solution*/
void solve(){
    cin >> n;
    int l = 1;
    int r = n*n;
    int ans = 0;
    while (l<=r){
        int mid = (l+r)/2;
        if (check(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans+1 << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
