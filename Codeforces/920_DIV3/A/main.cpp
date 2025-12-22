#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        int x,y,i,j,meow,woof;
        cin >> meow >> woof;
        x = meow;
        y = meow;
        i = woof;
        j = woof;
        for (int idx=2; idx<=4; idx++){
            cin >> meow >> woof;
            x = min(meow,x);
            y = max(meow,y);
            i = min(woof,i);
            j = max(woof,j);
        }
        cout << abs(x-y)*abs(i-j) << endl;
    }
    return 0;
}
