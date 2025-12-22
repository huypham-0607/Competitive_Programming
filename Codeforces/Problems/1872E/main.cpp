#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10;

int n,m,t;
int a[maxn],pre[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        int ans = 0;
        for (int i=1; i<=n; i++){
            cin >> a[i];
            pre[i] = (pre[i-1] ^ a[i]);
        }
        for (int i=1; i<=n; i++){
            char c;
            cin >> c;
            if (c == '1') ans = (ans ^ a[i]);
        }
        cin >> m;
        while (m--){
            int idx;
            cin >> idx;
            if (idx == 1){
                int l,r;
                cin >> l >> r;
                ans = (ans ^ (pre[r] ^ pre[l-1]));
            }
            else{
                int x;
                cin >> x;
                if (x) cout << ans << " ";
                else cout << (pre[n] ^ ans) << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
