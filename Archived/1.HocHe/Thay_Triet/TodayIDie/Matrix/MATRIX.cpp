/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e3+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,m;
int a[N][N];
int pre[N][N];

bool Check1(){
    if (n*m<=5000) return true;
    return false;
}

/*Solution*/
void Solve1(){
    int cnt=0;
    for (int i1=1; i1<=n; i1++){
        for (int i2=i1; i2<=n; i2++){
            for (int j1=1; j1<=m; j1++){
                for (int j2=j1; j2<=m; j2++){
                    if ((pre[i2][j2]^pre[i1-1][j2]^pre[i2][j1-1]^pre[i1-1][j1-1])==0) ++cnt;
                }
            }
        }
    }
    cout << cnt << endl;
}

int dp[N][N][2];
void Solve2(){
    int ans = 0;
    for (int i1=1; i1<=n; i1++){
        for (int i2=i1; i2<=n; i2++){
            dp[i1][i2][0] = 1;
            for (int j=1; j<=m; j++){
                int cur = pre[i2][j]^pre[i1-1][j];
                ans+=dp[i1][i2][cur];
                dp[i1][i2][cur]++;
            }
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("MATRIX.inp","r",stdin);
    freopen("MATRIX.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            if (a[i][j]%2==1) a[i][j] = 1;
            else a[i][j] = 0;
            pre[i][j] = (a[i][j]^pre[i-1][j]^pre[i][j-1]^pre[i-1][j-1]);
        }
    }

//    if (Check1()) return Solve1(),0;
    Solve2();
    return 0;
}
