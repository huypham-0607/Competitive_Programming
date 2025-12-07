#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e3+10;
const int INF = 1e9;

int test;
int n,m,x;
bool vis[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test;
    while (test--){
        cin >> n >> m >> x;

        for (int i=1; i<=n; i++) vis[0][i] = false;
        vis[0][x] = true;
        for (int idx = 1; idx<=m; idx++){
            for (int i=1; i<=n; i++){
                vis[idx][i] = false;
            }
            int d;
            char c;
            bool cw = false, ccw = false;
            cin >> d >> c;
            if (c == '0') cw = true;
            else if (c == '1') ccw = true;
            else {
                cw = true;
                ccw = true;
            }
            for (int i=1; i<=n; i++){
                if (vis[idx-1][i] && cw){
                    int j = (i-1+d)%n+1;
                    vis[idx][j] = true;
                }
                if (vis[idx-1][i] && ccw){
                    int j = i-1-d;
                    if (j<0) j+=n;
                    j+=1;
                    vis[idx][j] = true;
                }
            }
        }
        int res = 0;
        for (int i=1; i<=n; i++){
            if (vis[m][i]) res++;
        }
        cout << res << endl;
        for (int i=1; i<=n; i++){
            if (vis[m][i]) cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
