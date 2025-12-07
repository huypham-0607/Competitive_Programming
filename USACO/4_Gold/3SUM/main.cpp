/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
//#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "threesum"

using namespace std;

/*Constants*/
const int N = 5010;
const int INF = 1e9+7;
const int MD = 1e9+7;
const int SHIFT = 1e6;
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
//map<int,int> mp[N];
vector<int> freq(SHIFT*2+10,0);
ll dp[N][N];

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=i-1; j>0; j--){
            int val = a[i] + a[j] + SHIFT;
//            cout << j << " " << i << " " << val << " " << freq[val] << endl;
            if (val>=0 && val<=SHIFT*2){
                dp[j][i]+=freq[val];
            }
            freq[-a[j]+SHIFT]++;
        }
        for (int j=i-1; j>0; j--) freq[-a[j]+SHIFT]--;
    }

//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }

    for (int delta=2; delta<n; delta++){
        for (int i=1, j=i+delta; j<=n; i++,j++){
//            cout << i << " " << j << endl;
            dp[i][j] = dp[i][j] + dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
        }
    }

//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }

    for (int i=1; i<=q; i++){
        int l,r; cin >> l >> r;
        cout << dp[l][r] << endl;
    }
}

/*Driver Code*/
signed main(){
    freopen(NAME".in","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
