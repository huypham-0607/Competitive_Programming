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
const int N = 4e3+10;
const int INF = 1e9+7;
const int MD = 998244353;
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
int dpin[N][N],dpout[N][N];
int ans[N];
string s;


/*Solution*/
void solve(){
    cin >> s;
    n = (int) s.size();
    s = "#"+s;
    if (s[1] == s[n]){
        dpout[1][n] = 1;
    }
    else dpout[1][n] = 0;
    for (int delta=n-1; delta>=1; delta--){
        for (int l=1; l+delta-1<=n; l++){
            int r = l+delta-1;
            dpout[l][r] = (dpout[l-1][r]+dpout[l][r+1])%MD-dpout[l-1][r+1];
            if (dpout[l][r]<0) dpout[l][r]+=MD;
            if (s[l] == s[r]) dpout[l][r] = (dpout[l][r]+dpout[l-1][r+1]+1)%MD;
        }
    }
    for (int i=1; i<=n; i++){
        dpin[i][i] = 1;
    }
    for (int i=2; i<=n; i++){
        if (s[i] == s[i-1]) dpin[i-1][i] = 3;
        else dpin[i-1][i] = 2;
    }
    for (int delta = 3; delta<=n; delta++){
        for (int l=1; l+delta-1<=n; l++){
            int r = l+delta-1;
            dpin[l][r] = (dpin[l][r-1]+dpin[l+1][r])%MD-dpin[l+1][r-1];
            if (dpin[l][r]<0) dpin[l][r]+=MD;
            if (s[l] == s[r]) dpin[l][r] = (dpin[l][r]+dpin[l+1][r-1]+1)%MD;
        }
    }
    for (int i=1; i<=n; i++){
        ans[i] = (ans[i] + dpout[i-1][i+1]+1)%MD;
    }
    for (int r=1; r<=n; r++){
        for (int l=1; l<r; l++){
            if (s[l] == s[r]){
                if (l==r-1){
                    ans[l] = (ans[l] + dpout[l-1][r+1]+1)%MD;
                    ans[r] = (ans[r] + dpout[l-1][r+1]+1)%MD;
                }
                else{
                    ans[l] = (ans[l] + (((ll)dpout[l-1][r+1]+1)*((ll)dpin[l+1][r-1]+1))%MD)%MD;
                    ans[r] = (ans[r] + (((ll)dpout[l-1][r+1]+1)*((ll)dpin[l+1][r-1]+1))%MD)%MD;
                }
            }
        }
    }
    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << dpin[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << dpout[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

