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
pii a,b;

/*Solution*/
void solve(){
    cin >> n >> a.se >> b.se >> a.fi >> b.fi;
    if (a>b) swap(a,b);

    int cnt = 0;
    if (a.se > b.se){
        if (n>=a.se){
            cnt += (n-a.se)/a.fi + 1;
            n-=a.fi*cnt;
        }
        if (n>=b.se){
            cnt += (n-b.se)/b.fi + 1;
        }
    }
    else {
        if (n>=a.se){
            cnt += (n-a.se)/a.fi + 1;
        }
    }

    cout << cnt << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
