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
const int N = 510;
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
int n,m,k,s;
int tmp[N][N];


/*Solution*/
void solve(){
    cin >> n >> m >> k >> s;
    for (int i=1; i<=k; i++){
        for (int j=1; j<=k; j++){
            if (s){
                tmp[i][j] = 1;
                --s;
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << tmp[(i-1)%k+1][(j-1)%k+1] << " ";
        }
        cout << endl;
    }
}

/*Driver Code*/
signed main(){
    freopen("PHATSINH.INP","r",stdin);
    freopen("PHATSINH.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
