#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const ll maxn = 100000;

bitset<10> ok;

bool check(ll x){
    ok.reset();
    int t;
    while (x>0){
        t = x%10;
        if (ok[t]) return 0;
        ok[t] = 1;
        x/=10;
    }
    return 1;
}

int main(){
    //freopen("squares.INP","r",stdin);
    //freopen("squares.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k;
    cin >> k;
    ll res = -1;
    ll t=0;
    for (ll i=1; i<maxn; i++){
        if (check(i*i)) ++t;
        if (t==k){
            res = i*i;
            break;
        }
    }
    cout << res;
    return 0;
}
