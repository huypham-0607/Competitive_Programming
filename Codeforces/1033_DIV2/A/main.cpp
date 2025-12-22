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
int l1,l2,l3,b1,b2,b3;

/*Solution*/
void solve(){
    bool ver = false;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if (l1 == l2 && l2 == l3){
        if (b1 + b2 + b3 == l1) ver = true;
    }

    if (b1 == b2 && b2 == b3){
        if (l1 + l2 + l3 == b1) ver = true;
    }

    if (l2 == l3){
        int b = b2 + b3;
        if (b == b1){
            if (l1 + l2 == b1) ver = true;
        }
    }

    if (b2 == b3){
        int l = l2 + l3;
        if (l == l1){
            if (b1 + b2 == l1) ver = true;
        }
    }

    if (ver) cout << "YES" << endl;
    else cout << "NO" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
