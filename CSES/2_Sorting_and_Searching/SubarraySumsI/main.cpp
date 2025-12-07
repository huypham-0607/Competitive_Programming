#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,k;
int a[maxn];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    a[n+1] = INF;
    int l = 0;
    int r = 0;
    int t = 0;
    int ans = 0;
    while (r<=n){
        if (t == k) ++ans;
        if (t>k){
            ++l;
            t-=a[l];
        }
        else{
            ++r;
            t+=a[r];
        }
    }
    cout << ans;
    return 0;
}
