#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,test,m,x,y,i,j;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n >> m >> x >> y >> i >> j;
        if (x>=i){
            cout << "Draw" << endl;
        }
        else{
            int moves = i-x;
            int dist = abs(y-j);
            if (moves%2 == 1){
                if (j > y){
                    dist = min(dist+moves/2,dist+m-j);
                }
                else{
                    dist = min(dist+moves/2,dist+j-1);
                }
                if (dist <= moves/2+1){
                    cout << "Alice" << endl;
                }
                else cout << "Draw" << endl;
            }
            else{
                if (y > j){
                    dist = min(dist+moves/2,dist+m-y);
                }
                else{
                    dist = min(dist+moves/2,dist+y-1);
                }
                if (dist <= moves/2){
                    cout << "Bob" << endl;
                }
                else cout << "Draw" << endl;
            }
//            cout << dist << " " << moves << endl;
        }
    }
    return 0;
}
