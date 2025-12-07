#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e15;

int n,test,k,x,t;
vector<int> v;
int ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        v.clear();
        cin >> n >> k >> x;
        //v.push_back(0);
        ans = -INF;
        t = 0;
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            v.push_back(x);
            t+=x;
        }
        int l = v.size();
        sort(v.begin(),v.end());
//        for (auto i:v) cout << i << " ";
//        cout << endl;
        for (int i=1; i<=x; i++){
            t-=v[l-i]*2;
        }
        for (int i=1; i<=k; i++){
            ans = max(ans,t);
            t+=v[l-i];
            if (i+x <= l){
                t-=v[l-x-i]*2;
            }
        }
        ans = max(ans,t);
        cout << ans << " ";
    }
    return 0;
}
