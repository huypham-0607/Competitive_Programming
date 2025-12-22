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
const int N = 10010;
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
int n,c;
int s[N],p[N];
vector<int> dppre;
vector<int> dp;

/*Solution*/
void solve(){
    cin >> n >> c;
    int totalp = 0;
    for (int i=1; i<=n; i++){
        cin >> p[i];
        totalp+=p[i];
    }
    for (int i=1; i<=n; i++){
        cin >> s[i];
    }
    dp.resize(n+10);
    dppre.resize(n+10);
    dppre[0] = totalp;
    for (int i=1; i<=n; i++){
        dp[0] = totalp;
        for (int j=1; j<=i; j++){
            if (j==i){
                dp[j] = dppre[j-1]-p[i]+s[i]+(n-i)*c-(j-1)*c;
            }
            else dp[j] = min(dppre[j],dppre[j-1]-p[i]+s[i]+(n-i)*c-(j-1)*c);
        }
        swap(dp,dppre);
    }
    int ans = LLINF;
    for (int j=0; j<=n; j++){
        ans = min(ans,dppre[j]);
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
