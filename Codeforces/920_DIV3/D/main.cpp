#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,m,test;
vector<int> a,b;

pii check(int x, int y, int l, int r){
    pii meow,woof;
    if (abs(x-l) > abs(x-r)){
        meow = {x,l};
    }
    else meow = {x,r};
    if (abs(y-l) > abs(y-r)){
        woof = {y,l};
    }
    else woof = {y,r};
    if (abs(woof.fi-woof.se) > abs(meow.fi - meow.se)){
        return woof;
    }
    else return meow;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        a.clear();
        b.clear();
        cin >> n >> m;
        int t=0;
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i=1; i<=m; i++){
            int x;
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int l = 0, r = m-1;
        int x = 0, y = n-1;
        while (x<=y){
            pii meow = check(a[x],a[y],b[l],b[r]);
            t+=abs(meow.fi-meow.se);
            if (meow.fi == a[x]) ++x;
            else --y;
            if (meow.se == b[l]) ++l;
            else --r;
        }
        cout << t << endl;
    }
    return 0;
}
