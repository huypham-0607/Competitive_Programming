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
int n,m;
int a[10][10];
/*Solution*/
void solve(){
    cin >> n >> m;
    if (n==1 && m==1){
        int tmp;
        cin >> tmp;
        cout << -1 << endl;
        return;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (n==1) cin >> a[i][(j+1)%m];
            else cin >> a[(i+1)%n][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
