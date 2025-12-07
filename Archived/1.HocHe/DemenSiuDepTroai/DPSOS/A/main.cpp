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
const int N = 1e6+10;
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
int a[N*2];
int F[N*2];

/*Solution*/
void solve(){
    cin >> n >> m;
    int res = 0;
    for (int i=n-1; i>=0; i--){
        cin >> a[i];
        res = res^a[i];
    }
    for (int i=0; i<n; i++){
        F[i] = a[i];
    }
    for (int i=0; i<20; i++){
        for (int mask=0; mask<(1<<20); mask++){
            if ((mask>>i)&1) F[mask]^=F[mask^(1<<i)];
        }
//        for (int mask=0; mask<m; mask++){
//            cout << F[mask] << " ";
//        }
//        cout << endl;
    }
//    cout << res << " ";
    for (int i=0; i<m; i++){
        cout << F[((1<<20)-1)^i]  << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
