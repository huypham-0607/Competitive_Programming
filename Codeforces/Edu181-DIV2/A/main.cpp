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
int n;
string s,ans1,ans2,ans3;

/*Solution*/
void solve(){
    cin >> s;
    ans1 = ans2 = ans3 = "";
    for (int i=0; i<(int)s.size(); i++){
        if (s[i] == 'T') ans1+="T";
        else if (s[i] == 'N') ans3+="N";
        else ans2+=s[i];
    }
    cout << ans1 << ans2 << ans3 << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
