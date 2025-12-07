/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "MRTINO"

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
int x;

/*Solution*/
void solve(){
    cin >> x;
    if (x==1){
        cout << 1 << endl;
        return;
    }
    int pos = 63-__builtin_clzll(x-1);
    cout << (((x-1)^((int)1<<pos))+1)*2 << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
