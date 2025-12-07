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
const int LG = 20;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
int F1[N*2],F2[N*2];
int a[N*2];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        F1[a[i]]++;
        F2[((1<<LG)-1)^a[i]]++;
    }
    for (int i=0; i<LG; i++){
        for (int mask=0; mask<(1<<LG); mask++){
            if ((mask>>i)&1){
                F1[mask]+=F1[mask^(1<<i)];
                F2[mask]+=F2[mask^(1<<i)];
            }
        }
    }
    for (int i=1; i<=n; i++){
        cout << F1[a[i]] << " " << F2[((1<<LG)-1)^a[i]] << " " << n-F1[((1<<LG)-1)^a[i]] << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
