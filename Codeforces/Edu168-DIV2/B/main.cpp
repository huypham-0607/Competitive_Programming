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
int n;
int a[3][N];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=2; i++){
        for (int j=1; j<=n; j++){
            char c;
            cin >> c;
            if (c=='x') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    int cnt = 0;
    for (int i=2; i<n; i++){
        if (!a[1][i-1] && !a[1][i] && !a[1][i+1] && a[2][i-1] && !a[2][i] && a[2][i+1]) ++cnt;
        if (a[1][i-1] && !a[1][i] && a[1][i+1] && !a[2][i-1] && !a[2][i] && !a[2][i+1]) ++cnt;
    }
    cout << cnt << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
