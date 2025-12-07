/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 310;
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
int a[N][N];
int val[N];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        val[i] = 0;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> a[i][j];
        }
        for (int j=n; j>0; j--){
            if (a[i][j]!=1) break;
            ++val[i];
        }
    }
    sort(val+1,val+1+n);
    int ans = 0;
    for (int i=1; i<=n; i++){
        if (val[i]>=ans) ++ ans;
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
