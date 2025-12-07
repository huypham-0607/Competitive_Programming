#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e18+100;

int n,t,k;
vector<int> v;
int a[maxn];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        v.clear();
        cin >> n >> k;
        int mn = INF;
        for (int i=1; i<=n; i++){
            cin >> a[i];
            mn = min(mn,a[i]);
        }

        if (k>=3) cout << 0 << endl;
        else{
        for (int i=1; i<=n; i++){
            for (int j=i+1; j<=n; j++){
                v.push_back(abs(a[i]-a[j]));
            }
        }
        sort(v.begin(),v.end());
        if (k==1) cout << min(mn,v[0]) << endl;
        else{
            int ans = INF;
            int sz = v.size();
            for (int i=1; i<=n; i++){
                int idx = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
                if (idx == 0){
                    ans = min(ans,abs(a[i] - v[idx]));
                }
                else if (idx == sz){
                    ans = min(ans,abs(a[i] - v[idx-1]));
                }
                else{
                    ans = min(ans,abs(a[i] - v[idx]));
                    ans = min(ans,abs(a[i] - v[idx-1]));
                }
            }
            cout << min({mn,v[0],ans}) << endl;
        }
        }
    }
    return 0;
}
