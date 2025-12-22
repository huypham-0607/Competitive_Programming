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
string s;
/*Solution*/
void solve(){
    cin >> n;
    cin >> s;
    s+="1";
    bool isone = 1;
    int cnt0 = 0;
    int cnt1 = 0;
    for (int i=0; i<=n; i++){
        if (i!=n && s[i] == '1') ++cnt1;
        if (isone){
            if (s[i] == '0'){
                ++cnt0;
                isone = !isone;
            }
        }
        else{
            if (s[i] == '1'){
                isone = !isone;
            }
        }
    }
    if (cnt1 > cnt0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
