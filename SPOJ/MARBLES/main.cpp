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
int n;

ll CalcComb(int n, int k){
    if (k>n-k) k = n-k;
    long long res = 1;
    for (int i=0; i<k; i++){
        res = res*(n-i)/(i+1);
    }
    return res;
}

/*Solution*/
void solve(){
    int n,k; cin >> n >> k;
    cout << (long long)CalcComb(n-1,k-1) << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
