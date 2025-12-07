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
const int N = 24;
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
int F[(1<<N)];

/*Solution*/
void solve(){
    cin >> n;
    string s;
    for (int i=1; i<=n; i++){
        cin >> s;
        int rawr = 0;
        for (int i=0; i<(int)s.size(); i++){
            int idx = s[i]-'a';
            rawr = (rawr|(1<<idx));
        }
        F[rawr]+=1;
    }

    for (int i=0; i<N; i++){
        for (int mask=0; mask<(1<<N); mask++){
            if ((mask>>i)&1) F[mask]+=F[mask^(1<<i)];
        }
    }

    int ans = 0;
    for (int mask=0; mask<(1<<N); mask++){
        int res = n - F[((1<<N)-1)^mask];
        ans = ans^(res*res);
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
