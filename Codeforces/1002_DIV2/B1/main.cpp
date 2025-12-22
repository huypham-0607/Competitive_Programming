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
int a[N];

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    int cnt = 1;
    if (n==k){
        for (int i=1; i<=k; i++){
            int idx = 2*i;
            if (a[idx] == i) ++cnt;
            else break;
        }
    }
    else{
        cnt = 2;
        int delta = n-k;
        for (int i=2; i<=2+delta; i++){
            if (a[i]!=1){
                cnt = 1;
                break;
            }
        }
    }
    cout << cnt << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
