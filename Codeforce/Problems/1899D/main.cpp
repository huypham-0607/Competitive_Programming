#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n;
vector<int> v;
int t;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        v.clear();
        cin >> n;
        v.push_back(0);
        v.push_back(INF);
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int c=0,c1=0,c2=0;
        int ans = 0;
        for (int i=1; i<=n+1; i++){
            if (v[i] != v[i-1]){
                ans+=c*(c-1)/2;
                c = 1;
            }
            else ++c;
            if (v[i] == 1){
                c1++;
            }
            if (v[i] == 2){
                c2++;
            }
        }
        ans+=c1*c2;
        cout << ans << endl;
    }
    return 0;
}
