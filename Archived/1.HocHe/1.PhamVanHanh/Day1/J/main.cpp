/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define fi first
#define se second

using namespace std;

#define NAME "teleport"

/*Global Variables*/
int n;
vector<ll> v[2];

/*Solution*/
void solve(){
    cin >> n;
    ll cur[2];
    cur[0] = cur[1] = 0;
    ll rawr;
    for (int i=1; i<=n; i++){
        cin >> rawr;
        if (rawr<0){
            rawr = abs(rawr);
            v[0].push_back((rawr<<1)^1);
            v[0].push_back(((rawr*2)<<1));
            cur[0]+=rawr;
            cur[1]+=rawr;
        }
        else{
            v[1].push_back((rawr<<1)^1);
            v[1].push_back(((rawr*2)<<1));
            cur[0]+=rawr;
            cur[1]+=rawr;
        }
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    ll ans = (ll) 1e18+3;
    ll lcnt;
    ll r;
    ll ver = 0;
    unsigned int prev;
    for (int idx=0; idx<2; idx++){
        prev = 0;
        lcnt = 0;
        n = (int)v[idx].size();
        r = n/2;
        for (int i=0; i<n; i++){
            ver = (v[idx][i]&1);
            v[idx][i]>>=1;
            cur[idx]+=lcnt*(v[idx][i]-prev);
            cur[idx]-=r*(v[idx][i]-prev);

            if (ver){
                ++lcnt;
                --r;
            }
            else{
                --lcnt;
            }

//            cout << cur[idx] << " " << lcnt << " " << r << endl;

            ans = min(ans,cur[idx]);
            prev = v[idx][i];
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
