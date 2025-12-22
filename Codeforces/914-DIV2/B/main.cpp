#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10;
const int INF = 2e9;

int n,t;
int ans[maxn];
int pre[maxn];
vector<pii> v;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        v.clear();
        cin >> n;
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            v.push_back({x,i});
        }
        sort(v.begin(),v.end());
        pre[0] = v[0].fi;
        for (int i=1; i<n; i++){
            pre[i] = pre[i-1] + v[i].fi;
//            cout << i << " ";
        }
//        cout << endl;
        ans[v[n-1].se] = n-1;
        for (int i=n-2; i>=0; i--){
            if (pre[i]>=v[i+1].fi){
                ans[v[i].se] = ans[v[i+1].se];
            }
            else ans[v[i].se] = i;
        }
        for (int i=1; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
