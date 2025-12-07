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
const int N = 1e6+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;
const int LG = 22;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
int a[N];
int F[(1<<LG)+10];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        F[a[i]] = i;
    }
    for (int i=0; i<LG; i++){
        for (int mask=0; mask<(1<<LG); mask++){
            if ((mask>>i)&1) F[mask] = max(F[mask],F[mask^(1<<i)]);
        }
    }
    for (int i=1; i<=n; i++){
        int pos = F[((1<<LG)-1)^a[i]];
        if (pos == 0) cout << -1 << " ";
        else cout << a[pos] << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
