#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;

int calc1(int x, int y){
    if (x==0) return 0;
    if (x<y) return y;
    else return 0;
}

int calc2(int x, int y){
    if (x==0) return 0;
    return x+y;

}

const int maxn = 9010;
const ll inf = 1e17;

ll dp[maxn][maxn];
ll a[maxn];
pair<ll,int> save[maxn];
ll pre[maxn];
vector<ll> val[maxn];
int n;

int main(){
    //freopen("towers.INP","r",stdin);
    //freopen("towers.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    pre[0] = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        pre[i] = pre[i-1]+a[i];
    }
    for (int i=1; i<=n; i++){
        dp[i][0] = inf;
    }
    save[0] = 0;
    for (int i=1; i<=n; i++){
        save[i] = 1;
        for (int j=1; j<=i; j++){
            int x = save[i];
            if (save[i]){
                dp[i][j] =
            }
        }
    }
    for (int i=0; i<n; i++){
        if (dp[n][i]){
            cout << i;
            break;
        }
    }
    cout << "\n";
    for (int i=1; i<=n; i++){
        for (int j=0; j<i; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
