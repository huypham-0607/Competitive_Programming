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
int p[N];
vector<pair<double,int>> v;

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> p[i];
    }
    int x;
    for (int i=1; i<=n; i++){
        cin >> x;
        v.push_back({(1.0*x/p[i]),i});
    }
    sort(v.begin(),v.end(),greater<pair<double,int>>());
    cout << 1 << endl << v[0].se << endl;
}

/*Driver Code*/
signed main(){
    freopen("survey.inp","r",stdin);
    freopen("survey.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
