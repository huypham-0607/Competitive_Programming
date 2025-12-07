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

int distcount[N];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        distcount[x]++;
    }

    int reachable = 0;
    for (int i=1; i<=100000; i++){
        if (!distcount[i]) continue;
        if (reachable<i-1){
            cout << reachable+1 << endl;
            return;
        }
        int tmp = i*distcount[i];
        reachable = tmp+reachable;
    }
    cout << reachable+1;
}

/*Driver Code*/
signed main(){
    freopen("COINS.inp","r",stdin);
    freopen("COINS.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
