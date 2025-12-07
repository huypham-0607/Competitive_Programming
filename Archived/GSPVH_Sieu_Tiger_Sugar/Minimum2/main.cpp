#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 5e6+69;
const int inf = 1e9+10;

int a[maxn],pre[maxn];
int luulow,luui;

signed main(){
    //freopen("minimum.INP","r",stdin);
    //freopen("minimum.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x,y;
    cin >> n >> x >> y;
    luulow = -inf;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        if (a[i]>=x && a[i]<=y && a[i] > luulow){
            luulow = a[i];
            luui = i;
        }
        pre[i] = pre[i-1] + a[i];
    }
    int mn = inf;
    int ans = luulow;
    int l = 1;
    ii anspos = {0,0};
    int kadane = 0;
    for (int r=1; r<=n; r++){
        mn = min(mn,a[r]);
        kadane+=a[r];
        if (mn > y){
            continue;
        }
        if (kadane < luulow || mn < x){
            mn = inf;
            kadane = 0;
            l=r+1;
            continue;
        }
        if (kadane>ans){
            ans = kadane;
            anspos.fi = l;
            anspos.se = r;
        }
    }
    if (ans == -1){
        cout << luulow << "\n" << luui << " " << luui;
    }
    else cout << ans << "\n" << anspos.fi << " " << anspos.se;
    return 0;
}
