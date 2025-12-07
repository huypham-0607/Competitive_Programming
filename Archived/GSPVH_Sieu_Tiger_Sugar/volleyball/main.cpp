#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int main(){
    freopen("volleyball.INP","r",stdin);
    freopen("volleyball.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,k,x,y;
    cin >> t;
    while (t--){
        cin >> k >> x >> y;
        if (x<y) swap(x,y);
        if (x>=k-1 && y>=k-1){
            k=y+2;
        }
        if (x>=k) cout << 0 <<  " ";
        else cout << k-x << " ";
    }
    return 0;
}
