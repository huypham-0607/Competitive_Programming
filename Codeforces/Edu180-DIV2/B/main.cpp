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
int a[N];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<n; i++){
        if (abs(a[i]-a[i+1]) <= 1){
            cout << 0 << endl;
            return;
        }
    }
    int pre;
    if (a[2] - a[1]>0) pre = 1;
    else pre=-1;
    for (int i=2; i<n; i++){
        int cur = (a[i+1]-a[i]>0)? 1 : -1;
        if (cur*pre<0){
            cout << 1 << endl;
            return;
        }
        pre = cur;
    }
    cout << -1 << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
