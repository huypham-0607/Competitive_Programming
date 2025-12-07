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
int n,m;
int a[N];
vector<pii> v;
int dp[30030];
int trace[30030];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());
    dp[0] = 1;

    for (auto in:v){
        int x = in.fi;
        int idx = in.se;
        for (int i=1; i<=30000; i++){
            if (i-x<0) continue;
            if (dp[i] == 0){
                if (dp[i-x] == 1){
                    trace[i] = idx;
                    dp[i] = 1;
                }
                else if (dp[i-x] == 2) dp[i] = 2;
            }
            else if (dp[i] == 1){
                if (dp[i-x]>0) dp[i] = 2;
            }
        }
    }

//    for (int i = 0; i < 10; ++i) cout << dp[i] << ' ';
    cin >> m;

    for (int i=1; i<=m; i++){
        int x;
        cin >> x;
        if (dp[x]==0) cout << "NO" << endl;
        else if (dp[x] == 2) cout << "MANY" << endl;
        else{
            vector<int> tmp;
            int cur = x;
            while (cur!=0){
                tmp.push_back(trace[cur]);
                cur = cur-a[trace[cur]];
            }
            sort(tmp.begin(),tmp.end());
            for (auto rawr:tmp){
                cout << rawr << " ";
            }
            cout << endl;
        }
    }

}

/*Driver Code*/
signed main(){
//    freopen("MENU.inp","r",stdin);
//    freopen("MENU.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
