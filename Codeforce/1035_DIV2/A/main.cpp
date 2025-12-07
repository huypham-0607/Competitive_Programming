/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
int a,b,x,y;

/*Solution*/
void solve(){
    cin >> a >> b >> x >> y;
    if (a<b){
        int cnt = 0;
        while (a<b){

            if (a&1) cnt+=x;
            else cnt+=min(x,y);
            a++;
        }
        cout << cnt << endl;
        return;
    }
    if (a==b) cout << 0 << endl;
    else{
        if ((a^1) == b) cout << y << endl;
        else cout << -1 << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
