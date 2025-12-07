#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5 + 10;
const ll inf = LLONG_MAX;

class ST{
public:
    vector<ll> t;
    ST(int n){
        t.resize(4 * n + 5,inf);
    }
    void update(int id,int l,int r,int i,ll k){
        if (i < l || i > r) return;
        if (l == r){
            t[id] = k;
            return;
        }
        int mid = (l + r) / 2;
        update(id * 2,l,mid,i,k);
        update(id * 2 + 1,mid + 1,r,i,k);
        t[id] = min(t[id * 2],t[id * 2 + 1]);
    }
    ll get(int id,int l,int r,int u,int v){
        if (l > r) return inf;
        if (l > v || r < u) return inf;
        if (l >= u && r <= v) return t[id];
        int mid = (l + r) / 2;
        return min(get(id * 2,l,mid,u,v),
                   get(id * 2 + 1,mid + 1,r,u,v));
    }
};

ll sum[maxn];
ll dp[maxn];
ll a,b,m;
int n;

int main(){
    freopen("candy.INP","r",stdin);
    freopen("candy.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++){
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    dp[0] = 0;
    ST sa(n + 1),sb(n + 1);
    sa.update(1,1,n + 1,1,0);
    sb.update(1,1,n + 1,1,0);
    for (int i = 1; i <= n; i++){
        int pos = upper_bound(sum,sum + 1 + n,sum[i] - m) - sum;
        dp[i] = min(sa.get(1,1,n + 1,1,pos) + a * (sum[i] - m),
                    sb.get(1,1,n + 1,pos + 1,i) + b * (m - sum[i]));
        sa.update(1,1,n + 1,i + 1,dp[i] - a * sum[i]);
        sb.update(1,1,n + 1,i + 1,dp[i] + b * sum[i]);
    }
    cout << dp[n];
    return 0;
}
