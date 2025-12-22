#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e16;

int test;
int n,m,k;
vector<int> v;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test;

    while (test--){
        v.clear();
        cin >> n >> m >> k;
        int gap1 = 0;
        int gap2 = 0;
        int l,r,mid,x;
        int prev;
        cin >> prev;
        for (int i=1; i<n; i++){
            cin >> x;
            int delta = x - prev;
            if (delta > gap1){
                gap2 = gap1;
                gap1 = delta;
                l = prev;
                r = x;
                mid = (prev+x)/2;
            }
            else if (delta > gap2){
                gap2 = delta;
            }
            prev = x;
        }
        for (int i=1; i<=m; i++){
            cin >> x;
            v.push_back(x);
        }
        v.push_back(-INF);
        v.push_back(INF);
        v.push_back(INF);
        sort(v.begin(),v.end());
        int res = gap1;
        for (int i=1; i<=k; i++){
            cin >> x;
            int y = mid-x;
            int idx = (lower_bound(v.begin(),v.end(),y) - v.begin());
            for (int j = idx-1; j<=idx+1; j++){
                int bruh = max(abs(v[j]+x-l),abs(v[j]+x-r));
                res = max(min(res,bruh),gap2);
            }
        }
//        cout << res << " " << gap1 << " " << l << " " << mid << " " << r << " " << gap2 << endl;
        cout << res << endl;
    }

    return 0;
}
