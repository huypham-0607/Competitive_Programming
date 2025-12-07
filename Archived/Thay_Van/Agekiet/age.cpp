#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define vi vector<int>

using namespace std;
const int maxn = 255;

int n,m;
vector<int> a[maxn];

void dfs(int u,int cur,vector<vector<bool>>& v){
    //cout << cur << "\n";
    if (cur > 20 * n) return;
    if (v[cur][u] == 1) return;
    v[cur][u] = 1;
    for (int i : a[u]){
        dfs(i,cur + 1,v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("AGE.INP","r",stdin);
    freopen("AGE.OUT","w",stdout);
    cin >> n >> m;
    int p1,p2;
    cin >> p1 >> p2;
    for (int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    vector<vector<bool>> v1(21 * n + 5,vector<bool> (n + 5,0));
    vector<vector<bool>> v2(21 * n + 5,vector<bool> (n + 5,0));
    dfs(p1,0,v1);
    dfs(p2,0,v2);
    int res = -1;
    bool f = 0;
    for (int i = 0; i <= 20 * n; i++){
        if (f) break;
        for (int j = 1; j <= n; j++){
            if (v1[i][j] && v2[i][j]){
                res = i;
                f = 1;
                break;
            }
        }
    }
    cout << res;
    return 0;
}
