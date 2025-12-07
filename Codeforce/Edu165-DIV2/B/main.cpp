/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
string s;

/*Solution*/
void solve(){
    cin >> s;
    int cur = 0;
    int t = 0;
    n = (int)s.size();
    for (int i=0; i<n; i++){
        if (s[i] == '1'){
            ++cur;
        }
        else{
            if (cur!=0) t+=cur+1;
        }
    }
    cout << t << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
