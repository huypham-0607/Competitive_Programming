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
const int goc = 1e6;
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
int pre[(int)2e6+10];
string s;

/*Solution*/
void solve(){
    cin >> n;
    cin >> s;
    pre[0+goc] = 1;
    int sum = 0;
    int res = 0;
    for (int i=0; i<n; i++){
        if (s[i] == 'a') ++sum;
        else --sum;
        res+=pre[sum+goc];
//        cout << sum << " " << pre[-sum+goc] << " " << res << endl;
        pre[sum+goc]++;
    }
    cout << res << endl;
//    for (int i=-8; i<=8; i++){
//        cout << pre[i+goc] << " ";
//    }
}

/*Driver Code*/
signed main(){
    freopen("DANCE.inp","r",stdin);
    freopen("DANCE.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
