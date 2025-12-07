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
int n,sub=0;
string s;
vector<int> pi(N,0),ans(N,0);

/*Solution*/
void solve(){
    cin >> n;
    cin >> s;
    int t = (n+1)*n/2 -1;
    for (int i=1; i<n; i++){
        int j = pi[i-1];
        while (j>0 && s[i]!=s[j]){
            j = pi[j-1];
        }
        if (s[i] == s[j]){
            pi[i] = j+1;
            ++ans[pi[i]];
            sub+=pi[i];
        }
        else{
            pi[i] = 0;
            t-=(i+1);
        }
    }
//    for (int i=0; i<n; i++){
//        cout << pi[i] << " ";
//    }
//    cout << endl;
    for (int i=n-1; i>0; i--){
        int j = pi[i-1];
        if (j!=0){
            sub-=(i-j)*ans[i];
            ans[j] += ans[i];
            ans[i] = 0;
        }
    }
//    for (int i=0; i<n; i++){
//        cout << ans[i] << " ";
//    }
//    cout << endl;
    cout << t - sub;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
