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
int n,m,a,b;
int X1,X2,Y1,Y2;

/*Solution*/
void solve(){
    cin >> m >> n >> b >> a;
    cin >> X1 >> Y1 >> X2 >> Y2;
    if (X1<X2) swap(X1,X2);
    if (Y1<Y2) swap(Y1,Y2);
    int tmpx = (X1-(X2+b));
    int tmpy = (Y1-(Y2+a));
//    cout << tmpx << " " << tmpy << endl;
    if (tmpx>=0 && tmpx%b == 0) cout << "YES" << endl;
    else if (tmpy>=0 && tmpy%a == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
