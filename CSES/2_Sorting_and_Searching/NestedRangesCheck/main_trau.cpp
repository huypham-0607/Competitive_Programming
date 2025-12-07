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
int n;
int l[N],r[N],ans1[N],ans2[N];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> l[i] >> r[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i==j) continue;
            if (l[i]<=l[j] && r[j]<=r[i]){
                ans1[i] = 1;
            }
            if (l[j]<=l[i] && r[i]<=r[j]){
                ans2[i] = 1;
            }
        }
    }
    for (int i=1; i<=n; i++){
        cout << ans1[i] << " ";
    }
    cout << endl;
    for (int i=1; i<=n; i++){
        cout << ans2[i] << " ";
    }
}

/*Driver Code*/
int main(){
    freopen("main.inp","r",stdin);
    freopen("main.ans","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
