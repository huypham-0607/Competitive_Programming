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
int pre[N];
int a[N];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        int cnt = 0;
        int x = i;
        while (x%2==0){
            ++cnt;
            x/=2;
        }
        pre[i] = pre[i-1]+cnt;
    }

    int ans = 0;

    for (int i=0; i<n; i++){
        int cnt = pre[n-1]-pre[n-1-i]-pre[i];
//        cout << cnt << endl;
        if (!cnt) ans = (ans^a[i]);
    }

    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
