#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e6+10;
const int INF = 2e9;

int test;
int n;
int a[maxn];

signed main(){
    freopen("XOASO.inp","r",stdin);
    freopen("XOASO.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long t=0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        if (i>1){
            t+=max(a[i],a[i-1]);
        }
    }
    cout << t;
    return 0;
}
