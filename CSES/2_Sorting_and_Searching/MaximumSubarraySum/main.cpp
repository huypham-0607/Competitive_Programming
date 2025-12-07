#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n;
int pre[maxn];
int l[maxn];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int ans = -INF;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        pre[i] = pre[i-1] + x;
        l[i+1] = min(l[i],pre[i]);
        ans = max(ans,pre[i] - l[i]);
    }
    cout << ans;
    return 0;
}
