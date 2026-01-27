#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    vector<ll> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];

    ll ans = pre[n - 1];

    auto query = [&](int l, int r) -> ll{
        ll res = pre[r];
        if (l > 0)
            res -= pre[l - 1];
        return res;
    };

    for (int i = 0; i < n; i++){
        int l = 1, r = min(i, n - i - 1) + 1;
        while (l < r){
            int mid = (l + r) / 2;
            
            int left = min(1LL * (mid - 1) * k, 1LL * i);
            int right = min(1LL * mid * k - 1, 1LL * i);
            ll cost = query(left, right) + a[i + mid];
            if (cost <= 1LL * a[i] * (right - left + 1 + 1))
                l = mid + 1;
            else
                r = mid;
        }
        l--;
        if (l == 0)
            continue;

        int right = min(1LL * l * k - 1, 1LL * i);
        ll len = right + 1 + l;
        ll cost = len * a[i] - (query(0, right) + query(i + 1, i + l));
        ans = max(ans, pre[n - 1] + cost);
    }

    cout << ans << "\n";
}

int main(){
    freopen("2154E.inp","r",stdin);
    freopen("2154E.ans","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
}