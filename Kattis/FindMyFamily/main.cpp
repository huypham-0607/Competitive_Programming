/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,k;

/*Solution*/
void solve(){
    cin >> k;
    vector<int> ans;
    for (int test=1; test<=k; test++){
        cin >> n;
        vector<int> v;
        for (int i=1; i<=n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        int mx = v[n-1];
        bool ver = false;
        for (int i=n-2; i>=0; i--){
            cout << i << endl;
            mx = max(mx,v[i]);
            if (v[i] == mx || v[i+1] == mx) continue;
            cout << v[i] << " " << v[i+1] << endl;
            if (v[i] > v[i+1]) ver = true;
        }
        if (ver) ans.push_back(test);
    }
    cout << ans.size() << endl;
    for (auto x:ans) cout << x << endl;
}

/*Driver Code*/
signed main(){
//    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
