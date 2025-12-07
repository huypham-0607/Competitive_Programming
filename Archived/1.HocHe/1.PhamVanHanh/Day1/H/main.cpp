/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "discounts"

using namespace std;

/*Constants*/
const int N = 220797+10;
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
vector<int> res[N];
vector<pair<int,pii>> v;

/*Solution*/
void solve(){
    cin >> n >> n >> k;
    for (int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        v.push_back({y%2,{x,i}});
    }
    long double ans=0;
    sort(v.begin(),v.end(),greater<pair<int,pii>>());
    for (int i=0; i<k; i++){
        if (i==k-1){
            int mn = INF;
            for (int j=i; j<n; j++){
                mn = min(mn,v[j].se.fi);
                ans+=v[j].se.fi;
                res[i].push_back(v[j].se.se);
            }
            if (v[i].fi) ans-=0.5*mn;
        }
        else{
            if (v[i].fi) ans+=0.5*v[i].se.fi;
            else ans+=v[i].se.fi;
            res[i].push_back(v[i].se.se);
        }
    }
    cout << fixed << setprecision(1) << ans << endl;
    for (int i=0; i<k; i++){
        cout << res[i].size() << " ";
        for (auto v:res[i]){
            cout << v << " ";
        }
        cout << endl;
    }
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
