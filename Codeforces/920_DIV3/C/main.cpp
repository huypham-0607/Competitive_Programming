#include <bits/stdc++.h>
#define endl "\n"
#define int unsigned long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,test;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        int f,x,y;
        cin >> n >> f >> x >> y;
        int t = 0;
        int prev = 0,cur;
        for (int i=1; i<=n; i++){
            cin >> cur;
            t+=min((cur-prev)*x,y);
            prev = cur;
        }
//        cout << t << " ";
        if (t>=f) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
