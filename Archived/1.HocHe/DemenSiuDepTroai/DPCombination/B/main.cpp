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
int n,m,k;

/*Solution*/
void solve(){
    cin >> n >> m >> k;
    int total=0, tk=0;
    for (int i=1; i<=m; i++){
        int x; cin >> x;
        if (i==k) tk = x;
        total+=x;
    }
    double res = 1;
    --n; --tk; --total;
    if (n>total){
        cout << -1 << endl;
        return;
    }
    if (!tk){
        cout << 0 << endl;
        return;
    }
    else if (n>total-tk){
        cout << 1 << endl;
        return;
    }
    for (int i=0; i<tk; i++){
        res*=(total-n-i);
        res/=(total-i);
    }
    cout << fixed << setprecision(6) << 1-res << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
