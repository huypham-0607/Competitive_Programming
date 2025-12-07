/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
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
int n,q;
int a[N];
pii dp[N];

/*Solution*/
void solve(){
    cin >> n >> q;
    int K = floor(sqrt(n));
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=n-1; i>=0; i--){
        int id = i/K;
        int j = i+a[i];
        int lim = min(n,K*(id+1));
        if (j<lim){
            dp[i] = dp[j];
            dp[i].se++;
        }
        else{
            dp[i] = {i,1};
        }
    }
//    for (int i=0; i<n; i++){
//        cout << "{" << dp[i].fi << "," << dp[i].se << "} ";
//    }
//    cout << endl;
    while (q--){
        int tpe; cin >> tpe;
        if (!tpe){
            int x,val; cin >> x >> val;
            --x;
            int id = x/K;
            a[x] = val;
            for (int i=x; i>=K*id; i--){
                int j = i+a[i];
                int lim = min(n,K*(id+1));
                if (j<lim){
                    dp[i] = dp[j];
                    dp[i].se++;
                }
                else{
                    dp[i] = {i,1};
                }
            }
//            for (int i=0; i<n; i++){
//                cout << "{" << dp[i].fi << "," << dp[i].se << "} ";
//            }
//            cout << endl;
        }
        else{
            int x; cin >> x;
            --x;
            int prev = -1, cnt = 0;
            while (x<n){
                cnt+=dp[x].se;
                prev = dp[x].fi;
                x = prev+a[prev];
            }
            cout << prev+1 << " " << cnt << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
