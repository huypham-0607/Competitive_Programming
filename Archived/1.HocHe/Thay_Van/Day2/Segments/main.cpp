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
int ans[N];
vector<pair<pii,int>> v;
map<int,int> mp;

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int l,r;
        cin >> l >> r;
        v.push_back({{l,-r},i});
    }
    sort(v.begin(),v.end(),greater<pair<pii,int>>());
    for (auto in:v){
        int l = in.fi.fi;
        int r = -in.fi.se;
        int idx = in.se;
//        cout << l << " " << r << " " << idx << endl;
        auto it = mp.upper_bound(r);
        while (it!=mp.begin()){
//            cout << it->fi << endl;
            auto it2 = prev(it);
            ans[it2->se] = idx;
            mp.erase(it2->fi);
            it = mp.upper_bound(r);
        }
        mp[r] = idx;
    }
    for (int i=1; i<=n; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
    freopen("SEGMENTS.inp","r",stdin);
    freopen("SEGMENTS.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
