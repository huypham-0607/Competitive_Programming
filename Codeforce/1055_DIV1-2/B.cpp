/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;
int xk,yk,xd,yd;

/*Solution*/
void solve(){
    cin >> n >> xk >> yk >> xd >> yd;
    int deltax, deltay;
    if (xd > xk) deltax = xd;
    else if (xd < xk) deltax = n-xd;
    else deltax = 0;
    if (yd > yk) deltay = yd;
    else if (yd < yk) deltay = n-yd;
    else deltay = 0;
    cout << max(deltax, deltay) << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
//    if (fopen(TEXT".inp","r")){
//        freopen(TEXT".inp","r",stdin);
//        freopen(TEXT".out","w",stdout);
//    }

    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
