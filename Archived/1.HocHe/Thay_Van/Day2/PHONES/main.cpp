/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define psi pair<string,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e4+10;
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
int dp[N];
int cmp[5];
vector<psi> tmp[5] = {{},
                        {},
                        {{"aa",2}},
                        {{"aba",2},{"aab",2},{"abb",2},{"aaa",3}},
                        {{"abac",2},{"abcb",2},{"abab",3},{"aabb",3},{"abbb",3},{"abaa",3},{"aaba",3},{"aaab",3},{"abba",4},{"aaaa",5}}};

bool comp(string& s, string& temp){
    int a[5];
    for (int i=0; i<5; i++){
        a[i] = -1;
    }
    for (int i=0; i<(int)s.size(); i++){
        int idx = temp[i]-'a';
        if (a[idx] == -1) a[idx] = s[i]-'0';
        else if (s[i]-'0'!=a[idx]) return false;
    }
    return true;
}

/*Solution*/
void solve(){
    cin >> s;
    int n = s.size();
    s = "#"+s;
    string seg;
    for (int i=2; i<=n; i++){
        seg.insert(0,s.substr(i,1));
        for (int j=2; j<=4; j++){
            if (i-j>=0){
                dp[i] = max(dp[i],dp[i-j]);
                seg.insert(0,s.substr(i-j+1,1));
                for (auto in:tmp[j]){
                    if (comp(seg,in.fi)){
                        dp[i] = max(dp[i],dp[i-j]+in.se);
                    }
                }
            }
        }
        seg.clear();
    }
    cout << dp[n];
}

/*Driver Code*/
signed main(){
    freopen("PHONES.inp","r",stdin);
    freopen("PHONES.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
