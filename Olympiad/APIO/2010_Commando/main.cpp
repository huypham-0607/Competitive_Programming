/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
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
int a,b,c;
int dp[N];
int coef[N];
int cst[N];
int pre[N];


long double intersect(int i, int j){
    return (long double) (cst[j]-cst[i])/(coef[i]-coef[j]);
}

/*Solution*/
void solve(){
    cin >> n;
    cin >> a >> b >> c;
    for (int i=1; i<=n; i++){
        cin >> pre[i];
        pre[i] += pre[i-1];
    }

    deque<int> dq;
    dq.push_back(0);
    for (int i=1; i<=n; i++){
        while (dq.size()>1 && intersect(dq[0],dq[1]) < pre[i]) dq.pop_front();

        int j = dq.front();
        dp[i] = a*pre[i]*pre[i]+b*pre[i]+c+coef[j]*pre[i]+cst[j];
        cst[i] = dp[i]+a*pre[i]*pre[i]-b*pre[i];
        coef[i] = -2*a*pre[i];

        while (dq.size()>1 && intersect(dq[(int)dq.size()-2],dq.back()) > intersect(dq.back(),i)) dq.pop_back();
        dq.push_back(i);
    }
    cout << dp[n] << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
