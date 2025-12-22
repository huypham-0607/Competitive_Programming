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
const int N = 505;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,k;



int pref[N][N][N];
int suf[N][N][N];

int a[N];

int add(int x, int y){
    return (1LL*x+y)%MD;
}

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        char c; cin >> c;
        a[i] = c-'0';
    }
    pref[0][0][0] = 1;
    int ans = 0;
    for (int i=0; i<k; i++){
        for (int j=0; j<=i; j++){
            for (int idx=n; idx>0; idx--){
                suf[i][j][idx] = add(suf[i][j][idx],suf[i][j][idx+1]);
            }
            for (int idx=1; idx<=n; idx++){
                pref[i][j][idx] = add(pref[i][j][idx],pref[i][j][idx-1]);
                int t = add(pref[i][j][idx],suf[i][j][idx]);
                cout << i << " " << j << " " << idx << " " << t << " " << a[idx] << endl;
                if (j%2 == a[idx]){
                    cout << "Through" << endl;
                    suf[i+1][j+1][idx] = add(suf[i+1][j+1][idx],t);
                    pref[i+1][j][idx+1] = add(pref[i+1][j][idx+1],t);
                    if (i+1 == k) ans = add(ans,t);
                }
            }
        }
    }
    cout << ans << endl;
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
