#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n;
int a[maxn];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }
        a[n+1] = 0;
        a[n+1] = 0;
        a[n+3] = 0;
        bool v=true;
        for (int i=1; i<=n+1; i++){
            if (a[i] < 0) v=false;
            if (a[i] > 0){
                a[i+2]-=a[i];
                a[i+1]-=a[i]*2;
                a[i]-=a[i];
            }
        }
        if (v) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
