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

/*Solution*/
void solve(){
    int mxodd=0,mxeven=0,oddcnt=0,evencnt=0;
    cin >> n;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        if (i%2==1){
            mxodd = max(mxodd,x);
            oddcnt++;
        }
        else{
            mxeven = max(mxeven,x);
            evencnt++;
        }
    }
    cout << max(mxodd+oddcnt,mxeven+evencnt) << endl;

}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
