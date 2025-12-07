#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
#define lim 1e17
using namespace std;

pair<ii,ll> a[200100];
ll n;
vector<ii> dp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (ll i=0; i<n; i++){
        ll s,e,t;
        cin >> s >> e >> t;
        a[i] = {{e,s},t};
    }
    sort(a,a+n);
    /*for (int i=0; i<n; i++){
        cout << a[i].fi.fi << " " << a[i].fi.se;
    }*/
    dp.push_back({0,0});
    ll c=0;
    for (ll i=0; i<n; i++){
        ll s = a[i].fi.se,
            e = a[i].fi.fi,
            t = a[i].se;
        ii temp = {s,0};
        ll pos = lower_bound(dp.begin(),dp.end(),temp)-dp.begin()-1;
        t+=dp[pos].se;
        if (e == dp[c].fi){
            dp[c].se = max(dp[c].se,t);
        }
        else if (t>dp[c].se){
            dp.push_back({e,t});
            c++;
        }
        /*for (int j=0; j<=c; j++){
            cout << "(" << dp[j].fi << "," << dp[j].se << ") ";
        }
        cout << endl;*/
    }
    cout << dp[c].se;
    return 0;
}
