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
int up[N],down[N];


/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> up[i];
    }
    for (int i=1; i<=n; i++){
        cin >> down[i];
    }
    int ans = -LLINF;
    for (int i=1; i<=n; i++){
        int t = up[i] + down[i];
        for (int j=1; j<=n; j++){
            if (j==i) continue;
            else t+=max(up[j],down[j]);
        }
        ans = max(ans,t);
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
