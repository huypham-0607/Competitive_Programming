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
int n,k;
string s;

int check(){
    auto prev = s[1];
    s[0] = s[1];
    s[n+1] = (s[n] == '0')? '1' : '0';
    int cnt = 0;
    for (int i=1; i<=n+1; i++){
        if (s[i]!=prev || i == n+1){
            if (cnt > k){
                return i-k;
            }
            if (cnt < k){
                return i;
            }
            cnt = 1;
        }
        else ++cnt;
        prev = s[i];
    }
    return 0;
}

/*Solution*/
void solve(){
    cin >> n >> k;
    cin >> s;
    if (s[0] == '1') s = "0"+s;
    else s = "1"+s;
    int res = check();
    if (res!=0){
        reverse(s.begin()+res,s.begin()+n+1);
//        cout << res << " " << s << endl;
        int res2 = check();
        if (res2!=0) cout << -1 << endl;
        else cout << res-1 << endl;
    }
    else cout << n << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
