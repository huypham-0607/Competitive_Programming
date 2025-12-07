#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e9+7;

int test;
int n;
int vis[maxn];

void BFS(){
    deque<pii> dq;
    dq.push_back({1,1});
    vis[1] = 1;
    while (!dq.empty()){
        int u = dq.front().fi;
        int w = dq.front().se;
        dq.pop_front();

        if (vis[(u*10)%n] > w){
//            cout << u*10%n << " " << u << " " << w << endl;
            vis[(u*10)%n] = w;
            dq.push_front({(u*10)%n,w});
        }
        if (vis[(u+1)%n] > w+1){
//            cout << (u+1)%n << " " << u << " " << w << endl;
            vis[(u+1)%n] = w+1;
            dq.push_back({(u+1)%n,w+1});
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<=n; i++){
        vis[i] = INF;
    }
    BFS();
    cout << vis[0];
//
//    cout << endl;
//    for (int i=0; i<n; i++){
//        cout << vis[i] << " ";
//    }

    return 0;
}
