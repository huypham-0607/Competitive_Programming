#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,x,t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> x;
        int ans = 0;
        int prev = 0;
        for  (int i=1; i<=n; i++){
            int y;
            cin >> y;
            if (i == n) ans = max(ans,(x - y)*2);
            ans = max(ans,y - prev);
            prev = y;
        }
        cout << ans << endl;
    }
    return 0;
}
