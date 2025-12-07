#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 5e3+50;
const int meow = 1e6;
const int INF = 2e9;

int n,q;
int pre[maxn][maxn],a[maxn];
int mp[(meow*2+50)];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            //cout << i << " " << j << endl;
            int x = -(a[i]+a[j]);
            if (abs(x)<=meow) pre[i][j]+=mp[x+meow+5];
            //cout << i << " " << j  << " " << a[j] << endl;
            mp[a[j]+meow+5]++;
        }
        for (int j=i+1; j<=n; j++){
            mp[a[j]+meow+5]--;
        }
    }
    for (int t=0; t<n; t++){
        for (int i=1; n-i>=t; i++){
            int j = i+t;
            //cout << i << " " << j << endl;
            pre[i][j] += (pre[i][j-1] + pre[i+1][j] - pre[i+1][j-1]);
        }
    }
    while (q--){
        int l,r;
        cin >> l >> r;
        cout << pre[l][r] << endl;
    }
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << pre[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
