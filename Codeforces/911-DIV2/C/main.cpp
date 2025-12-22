#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 3e5+10;
const int INF = 2e9;

int n,t;
vector<pii> a[maxn];
int dir[maxn];

int dfs(int u, int p, int d, int cnt){
    int c = cnt;
    int res = INF;
    if (dir[p] != d) ++c;
    if (int(a[u].size()) == 0) return c;
    for (auto in:a[u]){
        int v = in.fi;
        int drc = in.se;
        res = min(res,dfs(v,u,drc,c));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        a[0].push_back({1,1});
        dir[0] = 1;
        for (int i=1; i<=n; i++){
            a[i].clear();
            char c;
            cin >> c;
            if (c == 'L'){
                dir[i] = 1;
            }
            else if (c == 'R'){
                dir[i] = 2;
            }
            else dir[i] = 0;
        }
        for (int i=1; i<=n; i++){
            for (int idx = 1; idx <=2; idx++){
                int u;
                cin >> u;
                if (u){
                    a[i].push_back({u,idx});
                }
            }
        }
        int meow = dfs(1,0,1,0);
        cout << meow << endl;
    }
    return 0;
}
