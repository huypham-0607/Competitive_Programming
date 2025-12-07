#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int INF = 2e9;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int mn = INF;
        int n;
        cin >> n;
        while (n--){
            int x,y;
            cin >> x >> y;
            mn = min(mn,x+y/2-((y+1)%2));
        }
        cout << mn << "\n";
    }
    return 0;
}
