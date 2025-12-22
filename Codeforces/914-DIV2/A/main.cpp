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

int di[4] = {-1,-1,1,1},
    dj[4] = {-1,1,1,-1};
vector<pii> king,queen;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        king.clear();
        queen.clear();
        int a,b,x,y,u,v;
        cin >> a >> b;
        cin >> x >> y;
        cin >> u >> v;

        for (int i=0; i<4; i++){
            king.push_back({x+a*di[i],y+b*dj[i]});
        }
        for (int i=0; i<4; i++){
            queen.push_back({u+a*di[i],v+b*dj[i]});
        }
        if (a!=b){
            for (int i=0; i<4; i++){
                king.push_back({x+b*di[i],y+a*dj[i]});
            }
            for (int i=0; i<4; i++){
                queen.push_back({u+b*di[i],v+a*dj[i]});
            }
        }
        int cnt = 0;
        for (auto in:king){
            for (auto in2:queen){
                if (in == in2) ++cnt;
            }
        }
        cout << cnt << endl;

    }
    return 0;
}
