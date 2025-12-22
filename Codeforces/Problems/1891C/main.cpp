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
vector<int> v;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        int total = 0;
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            total+=x;
            v.push_back(-x);
        }
        sort(v.begin(),v.end());
        int ans = 0;
        int cur = 0;
        int i=0;
        while (cur < total/2){
            ++ans;
            cur-=v[i];
            ++i;
        }
        cout << ans + (total+1)/2 << endl;
        v.clear();
    }
    return 0;
}
