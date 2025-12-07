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
const int N = 1e6+10;
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
set<int> sta,stb;
int a[N],b[N];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }
    int res = 0;
    for (int i=1; i<=n; i++){
        if (stb.find(a[i])==stb.end()) sta.insert(a[i]);
        else stb.erase(a[i]);
        if (sta.find(b[i])==sta.end()) stb.insert(b[i]);
        else sta.erase(b[i]);
        if (sta.empty() && stb.empty()) ++res;
    }
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
