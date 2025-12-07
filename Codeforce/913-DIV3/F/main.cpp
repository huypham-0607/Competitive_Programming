#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,t;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        v.clear();
        cin >> n;
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        v.push_back(v[0]);
        int ans = INF;
        int pos = 0;
        for (int i=1; i<=n; i++){
            if (v[i] < v[i-1]){
                if (!pos) pos = i;
                else{
                    pos = n+1;
                    break;
                }
            }
        }
        if (pos == 0 || pos == n) ans = min(ans,0);
        if (pos < n+1){
            ans = min(ans,n-pos);
            ans = min(ans,pos+2);
        }
        pos = 0;
        for (int i=1; i<=n; i++){
            if (v[i] > v[i-1]){
                if (!pos) pos = i;
                else{
                    pos = n+1;
                    break;
                }
            }
        }
        if (pos == 0 || pos == n) ans = min(ans,1);
        if (pos < n+1){
            ans = min(ans,n-pos+1);
            ans = min(ans,pos+1);
        }
        if (ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
