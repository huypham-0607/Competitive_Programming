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
int n,m;

/*Solution*/
void solve(){
    cin >> n >> m;
    int ans = 0;
    for (int i=0; i<=31; i++){
        int div = ((long long)1<<(i+1));
        int tmp = n%div+1;
        if (tmp > div/2){
            ans += ((long long)1<<i);
        }
        else{
            int dist = (div/2-tmp+1);
            if (n > tmp-1) dist = min(dist,tmp);
            if (m >= dist) ans+=((long long)1<<i);
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
