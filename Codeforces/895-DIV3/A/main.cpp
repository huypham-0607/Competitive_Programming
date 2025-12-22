#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,x,y,z;
    cin >> t;
    while (t--){
        cin >> x >> y >> z;
        if (x>y) swap(x,y);
        double diff = (y-x)/double(2);
        cout << ceil(diff/z) << "\n";
    }
    return 0;
}
