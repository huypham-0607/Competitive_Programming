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
int n,q;

/*Solution*/
void solve(){
    cin >> n >> q;
    int mn = INF;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        mn = min(mn,x);
    }
    while (q--){
        int x;
        cin >> x;
        cout << min(x,mn-1) << " ";
    }
    cout << endl;
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
