/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ull unsigned long long
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
ull n;

bool check(ull mid){
    ull sus = floor(sqrtl(mid));
    if (mid-sus>=n) return true;
    else return false;
}

/*Solution*/
void solve(){
    cin >> n;
    ull l = 1, r = LLINF*2;
    ull ans = r+1;
    while (l<=r){
        ull mid = (l+r)/2;
        if (check(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
