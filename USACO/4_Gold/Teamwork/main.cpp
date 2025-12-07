#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e4+10;
const int maxk = 1e3+10;
const int INF = 2e9;

int n,k,a[maxn];
int dp[maxn][maxk];
int best[maxn];

int main(){
    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    best[0] = 0;
    for (int i=1; i<=n; i++){
        int mx = a[i];
        int cnt = 0;
        for (int j = i-1; j>=max(0,i-k); j--){
            ++cnt;
            best[i] = max(mx*cnt + best[j],best[i]);
            mx = max(mx,a[j]);
        }
    }
    cout << best[n];
    return 0;
}
