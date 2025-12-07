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
map<int,int> mp;

/*Solution*/
void solve(){
    mp.clear();
    string s;
    cin >> n;
    cin >> s;
    int rawr = 0;
    mp[0] = 1;
    int ans = 0;
    for (int i=0; i<n; i++){
        int idx = s[i]-'a';
        rawr = rawr^(1<<idx);
        ans+=mp[rawr];
        mp[rawr]++;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
//    freopen("TWINS.inp","r",stdin);
//    freopen("TWINS.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
