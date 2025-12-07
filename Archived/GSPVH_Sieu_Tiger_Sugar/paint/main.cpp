#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("paint.inp","r",stdin);
    //freopen("paint.out","w",stdout);
    long long a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    if (a1 > a2) swap(a1,a2);
    if (b1 > b2) swap(b1,b2);
    if (a1 > b1){
        swap(a1,b1);
        swap(a2,b2);
    }
    long long res = 0;
    res = a2 - a1 + b2 - b1;
    if (a2 >= b2) res -= (b2 - b1);
    else if (a2 > b1) res -= (a2 - b1);
    cout << res;
    return 0;
}
