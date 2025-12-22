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

/*Solution*/
void solve(){
    cin >> n;
    stack<int> s;
    int res = 0;
    char c;
    for (int i=1; i<=n; i++){
        cin >> c;
        if (c=='_'){
            if (!s.empty()){
                res+=i-s.top();
                s.pop();
            }
            else s.push(i);
        }
        else if (c=='('){
            s.push(i);
        }
        else{
            res+=i-s.top();
            s.pop();
        }
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
