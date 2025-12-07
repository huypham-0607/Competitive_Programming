/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,k;

/*Solution*/
void solve(){
    cin >> n >> k;
    if (k == n*n-1){
        cout << "NO" << endl;
        return;
    }
    k = n*n-k;
    vector<vector<char>> ans (n,vector<char>(n,'A'));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int val = i*n+j;
            if (val>=k){
                ans[i][j] = 'D';
            }
            else{
                if (i == 0){
                    if (j == 0) ans[i][j] = 'R';
                    else ans[i][j] = 'L';
                }
                else ans[i][j] = 'U';
            }
        }
    }
    cout << "YES" << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
