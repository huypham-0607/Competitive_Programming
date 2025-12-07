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

int cproduct(int x1, int y1, int x2, int y2){
    return (x1*y2-x2*y1);
}

/*Solution*/
void solve(){
    int x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int meow = cproduct(x2-x1,y2-y1,x3-x2,y3-y2);
    if (meow == 0) cout << "TOUCH" << endl;
    else if (meow > 0) cout << "LEFT" << endl;
    else cout << "RIGHT" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
