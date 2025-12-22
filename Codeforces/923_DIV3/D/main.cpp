#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n,q;
int l[maxn],r[maxn],grp[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        int prev = 0,x,y;
        int meow = 0;
        cin >> n;
        for (int i=1; i<=n; i++){
            cin >> x;
            if (x!=prev){
                r[meow] = i-1;
                ++meow;
                l[meow] = i;
            }
            grp[i] = meow;
            prev = x;
        }
        r[meow] = n;
        cin >> q;
        while (q--){
            cin >> x >> y;
            if (grp[x] == grp[y]) cout << -1 << " " << -1 << endl;
            else cout << r[grp[y]-1] << " " << l[grp[y]] << endl;
        }
//        cout << endl;
//        for (int i = 1; i<=n; i++){
//            cout << grp[i] << " " << l[i] << " " << r[i] << endl;
//        }
        cout << endl;
    }

    return 0;
}
