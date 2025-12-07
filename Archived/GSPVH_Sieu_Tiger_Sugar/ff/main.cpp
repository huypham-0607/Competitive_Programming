#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int main(){
    //freopen("ff.INP","r",stdin);
    //freopen("ff.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    if (k>=n) cout << 2;
    else cout << (n*2/k+(n*2%k!=0));
    return 0;
}
