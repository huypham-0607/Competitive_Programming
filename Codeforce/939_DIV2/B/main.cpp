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
int n;
int cnt[N];

/*Solution*/
void solve(){
    cin >> n;
    int ans = 0;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        cnt[x]++;
        if (cnt[x] == 2){
            ++ans;
        }
    }
    cout << ans << endl;
    for (int i=1; i<=n; i++){
        cnt[i] = 0;
    }
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
