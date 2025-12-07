/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
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
int n,q;
string s;
string ans;
int state[N];


/*Solution*/
void solve(){
    cin >> s;
    cin >> q;
    int n = s.size();
    s = "x"+s;
    ans = s;
    for (int i=1; i<=q; i++){
        int x; cin >> x;
        if (x>n/2) x = n-x+1;
        state[x]++;
    }
    for (int i=1; i<=n/2; i++){
        state[i]+=state[i-1];
        if (state[i]%2==1){
            swap(ans[i],ans[n-i+1]);
        }
    }
    for (int i=1; i<=n; i++){
        cout << ans[i];
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
