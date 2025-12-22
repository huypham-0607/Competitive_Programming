#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e18;

int n,t;
int l[maxn],pre[maxn],a[maxn];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        int ans = -INF;
        cin >> n;
        cin >> a[1];
        pre[1] = a[1];
        for (int i=2; i<=n; i++){
            cin >> a[i];
            if ((abs(a[i-1])%2) == (abs(a[i])%2)){
                pre[i] = a[i];
            }
            else pre[i] = pre[i-1] + a[i];
            //cout << a[i] << " " << a[i-1] << " " << ((a[i-1]%2) == (a[i]%2)) << endl;
        }
        for (int i=1; i<=n; i++){
            if ((abs(a[i-1])%2) != (abs(a[i])%2)){
                l[i] = min(l[i-1],pre[i-1]);
            }
            else l[i] = 0;
            ans = max(ans, pre[i] - l[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
