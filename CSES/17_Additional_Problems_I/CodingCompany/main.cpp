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
const int MD = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,x;
int a[105];
vector<vector<int>> dp1(105,vector<int>(10010)), dp2(105,vector<int>(10010));

/*Solution*/
void solve(){
    cin >> n >> x;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int mid = 5000;
    dp1[0][mid] = 1;
    for (int i=1; i<=n; i++){
        for (int j=0; j<=i; j++){
            for (int k=0; k<=mid*2; k++){
                dp2[j][k] = dp1[j][k];
                dp2[j][k] = (dp2[j][k]+((ll)dp1[j][k]*j)%MD)%MD;
                if (k-a[i]>=0 && j+1<=i) dp2[j][k] = (dp2[j][k]+((ll)dp1[j+1][k-a[i]]*(j+1))%MD)%MD;
                if (k+a[i]<=mid*2 && j-1>=0) dp2[j][k] = (dp2[j][k]+((ll)dp1[j-1][k+a[i]])%MD)%MD;
            }
        }
//        for (int j=0; j<=n; j++){
//            for (int k=mid-x; k<=mid+x; k++){
//                cout << dp2[j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
        swap(dp1,dp2);
    }
    int res = 0;
    for (int k=mid; k<=mid+x; k++){
        res = (res+dp1[0][k])%MD;
    }
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
