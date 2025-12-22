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
int n;
int a,x,y;

/*Solution*/
void solve(){
    cin >> a >> x >> y;
    if (x>y) swap(x,y);
    if (x < a && a < y){
        cout << "NO" << endl;
        return;
    }
    if (x-1 == a || y+1 == a){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases();

    return 0;
}
