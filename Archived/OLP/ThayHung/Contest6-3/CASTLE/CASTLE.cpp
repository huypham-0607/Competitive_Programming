#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e3+10;
const int INF = 1e9;

int test;
int n,m;
deque<pii> dq;

int a[maxn][maxn],h[maxn][maxn];

signed main(){
    freopen("CASTLE.INP","r",stdin);
    freopen("CASTLE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int res = 0;

    for (int i=1; i<=n; i++){
        int t = 0;
        dq.clear();
        for (int j=1; j<=m; j++){
//            cout << "{" << i << "," << j << "} " << endl;
            cin >> a[i][j];
            h[i][j] = 1;
            if (a[i][j] == a[i-1][j]){
                h[i][j]+=h[i-1][j];
            }
            if (a[i][j]!=a[i][j-1]){
                dq.clear();
                t = 0;
            }
            int prev = j;
            while (!dq.empty() && dq.back().fi >= h[i][j]){
//                cout << prev << " " << dq.back().se << " " << dq.back().fi << endl;
                t-=(prev-dq.back().se)*dq.back().fi;
                t+=(prev-dq.back().se)*h[i][j];
                prev = dq.back().se;
                dq.pop_back();
            }
            dq.push_back({h[i][j],prev});
            t+=h[i][j];
            res+=t;
//            cout << h[i][j] << " " << t << endl;
        }
//        cout << endl;
    }
    cout << res;
    return 0;
}
