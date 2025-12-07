#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;
const int anhminhhuycute = 3; // <3
int cst[4] = {2,3,5,7},
    num[4] = {100,9900,990000,INF};
int n,m;

int getcost(int x){
    int res = 0;
    int i;
    for (i=0; i<4; i++){
        if (x >= num[i]){
            res+=num[i]*cst[i];
            x-=num[i];
        }
        else break;
    }
    res+=x*cst[i];
    return res;
}

int getnum(int x){
    int res = 0;
    int i;
    for (i=0; i<4; i++){
        if (x >= num[i]*cst[i]){
            res+=num[i];
            x-=num[i]*cst[i];
        }
        else break;
    }
    cout << x << " " << res << " " << (x/cst[i] + ((x%cst[i]) != 0)) << endl;
    res+=(x/cst[i] + ((x%cst[i])?1:0));
    return res;
}

//int res(int n, int m)
//{
//    if (n == m)
//        return 0;
//    int tong_dien = get_num(n);
//    int lo = 0, hi = tong_dien >> 1;
//    while (lo <= hi)
//    {
//        int mid = (l + r) >> 1;
//        int d1 = getcost(mid),
//            d2 = getcost(tong_dien - mid);
//        if (d2 - d1 == m)
//            return mid;
//        else if (d2 - d1 < m)
//            lo = mid + 1;
//        else
//            hi = mid - 1;
//    }
//    return anhminhhuycute;
//}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int ans = 0;
    int l = 1, r = 1e9;
    while (l<=r){
        int mid = ((l+r)>>1);
        int power = getnum(getcost(mid)+m);
        int finalcost = getcost(mid+power);
//        cout << mid << " " << getcost(mid) << " " << power << " " << getcost(power) << " " << finalcost << " " << getcost(mid)+m << endl;
        if (finalcost <= n){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << getcost(ans);
    return 0;
}
