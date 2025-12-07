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
int divi;
int a[100];

/*Solution*/
void solve(){
    cin >> n;
    int deno = 1;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        deno = deno/__gcd(deno,a[i])*a[i];
    }
    int cur = 0;
    for (int i=1; i<=n; i++){
        cur = cur+(deno/a[i]);
        if (cur >= deno){
            cout << -1 << endl;
            return;
        }
    }
    for (int i=1; i<=n; i++){
        cout << deno/a[i] << " ";
    }
    cout << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i=1; i<=20; i++){
        divi = divi*i;
    }

    TestCases(1);

    return 0;
}
