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
set<int> st;
vector<int> v;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        v.clear();
        st.clear();
        cin >> n;
        int mx = -INF;
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            v.push_back(x);
            mx = max(mx,x);
            st.insert(x);
        }
        if (n == 1){
            cout << 1 << "\n";
            continue;
        }
        int x = abs(v[0]-mx);
        if (x == 0) x = abs(v[1]-mx);
        for (int i=1; i<n; i++){
            x = __gcd(x,abs(v[i]-mx));
        }
        int meow = mx;
        while (st.find(meow) != st.end()){
            meow-=x;
//            cout << meow << " ";
        }
        v.push_back(meow);
        int res = 0;
        for (int i=0; i<=n; i++){
            res+=((mx - v[i])/x);
        }
        cout << res << endl;
    }

    return 0;
}
