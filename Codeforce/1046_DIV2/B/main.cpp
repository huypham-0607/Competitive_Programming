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
int n,k;
string s;

/*Solution*/
void solve(){
    cin >> n >> k;
    cin >> s;
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (s[i]=='1') ++cnt;
        if (i-k>=0 && s[i-k]=='1') --cnt;
        if (cnt == k){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    int l =1, r=n;
    for (int i=0; i<n; i++){
        if (s[i] == '1'){
            cout << l << " ";
            ++l;
        }
        else{
            cout << r << " ";
            --r;
        }
    }
    cout << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
