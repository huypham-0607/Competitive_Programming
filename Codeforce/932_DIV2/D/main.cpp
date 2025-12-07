#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n,c;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        int even=0,odd=0;
        cin >> n >> c;
        int res = c*(c+1)/2+c+1;
//        cout << res << endl;
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            if (x%2) ++odd;
            else ++even;
            res-=(c-x)+1;
            if (x%2){
                res-=(x/2)+1-odd;
            }
            else{
                res-=(x/2)+1-even;
            }
//            cout << x << " " << (c-x)/2+1 << " " << ((x%2)?(x/2)+1-odd:(x/2)+1-even) << endl;
        }
        cout << res << endl;
    }

    return 0;
}
