#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define lim 1e9

using namespace std;

ll n,k;
int t;


bool anal(ll x, ll y, ll k){
    k--;
    while (k--){
        x-=1;
        if (x%y>0) x = x/y+1;
        else x = x/y;
    }
    x-=1;
    if (x<=0) return true;
    else return false;
}

ll bin_search(ll x, ll k){
    ll l = 2;
    ll r = lim;
    ll ans = lim+1;
    while (l<=r){
        ll mid = (l+r)/2;
        //cout << mid << " " << anal(x,mid,k) << "\n";
        if (anal(x,mid,k)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}

bool check(ll x, ll y){
    bool res = true;
    ll c = 0;
    while (x!=0){
        c++;
        x-=1;
        if (x%y!=0){
            res = false;
            break;
        }
        x = x/y;
    }
    if (res && c<3) res = false;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        bool v = false;
        for (ll i=3; i<=60; i++){
            ll res = bin_search(n,i);
            //cout << res << " " << check(n,res) << "\n";
            if (check(n,res)){
                v = true;
                break;
            }
        }
        if (v) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}

/*int main(){
    int c = 0;
    ll x = 0;
    while (x<=1000000000000000000){
        x*=3;
        x+=1;
        c++;
    }
    cout << c;
    return 0;
}*/
