#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        int a,b,c;
        cin >> a >> b >> c;
        cout << ((c+b)%2 == 0) << " " << ((a+c)%2 == 0) << " " << ((a+b)%2 == 0) << endl;
    }
    return 0;
}
