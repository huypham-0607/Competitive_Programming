#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n;
int a[maxn];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int mid = a[n/2+n%2];
    int t = 0;
    for (int i=1; i<=n; i++){
        t+=abs(mid-a[i]);
    }
    cout << t;
    return 0;
}
