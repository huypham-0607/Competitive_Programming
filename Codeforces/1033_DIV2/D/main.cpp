/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7;
const int LG = 30;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int a,b,k;

int bin_pow(int a, int b){
    int res = 1;
    for (int lg=LG-1; lg>=0; lg--){
        res = res*res%MD;
        if (((int)1<<lg)&b) res = res*a%MD;
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> a >> b >> k;
    int n = k*(a-1)+1;
    int x = 1;
    for (int i=n; i>n-a; i--){
        x = x*(i%MD)%MD;
    }
    int y = 1;
    for (int i=1; i<=a; i++){
        y = y*(i%MD)%MD;
    }

//    cout << x << " " << y << endl;

    y = bin_pow(y,MD-2);

    int ans = ((x*y%MD)*k%MD*(b-1)%MD+1)%MD;

    cout << n%MD << " " << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
