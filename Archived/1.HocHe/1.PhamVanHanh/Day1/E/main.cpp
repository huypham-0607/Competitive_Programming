/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "greedy-is-wrong"

using namespace std;

/*Constants*/
const int N = 55;
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

int check(int idx, int sus){
    for (int j=1; j<=n; j++){
        int cur = 0;
        int cnt = 0;
        for (int i=1; i<=n; i++){
            int val;
            if (sus!=0 && i == idx) val = sus;
            else val = a[i][j];
            if (val!=cur){
                cur = val;
                cnt = 1;
            }
            else ++cnt;
            if (cnt > n/2) return false;
        }
    }
    return true;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            char c;
            cin >> c;
            if (c == 'W') a[i][j] = 1;
            else a[i][j] = 2;
        }
    }
    if (check(1,0)){
        cout << 0 << endl;
        return;
    }
    int res = 0;
    for (int rawr = 1; rawr<=2; rawr++){
        for (int idx=1; idx<=n; idx++){
            if (check(idx,rawr)) res = 1;
        }
    }
    if (!res) res = 2;
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
