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
const int N = 1e6+10;
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
    int t = 0;
    int mn = INF;
    int mx = -INF;
    int cnt = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        if (a[i]>0){
            ++cnt;
            t+=a[i];
            mn = min(mn,a[i]);
        }
        else{
            mx = max(mx,a[i]);
        }
    }
    if (cnt%2==0){
        cout << t+max(mx,-mn);
    }
    else cout << t;

}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
