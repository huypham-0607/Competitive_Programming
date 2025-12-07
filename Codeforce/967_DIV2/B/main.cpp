/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
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
    if (n%2==0){
        cout << -1 << endl;
        return;
    }
    for (int i=1; i<=n; i++){
        a[i] = 0;
    }
    for (int i=1; i<=n/2; i++){
        a[i] = i*2;
    }
    a[n/2+1] = 1;
    for (int i=1; i<=n/2; i++){
        a[n-i+1] = i*2+1;
    }
    for (int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
