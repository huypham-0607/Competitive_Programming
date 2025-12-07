#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e18+1000000;

int n,a,b;
int pre[maxn];
int l[maxn];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    deque<pii> dq;
    dq.push_front({0,0});
    int ans = -INF;
    for (int i=1; i<=n; i++){
        while (!dq.empty() && dq.front().se < i-(b-a)){
            dq.pop_front();
        }
        int x;
        cin >> x;
        pre[i] = pre[i-1]+x;
        while (!dq.empty() && dq.back().fi >= pre[i]){
            dq.pop_back();
        }
        dq.push_back({pre[i],i});
        l[i+a] = dq.front().fi;
        if (i>=a) ans = max(ans,pre[i] - l[i]);
    }
    cout << ans;
    return 0;
}
