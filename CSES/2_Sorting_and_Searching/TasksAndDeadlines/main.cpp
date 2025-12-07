#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n;
vector<ii> v;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    int t=0;
    int ans = 0;
    for (auto in:v){
        t+=in.fi;
        ans += in.se - t;
    }
    cout << ans;
    return 0;
}
