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
const int N = 500+10;
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
int n,m,k;
int a[N][N], pre[N][N],blocked[N][N];

/*Solution*/
void solve(){
    int cnt = 0;
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            a[i][j] = 0;
            pre[i][j] = 0;
            blocked[i][j] = 0;
            char c; cin >> c;
            if (c == '#') blocked[i][j] = 1;
            if (c == 'g'){
                blocked[i][j] = 1;
                a[i][j] = 1;
                ++cnt;
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            pre[i][j] = a[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    int ans = INF;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            int i1 = max(0,i-k);
            int j1 = max(0,j-k);
            int i2 = min(n,i+k-1);
            int j2 = min(m,j+k-1);
            int val = pre[i2][j2] - pre[i1][j2] - pre[i2][j1] + pre[i1][j1];
            if (!blocked[i][j]){
                ans = min(ans,val);
//                cout << "val: " << val << " " << i << " " << j << endl;
            }
        }
    }

    cout << max(0,cnt-ans) << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
