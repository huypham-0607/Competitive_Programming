#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT "InterstellarIntervals"

using namespace std;

/*Constants*/
const int N = 5e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;
vector<int> a(N,0);
vector<int> dp(N,0);
vector<int> ans(10,0);
vector<int> used(N,0);
vector<int> val(N,0);

vector<vector<int>> store(N,vector<int>());

/*Solution*/
void solve(){
    cin >> n;
    string s;
    for (int i=0; i<n; i++){
        char c; cin >> c;
//        if (s[i] == 'R') a[i+1] = 1;
//        if (s[i] == 'B') a[i+1] = 2;
        if (c == 'R') a[i+1] = 1;
        if (c == 'B') a[i+1] = 2;
        if (c == 'X') a[i+1] = 0;
    }

    int last = -1;
    int lastb = n+1;
//    int sus = 0;
    for (int j=1; j<=n; j++){
        if (a[j] == 2){
            int i, tmp=-1;
            for (i=j+1; i<=n; i++){
                int pos = 2*j-i;
                if (pos<=last) break;
                if (i>n) break;
//                ++sus;
                tmp = max(tmp,pos);
                store[i].push_back(j);
            }
            if (tmp!=-1) last = tmp;
        }
    }
//    cout << ans[0] << " " << ans[1] << endl;
//    cout << ans.size() << endl;
//    cout << sus << endl;
    dp[0] = 1;
    val[0] = 1;
    ans[0] += dp[0];
    int lastr = 0;
    int cnt = 0;
    for (int i=1; i<=n; i++){
        int par = i%2;
        if (a[i] == 1){
            ans[0] = 0;
            ans[1] = 0;
            lastr = i;
        }
        else{
            int pos = i-(i-lastr)*2;
            if (pos>=0) ans[pos%2] = (ans[pos%2]+val[pos])%MD;
        }
        for (auto j:store[i]){
//            int x = (i-j)/2;
            int pos = 2*j-i;
            if (pos>=0 && !used[pos]){
                val[pos] = (val[pos] - dp[pos]+MD)%MD;
                if (pos >= i-(i-lastr)*2){
                    ans[pos%2] = (ans[pos%2] - dp[pos]+MD)%MD;
                }
                used[pos] = true;
            }
        }

        dp[i] = ans[par];
        if (a[i] == 0){
            dp[i] = (dp[i]+dp[i-1])%MD;
        }
        val[i] = dp[i];
        ans[par] = (ans[par]+val[i])%MD;
    }
    cout << dp[n] << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
//    if (fopen(TEXT".inp","r")){
//        freopen(TEXT".inp","r",stdin);
//        freopen(TEXT".out","w",stdout);
//    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
