/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "ILIGHT"

using namespace std;

/*Constants*/
const int N = 1e5+10;
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
int a[N][2];
int cur[N];
ll ans = 0;

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    for (int i=1; i<=k; i++){
        int x;
        cin >> x;
        for (int j=1; j<=n; j++){
            if (x>=a[j][cur[j]]) cur[j] = (cur[j]+1)%2;
        }
    }
    for (int j=1; j<=n; j++){
        ans+=a[j][cur[j]];
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".ans","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
