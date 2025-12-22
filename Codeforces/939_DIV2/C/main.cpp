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
int n;
int a[N][N];
/*Solution*/
void solve(){
    cin >> n;
    int t=0;
    int meow=1;
    for (int i=1; i<=n; i++){
        t+=i*meow;
        meow+=2;
    }
    cout << t << " " << n*2 << endl;
    for (int i=n; i>0; i--){
        for (int idx=1; idx<=2; idx++){
            cout << idx << " " << i << " ";
            for (int j=1; j<=n; j++){
                cout << j << " ";
            }
            cout << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
