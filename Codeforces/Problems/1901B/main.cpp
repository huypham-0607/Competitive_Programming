#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,t;
bool vis[maxn];
vector<pii> v;

signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        v.clear();
        memset(vis,true,n+5);
        vis[0] = 0;
        vis[n+1] = 0;
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            v.push_back({x,i});
        }
        sort(v.begin(),v.end());
//        for (auto in:v){
//            cout << in.fi << " " << in.se << endl;
//        }
        int gap = 1;
        int cnt = 0;
        int i = 0;
        int ans = 0;
        v.push_back({v[n-1].fi,0});
        while (i!=n){
            int prev = cnt;
            while (i<n && v[i].fi <= cnt){
                vis[v[i].se] = false;
                int c = 1;
                if (vis[v[i].se-1] == false) --c;
                if (vis[v[i].se+1] == false) --c;
                gap+=c;
                ++i;
            }
//            for (int j=1; j<=n; j++){
//                cout << vis[j] << " ";
//            }
//            cout << endl;
//            cout << cnt << " " << i << " " << gap << "\n";
            cnt = v[i].fi;
            ans+=gap*(cnt-prev);
        }
        cout << ans-1 << endl;
    }
    return 0;
}
