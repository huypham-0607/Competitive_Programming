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
int y,n,k;
vector<int> ans;

/*Solution*/
void solve(){
    cin >> y >> k >> n;
    int x = k;
    while (x<=n){
        if (x-y>0){
            ans.push_back(x-y);
        }
        x+=k;
    }
    sort(all(ans));
    if (!ans.size()){
        cout << -1 << endl;
        return;
    }
    for (auto val:ans) cout << val << " ";
    cout << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
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
