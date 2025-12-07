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
int last[26];
string s;

/*Solution*/
void solve(){
    cin >> s;
    n = s.size();
    int cnt = 0;
    int lst = 0;
    for (int i=1; i<=n; i++){
        int idx = s[i-1]-'a';
        if (last[idx]>=lst) lst = last[idx];
        last[idx] = i;
        cnt+=i-lst;
    }
    cout << cnt << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
