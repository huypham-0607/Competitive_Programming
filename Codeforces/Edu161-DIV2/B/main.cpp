#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 3e5+10;
const int INF = 2e9;

int n,test;
int a[maxn];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        for (int i=0; i<=n; i++){
            a[i] = 0;
        }
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            ++a[x];
        }
        int ans = 0;
        int cnt = 0;
        for (int i=0; i<=n; i++){
            if (a[i] == 0) continue;
            if (a[i] == 2) ans+=cnt;
            else if (a[i] >= 3){
                ans+=(a[i]*(a[i]-1)/2)*cnt+(a[i]*(a[i]-1)*(a[i]-2)/6);
            }
            cnt+=a[i];
        }
        cout << ans << endl;
    }
    return 0;
}
