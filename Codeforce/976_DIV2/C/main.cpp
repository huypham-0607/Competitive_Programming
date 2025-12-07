/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 62;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int b,c,d;

/*Solution*/
void solve(){
    cin >> b >> c >> d;
    int a = 0;
    for (int lg=LG-1; lg>=0; lg--){
        if ((b&(1LL<<lg)) && !(c&(1LL<<lg))){
            if (!(d&(1LL<<lg))){
                cout << -1 << endl;
                return;
            }
        }
        else if (!(b&(1LL<<lg)) && (c&(1LL<<lg))){
            if ((d&(1LL<<lg))){
                cout << -1 << endl;
                return;
            }
        }
        else if (!(b&(1LL<<lg)) && !(c&(1LL<<lg))){
            if ((d&(1LL<<lg))){
                a^=(1LL<<lg);
            }
        }
        else{
            if (!(d&(1LL<<lg))){
                a^=(1LL<<lg);
            }
        }
    }
    cout << a << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
