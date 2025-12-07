#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,x,y;
    cin >> t;
    while (t--){
        cin >> x >> y;
        if (y>x/2){
            if (x%2==0){
                if (x==y) cout << 1;
                else cout << (y-x/2)*2+1;
            }
            else cout << (y-x/2)*2-1;
        }
        else cout << y*2;
        cout << "\n";
    }
    return 0;
}
